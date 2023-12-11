//https://hackmd.io/nVv35wvRTK-vcdTQVKdmgg
#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back

using ll = long long;

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

vector <int> adj[N];
int d[N], n; ll fac[N], inv[N];

ll mpow(ll x, ll k) {
    ll res = 1;
    for (; k; k >>= 1, x = x * x % MOD)
        if (k & 1) res = res * x % MOD;
    return res;
}

ll inverse(ll x) {
    return mpow(x, MOD - 2);
}

ll C(int k, int n) {
    if (k > n) return 0;
    return fac[n] * inv[k] % MOD * inv[n - k] % MOD;
}

int dfs(int u, int p = 0) {
    int u_sz = 1, v_sz;
    for (int v : adj[u]) {
        if (v == p) continue;
        u_sz += v_sz = dfs(v, u);
        d[__gcd(v_sz, n - v_sz)]++;
    }
    return u_sz;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].eb(v); adj[v].eb(u);
    }
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = inv[i - 1] * inverse(i) % MOD; 
    }
    dfs(1); ll res = 0;
    for (int k = 1; k <= n; k++)
        if (n % k == 0) {
            int cnt = 0;
            for (int t = n / k; t <= n; t += n / k)
                cnt += d[t];
            (res += C(k - 1, cnt)) %= MOD;
        }
    cout << res << '\n';
}