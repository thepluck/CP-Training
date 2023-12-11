#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("password.inp", "r", stdin);
    freopen("password.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    string s; int w, res = 0;
    cin >> s >> w;
    for (char c : s)
        res += (c - 'a' + w) % 26;
    cout << res << '\n';
}