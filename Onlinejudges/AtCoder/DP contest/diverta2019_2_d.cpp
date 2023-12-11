#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmax(X &a, const Y &b) {
    return a < b ? a = b, 1 : 0;
}

using ll = long long;

ll dp[1000005];

/// O(n + max(g, s, b))

/// ax + by <= k, maximize cx + dy(bc <= ad)
/// Only need to consider x < b
/// because ax + by = a(x - b) + b(y + a)
/// And c(x - b) + d(y + a) >= cx + dy better
ll calc(ll sum, vector <pair <int, int>> item) {
    if (item.empty()) return sum;
    if (item.size() == 1)
        return sum + sum / item[0].first * item[0].second;
    if (item.size() == 2) {
        if (item[0].second * item[1].first >
        item[0].first * item[1].second) swap(item[0], item[1]);
        ll res = 0;
        for (ll i = 0; i < item[1].first
        && i * item[0].first <= sum; i++) {
            ll j = (sum - i * item[0].first) / item[1].first;
            cmax(res, i * item[0].second + j * item[1].second);
        }
        return sum + res;
    }
    for (int i = 0; i < item.size(); i++)
        for (int j = item[i].first; j <= sum; j++)
            cmax(dp[j], dp[j - item[i].first] + item[i].second);
    return sum + *max_element(dp, dp + sum + 1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int sum; cin >> sum;
    vector <int> a(3), b(3);
    for (int i = 0; i < 3; i++) cin >> a[i];
    for (int i = 0; i < 3; i++) cin >> b[i];
    vector <pair <int, int>> usea, useb;
    for (int i = 0; i < 3; i++)
        if (a[i] < b[i])
            usea.emplace_back(a[i], b[i] - a[i]);
        else if (a[i] > b[i])
            useb.emplace_back(b[i], a[i] - b[i]);
    cout << calc(calc(sum, usea), useb);
}