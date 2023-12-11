#include <bits/stdc++.h>
using namespace std;

#define ctz __builtin_ctz
const int N = 2e5 + 5;
int anc[19][N], dep[N];

int calc_dep(int u){
    if (u == 0 || dep[u] != -1) return dep[u];
    return dep[u] = calc_dep(anc[0][u]) + 1;
}

int get_anc(int u, int k){
    if (k > dep[u]) return -1;
    while (k > 0){
        u = anc[ctz(k)][u]; k -= k & -k;
    }
    return u;
}

int main(){
    int n, q; cin >> n >> q;
    for (int i = 0; i <= n; i++) dep[i] = -1;
    for (int i = 2; i <= n; i++) cin >> anc[0][i];
    for (int i = 1; i <= n; i++) calc_dep(i);
    for (int b = 1; b <= 18; b++)
        for (int i = 1; i <= n; i++)
            if (dep[i] >= (1 << b))
                anc[b][i] = anc[b - 1][anc[b - 1][i]];
    while (q--){
        int u, k; cin >> u >> k;
        cout << get_anc(u, k) << '\n';
    }
}