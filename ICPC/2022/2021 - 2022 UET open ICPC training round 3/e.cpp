#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> par(n);
    vector<long long> ans(n), exc(n);
    for (int i = 0; i < n; i++) {
        cin >> par[i] >> ans[i];
        exc[--par[i]] ^= INF;
    }
    for (int i = n - 1; i > 0; i--) {
        ans[i] -= exc[i];
        ans[par[i]] += ans[i];
        exc[par[i]] = min(exc[par[i]], ans[i]);
    }
    cout << ans[0] - exc[0];
}