#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;
const int MOD = 1000000007;

int DP[MAXN][4][4], F[MAXN], inv[MAXN];

void add(int &x, int y) {
    if ((x += y) >= MOD) x -= MOD;
}

void sub(int &x, int y) {
    if ((x -= y) < 0) x += MOD;
}

int mul(int x, int y) {
    return (long long)x * y % MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int c = 0; c < 4; c++)
        DP[1][c][c] = 1;
    inv[1] = 1;
    for (int i = 2; i <= N; i++) {
        for (int c1 = 0; c1 < 4; c1++)
            for (int c2 = 0; c2 < 4; c2++)
                for (int c3 = 0; c3 < 4; c3++)
                    if (c2 != c3 && c2 != (c3 ^ 1))
                        add(DP[i][c1][c3], DP[i - 1][c1][c2]);
        inv[i] = MOD - mul(MOD / i, inv[MOD % i]);
    }
    for (int i = 2; i <= N; i++)
        for (int c1 = 0; c1 < 4; c1++)
            for (int c2 = 0; c2 < 4; c2++)
                if (c1 != c2 && c1 != (c2 ^ 1))
                    add(F[i], DP[i][c1][c2]);
    int ans = 4;
    for (int i = 2; i <= N; i++) {
        for (int j = i * 2; j <= N; j += i)
            sub(F[j], F[i]);
        add(ans, mul(mul(F[i], inv[i]), N / i));
    }
    cout << ans << '\n';
}