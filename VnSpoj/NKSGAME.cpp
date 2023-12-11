#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()
#define lb lower_bound
#define ub upper_bound
int main(){
    int n; cin >> n;
    vector <int> a(n), b(n);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    sort(all(b)); int ans = INT_MAX;
    for (int x : a){
        auto it = lb(all(b), -x);
        if (it != b.end()) ans = min(ans, abs(*it + x));
        if (it != b.begin()) ans = min(ans, abs(*(--it) + x));
    }
    cout << ans << '\n';
}