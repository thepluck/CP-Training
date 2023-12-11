#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 5;
const int LG = 18;

int sum[LG][MAXN], cnt[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    while (N--) {
        int c; cin >> c; cnt[c] ^= 1;
    }
    for (int i = 1; i <= M; i++)
        cnt[i] ^= cnt[i - 1];
    for (int k = 1; k < LG; k++)
        for (int i = 1; i + (1 << k) <= M + 1; i++) {
            /// xor (c - i) in range [i, i + 2 ^ k)
            sum[k][i] = sum[k - 1][i] ^ sum[k - 1][i + (1 << (k - 1))];
            /// (c - i) where c in [i + 2 ^ (k - 1), i + 2 ^ k) have (k - 1)th bit on
            if (cnt[i + (1 << k) - 1] ^ cnt[i + (1 << (k - 1)) - 1])
                sum[k][i] ^= 1 << (k - 1);
        }
    int Q; cin >> Q;
    while (Q--) {
        int l, r, G = 0; cin >> l >> r;
        for (int k = LG - 1; k >= 0; k--)
            if (l + (1 << k) <= r) {
                /// c - l where c in [l + 2 ^ k, r] have kth bit on
                if (cnt[r] ^ cnt[l + (1 << k) - 1]) G ^= 1 << k;
                /// already computed
                G ^= sum[k][l]; l += 1 << k; 
            }
        cout << (G ? 'A' : 'B');
    }
}