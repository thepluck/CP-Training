#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;
const int MAXN = 1 << 20;

int A[MAXN], DP[MAXN][2], pre[MAXN];

int add(int x, int y) {
    if ((x += y) >= MOD) x -= MOD;
    return x;
}

int mul(int x, int y) {
    return (long long)x * y % MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, cnt = 0; cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i]; A[i] ^= A[i - 1];
        DP[A[i]][0] = 1;
    }
    for (int i = 1; i < N; i++) {
        if (A[i]) {
            DP[A[i]][0] = add(DP[A[i]][0],
            mul(DP[A[i]][1], cnt - pre[A[i]]));
            DP[A[i]][1] = add(DP[A[i]][0], DP[A[i]][1]);
            pre[A[i]] = cnt;
        } else cnt++;
    }
    if (A[N]) {
        cout << add(DP[A[N]][0],
        mul(DP[A[N]][1], cnt - pre[A[N]]));
    } else {
        int res = 1;
        for (int i = 0; i < cnt; i++)
            res = add(res, res);
        for (int i = 1; i < MAXN; i++)
            res = add(res, DP[i][1]);
        cout << res;  
    }
}