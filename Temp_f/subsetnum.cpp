#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    int n = s.size(), res = 0;
    vector <int> pw2(n), pw11(n);
    pw2[0] = pw11[0] = 1;
    for (int i = 1; i < n; i++) {
        pw2[i] = ll(pw2[i - 1]) * 2 % MOD;
        pw11[i] = ll(pw11[i - 1]) * 11 % MOD;
    }
    for (int i = 0; i < n; i++) {
        int add = s[i] - '0';
        add = ll(add) * pw2[i] % MOD;
        add = ll(add) * pw11[n - i - 1] % MOD;
        if ((res += add) >= MOD) res -= MOD;
    }
    cout << res << '\n';
}