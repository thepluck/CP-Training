#include <bits/stdc++.h>

using namespace std;

const int M = 1000000007;
const int V = 2000005;
const int N = 14;

int add(int x, int y) {
    return (x += y) >= M ? x - M : x;    
}

int sub(int x, int y) {
    return (x -= y) < 0 ? x + M : x;
}

int mul(int x, int y) {
    return (long long)x * y % M;
}


int inv[V], a[N], win[N][1 << N], scc[1 << N];

int prob(int i, int j) {
    return mul(a[i], inv[a[i] + a[j]]);    
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    inv[1] = 1;
    for (int i = 2; i < V; i++)
        inv[i] = M - mul(inv[M % i], M / i);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        for (int mask = 0; mask < (1 << n); mask++) {
            if (mask >> i & 1) continue;
            win[i][mask] = 1;
            for (int j = 0; j < n; j++)
                if (mask >> j & 1)
                    win[i][mask] = mul(win[i][mask], prob(i, j));
        }
    int res = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        scc[mask] = 1;
        for (int smask = mask & (mask - 1); smask > 0; --smask &= mask) {
            int tmp = scc[smask];
            for (int i = 0; i < n; i++)
                if (smask >> i & 1)
                    tmp = mul(tmp, win[i][mask ^ smask]);
            scc[mask] = sub(scc[mask], tmp);
        }
        int tmp = scc[mask];
        for (int i = 0; i < n; i++)
            if (mask >> i & 1)
                tmp = mul(tmp, win[i][mask ^ ((1 << n) - 1)]);
        res = add(res, mul(tmp, __builtin_popcount(mask)));
    }
    cout << res;
}