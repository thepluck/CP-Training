#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define fi first
#define se second
using ii = pair <int, int>;

const int N = 505;
char a[N][N]; int dis[N][N];
int r[] = {-1, 0, 0, 1};
int c[] = {0, -1, 1, 0};
int n, m, x, y, p, q;
queue <ii> que;
bitset <N> used[N];

bool is_node(int i, int j){
    return i > 0 && j > 0 && i <= n &&
            j <= m && !used[i][j];
}

bool check(int lim){
    if (dis[x][y] < lim) return 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            used[i][j] = 0;
    que.emplace(x, y); used[x][y] = 1;
    while (!que.empty()){
        int u, v; tie(u, v) = que.front();
        que.pop();
        for (int k = 0; k < 4; k++){
            int i = u + r[k], j = v + c[k];
            if (!is_node(i, j)) continue;
            if (dis[i][j] < lim) continue;
            que.emplace(i, j);
            used[i][j] = 1;
        }
    }
    return used[p][q];
}

int main(){
    freopen("vuk.inp", "r", stdin);
    freopen("vuk.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
            if (a[i][j] == '+'){
                que.emplace(i, j);
                used[i][j] = 1;
            }
            if (a[i][j] == 'V')
                x = i, y = j;
            if (a[i][j] == 'J')
                p = i, q = j;
        }
    while (!que.empty()){
        int u, v; tie(u, v) = que.front();
        que.pop();
        for (int k = 0; k < 4; k++){
            int i = u + r[k], j = v + c[k];
            if (!is_node(i, j)) continue;
            dis[i][j] = dis[u][v] + 1;
            used[i][j] = 1;
            que.emplace(i, j);
        }
    }
    int lo = 1, hi = min(dis[x][y], dis[p][q]), ans = 0;
    while (lo <= hi){
        int mi = (lo + hi) / 2;
        if (check(mi))
            ans = mi, lo = mi + 1;
        else hi = mi - 1;
    }
    cout << ans << '\n';
}