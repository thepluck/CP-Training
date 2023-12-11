#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
map <int, int> mp;
int k, n, x;
long long ans, sum;

int main(){
    freopen("pseq.inp", "r", stdin);
    freopen("pseq.out", "w", stdout);
    cin >> n >> k; mp[0] = 1;
    for (int i = 1; i <= n; i++){
        cin >> x; sum += x;
        auto it  = mp.find(sum - k);
        if (it != mp.end())
            ans += it->second;
        mp[sum]++;
    }
    cout << ans << '\n';
}