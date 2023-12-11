#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define fi first
#define se second
using ii = pair <int, int>;

template <class X, class Y>
bool chkmin(X &a, const Y &b){
    return a > b ? a = b, 1 : 0;
}

const int inf = 0x3f3f3f3f;
const int N = 1e6 + 5;
vector <ii> skip[N];
vector <vector <int>> dis, a;
int n, m, q, pre[8]; bool used[N];
int r[] = {-1, 0, 0, 1};
int c[] = {0, -1, 1, 0};

int path(ii s, ii t){
    for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++){
                dis[i][j] = inf; used[a[i][j]] = false;
            }
    dis[s.fi][s.se] = 0; int id = 0;
    queue <pair <ii, int>> bucket[4];
    bucket[0].emplace(ii(s.fi, s.se), 0);
    while (!bucket[id].empty()){
        while (!bucket[id].empty()){
            ii cur; int w;
            tie(cur, w) = bucket[id].front();
            bucket[id].pop(); if (cur == t) return w;
            if (w > dis[cur.fi][cur.se]) continue;
            if (cur.fi > 1){
                ii nxt = {cur.fi - 1, cur.se};
                if (chkmin(dis[nxt.fi][nxt.se], w + 1))
                    bucket[pre[id + 1]].emplace(nxt, w + 1);
            }
            if (cur.se > 1){
                ii nxt = {cur.fi, cur.se - 1};
                if (chkmin(dis[nxt.fi][nxt.se], w + 1))
                    bucket[pre[id + 1]].emplace(nxt, w + 1);
            }
            if (cur.fi < n){
                ii nxt = {cur.fi + 1, cur.se};
                if (chkmin(dis[nxt.fi][nxt.se], w + 1))
                    bucket[pre[id + 1]].emplace(nxt, w + 1);
            }
            if (cur.se < m){
                ii nxt = {cur.fi, cur.se + 1};
                if (chkmin(dis[nxt.fi][nxt.se], w + 1))
                    bucket[pre[id + 1]].emplace(nxt, w + 1);
            }
            if (used[a[cur.fi][cur.se]]) continue;
            used[a[cur.fi][cur.se]] = true;
            for (ii nxt : skip[a[cur.fi][cur.se]])
                if (chkmin(dis[nxt.fi][nxt.se], w + 3))
                    bucket[pre[id + 3]].emplace(nxt, w + 3);
        }
        id = pre[id + 1];
        if (bucket[id].empty()) id = pre[id + 1];
        if (bucket[id].empty()) id = pre[id + 1];
    }
    return dis[t.fi][t.se];
}

int main(){
    freopen("covid19.inp", "r", stdin);
    freopen("covid19.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> q;
    pre[0] = pre[4] = 0;
    pre[1] = pre[5] = 1;
    pre[2] = pre[6] = 2;
    pre[3] = pre[7] = 3;
    dis.resize(n + 1, vector <int> (m + 1));
    a.resize(n + 1, vector <int> (m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            cin >> a[i][j]; skip[i * j].eb(i, j);
        }
    while (q--){
        int i, j, x, y; cin >> i >> j >> x >> y;
        cout << path({i, j}, {x, y}) << '\n';
    }
}