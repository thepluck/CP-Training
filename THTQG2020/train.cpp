#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

struct edge {
    int u, v;

    edge() {}

    edge(int u, int v): u(u), v(v) {}
};

using ii = pair <int, int>;

const int N = 200005;

edge ed[N]; int ban;
vector <ii> adj[N];
int num[N], low[N], tim;
bool bri[N];
int ped[N], par[N];

void dfs(int u, int e) {
    num[u] = low[u] = ++tim;
    for (ii p : adj[u]) {
        int v, i; tie(v, i) = p;
        if (i == ban) continue;
        if (i == e) continue;
        if (!num[v]) {
            par[v] = u; ped[v] = i;
            dfs(v, i);
            cmin(low[u], low[v]);
            if (low[v] > num[u])
                bri[i] = 1;
        }
        else cmin(low[u], num[v]);
    }
}

int main() {
#ifdef LightUpTheFire
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // LightUpTheFire
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector <int> vers;
    for (int i = 1; i <= m; i++) {
        cin >> ed[i].u >> ed[i].v;
        adj[ed[i].u].eb(ed[i].v, i);
        adj[ed[i].v].eb(ed[i].u, i);
        vers.eb(ed[i].u);
        vers.eb(ed[i].v);
    }
    sort(vers.begin(), vers.end());
    vers.erase(unique(vers.begin(),
    vers.end()), vers.end());
    long long res = 0;
    for (ban = 1; ban <= m; ban++) {
        for (int u : vers)
            par[u] = num[u] = low[u] = 0;
        for (int i = 1; i <= m; i++)
            bri[i] = 0;
        tim = 0; dfs(1, 0);
        if (!par[2]) {
            res += m - 1; continue;
        }
        int u = 2;
        while (u != 1) {
            if (bri[ped[u]]) {
                res++;
            }
            u = par[u];
        }
    }
    cout << (m * (m - 1) - res) / 2;
}
