#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e6 + 5;
const int mod = 10000007;
int lp[N], pr[N], que[N], num, f[N], cn[N];
bitset <N> has;

void sieve(int n){
    for (int i = 2; i <= n; i++){
        if (lp[i] == 0){
            lp[i] = i; pr[++num] = i;
        }
        for (int j = 1; j <= num &&
        pr[j] <= lp[i] && i * pr[j] <= n; j++)
            lp[i * pr[j]] = pr[j];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int q, mx = 0; cin >> q; int g[100];
    for (int i = 1; i <= q; i++){
        cin >> que[i]; has[que[i]] = 1;
        mx = max(mx, que[i]);
    }
    for (int i = 0; i < 100; i++)
        g[i] = (i + 1) * (i + 2) / 2;
    sieve(mx);
    for (int i = 1; i <= mx; i++){
        int x = i;
        while (x > 1){
            cn[lp[x]]++; x /= lp[x];
        }
        if (has[i]){
            ll res = 1;
            for (int j = 1; j <= num; j++)
                res = res * g[cn[pr[j]]] % mod;
            f[i] = res;
        }
    }
    for (int i = 1; i <= q; i++)
        cout << f[que[i]] << '\n';
}