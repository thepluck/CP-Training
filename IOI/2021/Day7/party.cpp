#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1000000007;
const int SIZ = 1 << 15;
const int LEN = 130;

int pw2[2][SIZ];

int Add(int x, int y) {
    return x - ((x += y) >= MOD ? MOD : 0);
}

int Sub(int x, int y) {
    return x + ((x -= y) < 0 ? MOD : 0);
}

int Mul(int x, int y) {
    return (ll)x * y % MOD;
}

// int Pow(int x, int k) {
//     int res = 1;
//     for (; k; k >>= 1, x = Mul(x, x))
//         if (k & 1) res = Mul(res, x);
//     return res;
// }

int Pow2(long long k) {
    k %= MOD - 1;
    return Mul(pw2[0][k & (SIZ - 1)], pw2[1][k >> 15]);
}

vector <long long> get_cnt(int N) {
    int K = 64 - __builtin_clzll(N);
    vector <long long> cnt(64);
    for (int i = 0; i + 1 < K; i++)
        cnt[i] = 1ll << i;
    cnt[K - 1] = N - (1 << (K - 1) - 1);
    return cnt;
}

int calc(ll N, const vector <ll> &cnt) {
    int K = 64 - __builtin_clzll(N), res = 0;
    vector <long long> sum = cnt;
    for  (int i = LEN - 2; i >= 0; i--) {
        sum[i] += sum[i + 1];
        res = Add(res, Mul(i, Sub(Pow2(sum[i]), Pow2(sum[i + 1]))));
    }
    if (N == 1) return res;
    int L = (1ll << (K - 2)) - 1 + min(1ll << (K - 2), N - (1ll << (K - 1)) + 1);
    int R = N - L - 1;
    vector <long long> tmp, cnt;
    if (L) tmp = 
}

void solve() {
    ll N; cin >> N;
    
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    pw2[0][0] = pw2[1][0] = 1;
    for (int i = 1; i < SIZ; i++)
        pw2[0][i] = Mul(pw2[0][i - 1], 2);
    pw2[1][1] = Mul(pw2[0][SIZ - 1], 2);
    for (int i = 2; i < SIZ; i++)
        pw2[1][i] = Mul(pw2[1][i - 1], pw2[1][1]);
    // int Q; cin >> Q;
    // while (Q--) solve();
}