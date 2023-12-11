#include <bits/stdc++.h>
using namespace std;

#define bug(x) cout << #x << " = " << x

template <class X, class Y>
bool chkmin(X &a, const Y &b){
    return a > b ? a = b, 1 : 0;
}

struct node{
    int x = 0, y = 0;

    bool is_empty(){
        return !x && !y;
    }

    bool is_valid(int n, int m){
        return x > 0 && y > 0 &&
        x <= n && y <= m;
    }

    node(){}

    node(int x, int y): x(x), y(y){}
};

const int N = 505;
const int inf = 0x3f3f3f3f;
char a[N][N];
int dp[10][10][N][N], n, m;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
node nxt[N][N][4];

node go(node u, int dir){
    if (!nxt[u.x][u.y][dir].is_empty())
        return nxt[u.x][u.y][dir];
    if (a[u.x][u.y] == 'A') dir--;
    if (a[u.x][u.y] == 'C') dir++;
    dir = (dir + 4) % 4;
    node v; v.x = u.x + dx[dir];
    v.y = u.y + dy[dir];
    if (!v.is_valid(n, m) ||
        a[v.x][v.y] == 'x')
        nxt[u.x][u.y][dir] = u;
    else nxt[u.x][u.y][dir] = go(v, dir);
    return nxt[u.x][u.y][dir];
}

int main(){
    freopen("arobot.inp", "r", stdin);
    freopen("arobot.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int lim; cin >> lim >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    queue <node> qs;
    deque <node> dq[2];
    memset(dp, 0x3f, sizeof dp);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (isdigit(a[i][j])){
                int nu = a[i][j] - '0';
                dp[nu][nu][i][j] = 0;
                qs.emplace(i, j);
                while (!qs.empty()){
                    node u = qs.front(); qs.pop();
                    for (int d = 0; d < 4; d++){
                        node v = go(u, d);
                        if (chkmin(dp[nu][nu][v.x][v.y]
                        , dp[nu][nu][u.x][u.y] + 1))
                            qs.push(v);
                    }
                }
            }
    for (int y = 2; y <= lim; y++)
        for (int x = y - 1; x > 0; x--){
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++){
                    for (int z = x; z < y; z++)
                        chkmin(dp[x][y][i][j],
                        dp[x][z][i][j] +
                        dp[z + 1][y][i][j]);
                    if (dp[x][y][i][j] != inf)
                        dq[0].emplace_back(i, j);
                }
            sort(dq[0].begin(), dq[0].end(),
            [&](node u, node v){
                return dp[x][y][u.x][u.y]
                < dp[x][y][v.x][v.y]; 
            });
            while (!dq[0].empty()){
                node u = dq[0][0];
                while (!dq[0].empty() &&
                dp[x][y][dq[0][0].x][dq[0][0].y]
                == dp[x][y][u.x][u.y]){
                    dq[1].push_back(dq[0][0]);
                    dq[0].pop_front();
                }
                while (!dq[1].empty()){
                    u = dq[1].front();
                    dq[1].pop_front();
                    for (int d = 0; d < 4; d++){
                        node v = go(u, d);
                        if (chkmin(dp[x][y][v.x][v.y]
                        , dp[x][y][u.x][u.y] + 1))
                            dq[0].push_front(v);
                    }
                }
            }
        }
    int res = inf;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            res = min(res, dp[1][lim][i][j]);
    if (res == inf) res = -1;
    cout << res << '\n';
}