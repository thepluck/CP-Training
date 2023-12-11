#include <bits/stdc++.h>

using namespace std;

const int MAXN = 505;

int N, M, MOD, C[MAXN][MAXN];
int cnt1[MAXN], sum1[MAXN];
int cnt2[MAXN][MAXN], sum2[MAXN][MAXN];

int add(int x, int y) {
    if ((x += y) >= MOD) x -= MOD;
    return x;
}

int mul(int x, int y) {
    return (long long)x * y % MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M >> MOD;
    for (int i = 0; i <= N; i++) C[i][0] = 1;
    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= i; j++)
            C[i][j] = add(C[i - 1][j], C[i - 1][j - 1]);
    cnt1[0] = cnt2[0][0] = 1;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= i; j++) {
            cnt1[i] = add(cnt1[i], mul(C[i - 1][j - 1],
            mul(i + 1, mul(cnt1[j - 1], cnt1[i - j]))));
            sum1[i] = add(sum1[i], mul(C[i - 1][j - 1],
            add(mul(add(mul(cnt1[j - 1], sum1[i - j]),
            mul(sum1[j - 1], cnt1[i - j])), i + 1),
            mul(j * (j - 1) / 2 + (i - j + 1) * (i - j) / 2,
            mul(cnt1[j - 1], cnt1[i - j])))));
        }
    }
    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= min(M, i); j++) {
            for (int k = 0; k <= min(M - j, N - i); k++) {
                cnt2[i + k + 1][j + k] = add(cnt2[i + k + 1][j + k],
                mul(C[j + k][k], mul(cnt2[i][j], cnt1[k])));
                sum2[i + k + 1][j + k] = add(sum2[i + k + 1][j + k],
                mul(C[j + k][k], add(mul(cnt2[i][j], sum1[k]),
                mul(sum2[i][j], cnt1[k]))));
            }
        }
    cout << sum2[N + 1][M] << '\n';
}