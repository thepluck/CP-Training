#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000005;
const int MOD = 1000000007;

int deg[MAXN];

int Add(int x, int y) {
    if ((x += y) >= MOD) x -= MOD;
    return x;
}

int Mul(int x, int y) {
    return (long long)x * y % MOD;
}

int Sub(int x, int y) {
    if ((x -= y) < 0) x += MOD;
    return x;
}

int Pow(int x, int k) {
    int res = 1;
    for (; k; k >>= 1, x = Mul(x, x))
        if (k & 1) res = Mul(res, x);
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    for (int i = 1; i < N; i++) {
        int u, v; cin >> u >> v;
        deg[u]++; deg[v]++;
    }
    int res = 0;
    for (int u = 2; u <= N; u++) {
        int cur = 0;
        for (int i = 1; i <= deg[u]; i++)
            cur = Add(cur, Mul(M, Mul(Pow(M - 1,
            i - 1), Pow(M, deg[u] - i))));
        cur = Sub(cur, Pow(M, deg[u]));
        res = Add(res, Mul(cur, Pow(M, N - 1 - deg[u])));
    }
    int cur = 0;
    for (int i = 1; i <= deg[1]; i++)
        cur = Add(cur, Mul(M, Mul(Pow(M - 1,
        i - 1), Pow(M, deg[1] - i))));
    res = Add(res, Mul(cur, Pow(M, N - 1 - deg[1])));
    cout << Mul(res, Pow(Pow(M, N - 1), MOD - 2));
}