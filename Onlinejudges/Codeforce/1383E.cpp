
// Problem : E. Strange Operation
// Contest : Codeforces - Codeforces Round #659 (Div. 1)
// URL : https://codeforces.com/contest/1383/problem/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void madd(int &x, int y) {
    if ((x += y) >= MOD) x -= MOD;
    if (x < 0) x += MOD;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    string s; cin >> s;
    int ans = 1, n = s.size();
    vector <int> sum(n);
    if (count(s.begin(), s.end(), '0') == n) {
        cout << n << '\n'; return 0;
    }
    int st = 0, en = n - 1;
    while (s[st] == '0') st++;
    while (s[en] == '0') en--;
    for (int i = st; i < en;) {
        int j = i + 1;
        while (s[j] == '0') j++;
        int cur = 0;
        for (int k = 0; k < j - i; k++) {
            madd(cur, ans - sum[k]);
            sum[k] = ans;
        }
        madd(ans, cur); i = j;
    }
    ans = 1ll * ans * (st + 1) % MOD;
    ans = 1ll * ans * (n - en) % MOD;
    cout << ans << '\n';
}