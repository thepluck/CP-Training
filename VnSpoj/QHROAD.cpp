#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b, x) for (int i = a; i x b; ++i)
#define FORD(i, a, b, x) for (int i = a; i x b; --i)

const int N = 1e5 + 5;
int anc[N], rnk[N], n, m, reg, q;
int que[N], id[N], from[N], to[N];

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
    cin >> n >> m >> q; reg = n;
    FOR(i, 1, n, <=) anc[i] = i;
    FOR(i, 1, m, <=) cin >> from[i] >> to[i];
    FOR(i, 1, q, <=){
        cin >> que[i]; id[que[i]] = i;
    }
    FOR(i, 1, m, <=) if (id[i] == 0) 
        reg -= union_set(from[i], to[i]);
    FORD(i, q, 1, >=){
        int old_reg = reg;
        reg -= union_set(from[que[i]], to[que[i]]);
        que[i] = old_reg;
    }
    FOR(i, 1, q, <=) cout << que[i] << '\n';
}