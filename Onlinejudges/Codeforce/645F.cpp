#include <bits/stdc++.h>

using namespace std;

const int V = 1000005;
const int N = 200005;
const int MOD = 1000000007;

vector <int> divs[V]; bool mark[V];
int phi[V], cnt[V], inv[N], bin[N], val[N];

int add(int x, int y) {
    if ((x += y) >= MOD) x -= MOD;
    return x;
}

int mul(int x, int y) {
    return (long long)x * y % MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k, q, res = 0; cin >> n >> k >> q;
    for (int i = 0; i < n + q; i++) {
        cin >> val[i]; mark[val[i]] = 1;
    }	
    for (int i = 1; i < V; i++) {
        phi[i] += i;
        for (int j = i; j < V; j += i) {
            if (mark[j]) divs[j].push_back(i);
            if (i != j) phi[j] -= phi[i];
        }
    }
    inv[1] = bin[k - 1] = 1;
    for (int i = 2; i < N; i++)
        inv[i] = MOD - mul(MOD / i, inv[MOD % i]);
    for (int i = k; i < N; i++)
        bin[i] = mul(bin[i - 1], mul(i, inv[i - k + 1]));
    for (int i = 0; i < n + q; i++) {
        for (int d : divs[val[i]]) {
            res = add(res, mul(phi[d], bin[cnt[d]])); cnt[d]++;
        }
        if (i >= n) cout << res << '\n';
    }
}