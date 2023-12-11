#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e5 + 5;
const int mod = 1e9 + 7;
ll pw[N], has[N];
ll mn = LLONG_MAX, mx = 0;

void solve(string s){
    int n = s.size(); s = ' ' + s;
    for (int i = 1; i <= n; i++)
        has[i] = (has[i - 1] * 2 + (s[i] == 'W')) % mod;
    for (int i = 1; i <= n; i++){
        ll tmp = (has[i - 1] + (has[n] - has[i - 1] *
        pw[n - i + 1] % mod) * pw[i - 1] % mod + mod) % mod;
        mx = max(mx, tmp); mn = min(mn, tmp);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    string s; cin >> s; pw[0] = 1;
    for (int i = 1; i <= s.size(); i++)
        pw[i] = pw[i - 1] * 2 % mod;
    solve(s);
    for (char &c : s) if (c == 'W') c = 'B'; else c = 'W';
    solve(s);
    reverse(s.begin(), s.end());
    solve(s);
    for (char &c : s) if (c == 'W') c = 'B'; else c = 'W';
    solve(s);
    cout << mn << ' ' << mx << '\n';
}