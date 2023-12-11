#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int u, v, w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
    Edge() {}
};

bool operator < (Edge& a, Edge& b){
    return a.w < b.w;
}
typedef vector <int> vi;

struct Dsu{
    vi par, rate;
    Dsu(int n) : par(n + 1), rate(n + 1, 0) {
        for (int i = 1; i <= n; i++) par[i] = i;
    }
    int find_set(int u){
        if (u != par[u]) par[u] = find_set(par[u]);
        return par[u];
    }
    bool union_set(int u, int v){
        u = find_set(u); v = find_set(v);
        if (u == v) return false;
        if (rate[u] == rate[v]) rate[u]++;
        if (rate[u] > rate[v]) par[v] = u;
        else par[u] = v;
        return true;
    }
};

int main(){
    int n, m; cin >> n >> m;
    vector <Edge> Adj(m);
    for (auto &e : Adj) cin >> e.u >> e.v >> e.w;
    sort(Adj.begin(), Adj.end());
    Dsu D(n); int res = 0;
    for (auto &e : Adj)
        if (D.union_set(e.u, e.v)) res += e.w;
    cout << res; return 0;
}
