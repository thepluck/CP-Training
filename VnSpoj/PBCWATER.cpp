#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e3 + 5;
int n, m, h[N][N], f[N][N];
int r[] = {-1, 0, 0, 1};
int c[] = {0, -1, 1, 0};

struct node{
    int u, v, w;
    bool operator < (const node &o) const {
        return w > o.w;
    }
};

bool is_node(int x, int y){
    return x > 0 && y > 0 && x <= n && y <= m;
}

priority_queue <node> pq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m; int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            cin >> h[i][j]; f[i][j] = INT_MAX;
        }
    for (int i = 1; i <= n; i++){
        f[i][1] = h[i][1];
        pq.push({i, 1, f[i][1]});
        f[i][m] = h[i][m];
        pq.push({i, m, f[i][m]});
    }
    for (int j = 1; j <= m; j++){
        f[1][j] = h[1][j];
        pq.push({1, j, f[1][j]});
        f[n][j] = h[n][j];
        pq.push({n, j, f[n][j]});
    }
    while (!pq.empty()){
        auto tmp = pq.top(); pq.pop();
        if (tmp.w > f[tmp.u][tmp.v]) continue;
        for (int k = 0; k < 4; k++){
            int x = tmp.u + r[k];
            int y = tmp.v + c[k];
            if (!is_node(x, y)) continue;
            int cost = max(h[x][y], f[tmp.u][tmp.v]);
            if (f[x][y] > cost){
                f[x][y] = cost;
                pq.push({x, y, f[x][y]});
            }
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            ans += f[i][j] - h[i][j];
    cout << ans << endl;
}