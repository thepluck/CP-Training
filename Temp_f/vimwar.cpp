//https://www.hackerrank.com/contests/w16/challenges/vim-war
#include <bits/stdc++.h>
using namespace std;

#define popcnt __builtin_popcount
#define parity __builtin_parity

const int MOD = 1e9 + 7;
const int N = 1 << 20;

int cnt[N], pw[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    string s; int rq = 0;
    while (n--) {
        cin >> s; int x = 0;
        for (char c : s)
            x = x * 2 + c - '0';
        cnt[x]++;
    }
    cin >> s;
    for (char c : s)
        rq = rq * 2 + c - '0';
    for (int i = 1; i < N; i++) {
        pw[i] = pw[i - 1] * 2 + 1;
        if (pw[i] >= MOD) pw[i] -= MOD;
    }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < (1 << m); j++)
            if (j >> i & 1)
                cnt[j] += cnt[j ^ (1 << i)];
    int ans = 0;
    for (int j = rq; ~j; j--) {
        if ((rq | j) != rq) continue;
        if (parity(rq ^ j)) {
            ans -= pw[cnt[j]];
            if (ans < 0) ans += MOD;
        }
        else {
            ans += pw[cnt[j]];
            if (ans >= MOD) ans -= MOD;
        }
    }
    cout << ans << '\n';
}