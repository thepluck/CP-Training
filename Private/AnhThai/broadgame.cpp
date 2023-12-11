#include <bits/stdc++.h>

using namespace std;

const int MAXN = 20005;

int mu[MAXN], sum[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    mu[1] = 1;
    for (int i = 1; i < MAXN; i++) {
        for (int j = i * 2; j < MAXN; j += i)
            mu[j] -= mu[i];
    }
    for (int i = 1; i < MAXN; i++)
        mu[i] += mu[i - 1];
    int T = 3;
    while (T--) {
        int K, G = 0; cin >> K;
        while (K--) {
            int M, N, X = 0; cin >> M >> N;
            for (int i = 1; i <= min(M, N); i++) {
                int j = min(M / (M / i), N / (N / i));
                X += (mu[j] - mu[i - 1]) * (M / i) * (N / i);
                i = j;
            }
            G ^= X;
        }
        cout << (G ? "YES\n" : "NO\n");
    }
}
