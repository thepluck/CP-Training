#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
using ll = long long;
int a[500005], mp[500005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, x; int sum = 0, cur; cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> x;
        cur = (sum - mp[x] + 1 + mod) % mod;
        sum = (sum + cur) % mod;
        mp[x] = (mp[x] + cur) % mod;
    }
    cout << sum << '\n';
}