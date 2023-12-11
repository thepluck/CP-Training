#include <bits/stdc++.h>
using namespace std;

template <typename T>
using max_heap = priority_queue <T>;

template <typename T>
using min_heap = priority_queue <T, vector <T>, greater <T>>;

using ll = long long;
using ii = pair <int, int>;
using edge = tuple <ll, int, int>;

const int N = 505;
int n, m, used[N][N]; ll dis[N][N];
int a[N][N], b[N][N], h;
int r[] = {-1, 0, 0, 1};
int c[] = {0, -1, 1, 0};

bool is_node(int i, int j){
    return i > 0 && j > 0 && i <= n && j <= m;
}

double dijkstra(){
    memset(dis, 0x3f, sizeof dis);
    queue <ii> q; min_heap <edge> pq;
    q.emplace(1, 1); used[1][1] = true;
    while (!q.empty()){
        int i, j; tie(i, j) = q.front();
        q.pop(); pq.emplace(0, i, j); dis[i][j] = 0;
        for (int k = 0; k < 4; k++){
            int x = i + r[k], y = j + c[k];
            if (!is_node(x, y) || used[x][y]) continue;
            if (b[x][y] - h < 50) continue;
            if (b[x][y] - a[x][y] < 50) continue;
            if (b[x][y] - a[i][j] < 50) continue;
            if (b[i][j] - a[x][y] < 50) continue;
            used[x][y] = true; q.emplace(x, y);
        }
    }
    while (!pq.empty()){
        int i, j; ll cur; tie(cur, i, j) = pq.top();
        pq.pop(); if (dis[i][j] < cur) continue;
        for (int k = 0; k < 4; k++){
            int x = i + r[k], y = j + c[k];
            if (b[x][y] - a[x][y] < 50) continue;
            if (b[x][y] - a[i][j] < 50) continue;
            if (b[i][j] - a[x][y] < 50) continue;
            ll nxt = cur;
            if (b[x][y] - h + cur < 50)
                nxt += 50 - b[x][y] + h - cur;
            if (h - nxt - a[i][j] >= 20) nxt += 10;
            else nxt += 100;
            if (dis[x][y] > nxt){
                dis[x][y] = nxt; pq.emplace(nxt, x, y);
            }
        }
    }
    return 1.0 * dis[n][m] / 10;
}

int main(){
    freopen("kayak.inp", "r", stdin);
    freopen("kayak.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout.precision(6); fixed(cout);
    cin >> h >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> b[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    cout << dijkstra() << '\n';
}