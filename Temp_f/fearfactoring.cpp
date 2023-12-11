/// o(x) denote the sum of divisors of x
/// given a, b <= 10 ^ 12, calculate the sum of o(x) for all a <= x <= b
#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define eb emplace_back
using ll = long long;

int main(){
    ll a, b, res = 0; cin >> a >> b;
    vector <ll> skip; a--; skip.eb(0);
    for (ll i = 1; i <= a; i++){
        i = b / (b / i);
        if (i <= a) skip.eb(i);
    }
    for (ll i = 1; i <= a; i++)
        skip.eb(i = a / (a / i));
    sort(all(skip));
    skip.resize(unique(all(skip)) - skip.begin());
    for (int i = 1; i < skip.size(); i++){
        ll tmp = (skip[i] - skip[i - 1])
                * (skip[i] + skip[i - 1] + 1) / 2;
        res += tmp * (b / skip[i] - a / skip[i]);
    }
    for (ll i = a + 1; i <= b; i++){
        ll j = b / (b / i);
        ll tmp = (j - i + 1) * (j + i) / 2;
        res += tmp * (b / i); i = j;
    }
    cout << res << '\n';
}   
