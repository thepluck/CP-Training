#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("password.inp", "r", stdin);
    freopen("password.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    string s; int x; cin >> s >> x;
    int res = 0;
    for (char c : s)
        res += (x + c - 'a') % 26;
    cout << res << '\n';
}