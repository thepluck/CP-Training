#include <bits/stdc++.h>
using namespace std;

unsigned int a[20005];
using ll = unsigned long long;
ll ans, len;

void solve(){
    int n; cin >> n; ans = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    priority_queue <int, vector <int>, greater <int>> pq(a + 1, a + n + 1);
    while (pq.size() > 1){
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        ans += a + b; pq.push(a + b);
    }
    cout << ans << '\n';
}

int main(){
    int t; cin >> t;
    while (t--) solve();
}
