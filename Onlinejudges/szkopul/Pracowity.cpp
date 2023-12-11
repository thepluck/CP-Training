/// from a permution P to all of its predecessor
/// how many swaps needed

/// F[n] = number of swap n n-1 n-2 ... 2 1

/// First sort n-1 n-2 ... 2 1 using F[n-1] swaps

/// "xth hole permutation": x 1 2 ... x-1 x+1 ... n-1 n
/// [(n+1)/2] swap -> x-1 n n-1 ... x x-2 ... 2 1
/// (n n-1 ... x x-2 ... 2 1) <- F[i - 1]
/// "(x-1)th hold permutaion": x-1 1 2 ... x-2 x ... n-1 n

/// Repeat process from "nth hole permution"
/// F[n] = F[n - 1] * n + [(n + 1) / 2] * (n - 1)


/// P[1] P[2] ... P[n]
/// First sort P[2] ... P[n] using X swaps
/// need more (P[1]-1) * ([(n+1)/2] + F[n-1]) swaps
/// cause P is now a "hole permutation"
/// remove P[1]

/// P[2] = how many x alive <= P[2]
/// P[3] = how many x alive <= P[3]
/// ...
/// P[n] = how many x alive <= P[n]
/// (using BIT, segment tree, etc)

/// P[2] P[3] ... P[n] is now a permutation
/// calculate X similar as above

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000005;
const int MOD = 1000000007;

int BIT[MAXN], DP[MAXN], P[MAXN];

int add(int x, int y) {
    if ((x += y) >= MOD) x -= MOD;
    return x;
}

int mul(int x, int y) {
    return (long long)x * y % MOD; 
}

void add(int i) {
    for (; i < MAXN; i += i & -i)
        BIT[i]++;
}

int sum(int i) {
    int res = 0;
    for (; i > 0; i -= i & -i)
        res += BIT[i];
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        DP[i] = add(mul(DP[i - 1], i),
        mul(i - 1, (i + 1) / 2));
        cin >> P[i];
    }
    int res = 0;
    for (int i = 1; i <= N; i++) {
        add(P[i]);
        res = add(res, mul(P[i] - sum(P[i]),
        add(DP[N - i], (N - i) / 2 + 1)));
    }
    cout << res << '\n';
}