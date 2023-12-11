// Problem: D. Winter is here
// Contest: Codeforces - Codeforces Round #428 (Div. 2)
// URL: https://codeforces.com/contest/839/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

const int N = 200005;
const int V = 1000005;
const int MOD = 1000000007;

int cnt[V], ans[V], mu[V], pw[N];

int add(int x, int y) {
    if ((x += y) >= MOD) x -= MOD;
    return x;
}

int sub(int x, int y) {
    if ((x -= y) < 0) x += MOD;
    return x;
}

int mul(int x, int y) {
    return (long long)x * y % MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, res = 0; cin >> n;
    mu[1] = pw[0] = 1;
    for (int i = 1; i <= n; i++)
        pw[i] = add(pw[i - 1], pw[i - 1]);
    for (int i = 1; i < V; i++)
        for (int j = i * 2; j < V; j += i)
            mu[j] -= mu[i];
    while (n--) {
        int x; cin >> x; cnt[x]++;
    }
    for (int i = V - 1; i > 1; i--) {
        for (int j = i; j < V; j += i)
            ans[i] += cnt[j];
        int cur = 0;
        for (int j = 1; i * j < V; j++) {
            if (!ans[i * j]) continue;
            if (mu[j] > 0)
                cur = add(cur, mul(ans[i * j],
                pw[ans[i * j] - 1]));
            else if (mu[j] < 0)
                cur = sub(cur, mul(ans[i * j],
                pw[ans[i * j] - 1]));
        }
        res = add(res, mul(cur, i));
    }
    cout << res << '\n';
}