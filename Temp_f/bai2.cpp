#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("bai2.inp", "r", stdin);
    freopen("bai2.out", "w", stdout);
    string s; cin >> s;
    int ans = count_if(s.begin(), s.end(), [](const char &x){
        return x == '1';
    });
    int t = s.find('1');
    if (t != -1 && t < 2) ans += 2 - t;
    cout << ans << '\n';
}