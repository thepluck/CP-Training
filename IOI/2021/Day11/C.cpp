#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;
const int MAXS = 20005;
const int MOD = 1000000007;

int A[MAXN], B[MAXN], fac[MAXN];
int F[MAXS][MAXN], G[MAXS][MAXN], H[MAXN * 2];

int Add(int x, int y) {
    if ((x += y) >= MOD) x -= MOD;
    return x;
}

int Sub(int x, int y) {
    if ((x -= y) < 0) x += MOD;
    return x;
}

int Mul(int x, int y) {
    return (long long)x * y % MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, S; cin >> N >> S;
    F[0][0] = G[0][0] = fac[0] = 1;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        for (int s = 20000; s >= A[i]; s--)
            for (int j = i; j > 0; j--)
                F[s][j] = Add(F[s][j], F[s - A[i]][j - 1]);
        fac[i] = Mul(fac[i - 1], i);
    }
    for (int i = 1; i <= N; i++) {
        cin >> B[i];
        for (int s = 20000; s >= B[i]; s--)
            for (int j = i; j > 0; j--)
                G[s][j] = Add(G[s][j], G[s - B[i]][j - 1]);  
    }
    for (int s = 19999; s >= 0; s--)
        for (int j = 0; j <= N; j++)
            G[s][j] = Add(G[s][j], G[s + 1][j]);
    int res = 0;
    for (int s = 0; s <= S; s++)
        for (int j = 1; j <= N * 2; j++) {
            int x = (j + 1) / 2, y = j - x;
            H[j] = Add(H[j], Mul(F[S - s][x],
            Mul(G[s][y], Mul(fac[x], Mul(fac[y],
            Mul(fac[N - x], fac[N - y]))))));
        }
    for (int j = 2 * N; j > 0; j--)
        H[j] = Sub(H[j], H[j - 1]);
    for (int j = 2; j <= N * 2; j += 2)
        res = Add(res, H[j]);
    cout << res;
}