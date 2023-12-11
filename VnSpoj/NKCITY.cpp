#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int anc[N], rnk[N], n, m;

struct edge{
    int u, v, w;
    bool operator < (const edge &o) const {
        return w < o.w;
    }
};

int find_set(int u){
    if (u != anc[u]) 
        anc[u] = find_set(anc[u]);
    return anc[u];
}

bool union_set(int u, int v){
    u = find_set(u); v = find_set(v);
    if (u == v) return false;
    if (rnk[u] == rnk[v]) rnk[u]++;
    if (rnk[u] > rnk[v]) anc[v] = u;
    else anc[u] = v;
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) anc[i] = i;
    vector <edge> edges(m);
    for (auto &e : edges) 
        cin >> e.u >> e.v >> e.w;
    sort(edges.begin(), edges.end());
    int ans = INT_MIN;
    for (auto e : edges){
        if (union_set(e.u, e.v))
            ans = max(ans, e.w);
    }
    cout << ans << '\n';
}