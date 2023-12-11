#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int par[N], dis[N];
int bl[N], wh[N];

int find_set(int u) {
    if (u != par[u]) {
        int r = find_set(par[u]);
        dis[u] ^= dis[par[u]];
        par[u] = r;
    }
    return par[u];
}

int main() {
    freopen("gquery.inp", "r", stdin);
    freopen("gquery.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        par[i] = i; bl[i] = 1;
    }
    int cmd, u, v, sum = 0;
    while (q--) {
        cin >> cmd >> u;
        if (cmd == 1) {
            cin >> v;
            int x = find_set(u);
            int y = find_set(v);
            if (x != y) {
                par[x] = y;
                cout << "OKOK\n";
                sum -= min(bl[x], wh[x]);
                sum -= min(bl[y], wh[y]);
                if (dis[u] ^ dis[v]) {
                    bl[y] += bl[x];
                    wh[y] += wh[x];
                    dis[x] = 0;
                }
                else {
                    bl[y] += wh[x];
                    wh[y] += bl[x];
                    dis[x] = 1;
                }
                sum += min(bl[y], wh[y]);
            }
            else {
                if (dis[u] ^ dis[v])
                    cout << "OKOK\n";
                else cout << "!!!!\n";
            }
        }
        if (cmd == 2) {
            cin >> v;
            int x = find_set(u);
            int y = find_set(v);
            if (x != y) cout << "CANT\n";
            else {
                if (dis[u] ^ dis[v])
                    cout << "DIFF\n";
                else cout << "SAME\n";
            }
        }
        if (cmd == 3) {
            int x = find_set(u);
            if (dis[u])
                cout << wh[x] << '\n';
            else cout << bl[x] << '\n';
        }
        if (cmd == 4) {
            int x = find_set(u);
            if (dis[u])
                cout << sum + wh[x]
                - min(bl[x], wh[x]) << '\n';
            else cout << sum + bl[x]
                - min(bl[x], wh[x]) << '\n';
        }
    }
}