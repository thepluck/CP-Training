
// Problem : D. Magic Numbers
// Contest : Codeforces - Educational Codeforces Round 8
// URL : https://codeforces.com/contest/628/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back

const int MOD = 1e9 + 7;

vector <int> can[2];
int dp[2005][2005];
int m, d, n;
vector <int> dgt[2];

int madd(int x, int y) {
    if ((x += y) >= MOD) x -= MOD;
    return x;
}

int rec(int i, int j, bool f, bool g) {
    if (i == n) return j == 0;
    if (!f && !g && ~dp[i][j])
        return dp[i][j];
    int res = 0;
    for (int d : can[i & 1]) {
        if (f && d < dgt[0][i]) continue;
        if (g && d > dgt[1][i]) continue;
        res = madd(res, rec(i + 1, (j * 10 + d) % m,
        f && d == dgt[0][i], g && d == dgt[1][i]));
    }
    if (!f && !g) dp[i][j] = res;
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> m >> d;
    string s; cin >> s;
    for (int i = 0; i < 10; i++)
        if (i != d) can[0].eb(i);
    n = s.size(); can[1].eb(d);
    for (char c : s) dgt[0].eb(c - '0');
    cin >> s;
    for (char c : s) dgt[1].eb(c - '0');
    memset(dp, -1, sizeof dp);
    cout << rec(0, 0, 1, 1) << '\n';
}