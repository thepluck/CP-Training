#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e5 + 5;
ll a[N], sum = 0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i]; sum += a[i];
    }
    ll mx = *max_element(a + 1, a + n + 1);
    if (2 * mx >= sum) cout << sum - mx << '\n';
    else cout << sum / 2 << '\n';
}