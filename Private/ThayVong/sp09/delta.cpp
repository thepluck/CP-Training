#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()
using ll = long long;
const int N = 2e5 + 5;
int a[N];

int main(){
    freopen("delta.inp", "r", stdin);
    freopen("delta.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--){
        multiset <int> s1, s2;
        int n; cin >> n; ll ans = LLONG_MAX;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i < n; i++){
            vector <int> a1, a2;
            for (int j = 1; j <= i; j++)
                a1.push_back(a[j]);
            for (int j = i + 1; j <= n; j++)
                a2.push_back(a[j]);
            sort(all(a1)); sort(all(a2));
            ll cur = 0;
            for (int j = 0; j < a1.size(); j++){
                cur += abs(a1[a1.size() / 2] - a1[j]);
            }
            for (int j = 0; j < a2.size(); j++){
                cur += abs(a2[a2.size() / 2] - a2[j]);
            }
            ans = min(ans, cur);
        }
        cout << ans << '\n';
    }
    
}