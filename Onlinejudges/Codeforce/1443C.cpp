#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        long long sum = 0;
        vector <pair <int, int>> a(n);
        for (auto &p : a) cin >> p.first;
        for (auto &p : a) {
            cin >> p.second; sum += p.second;
        }
        long long ans = sum;
        sort(a.begin(), a.end());
        for (auto &p : a) {
            sum -= p.second;
            ans = min(ans, max(sum, (long long)p.first));
        }
        cout << ans << '\n';
    }
}