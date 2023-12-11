#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
ll dp[N], s[N], mn[N], a, b;

bool cmp(int i, int j) {
    return dp[i] + s[i] * b >= dp[j] + s[j] * b;
}

int main() {
    freopen("candy.inp", "r", stdin);
    freopen("candy.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; ll m; cin >> n >> m >> a >> b;
    for (int i = 1; i <= n; i++) {
        cin >> s[i]; s[i] += s[i - 1];
    }
    deque <int> dq; dq.push_back(0);
    for (int i = 1, j = -1; i <= n; i++) {
        while (j < n && s[j + 1] + m < s[i]) j++;
        while (!dq.empty() && dq.front() <= j)
            dq.pop_front();
        dp[i] = inf;
        if (!dq.empty()) dp[i] = dp[dq[0]] +
                    (m - s[i] + s[dq[0]]) * b;
        if (~j) dp[i] = min(dp[i], mn[j] +
                            (s[i] - m) * a);
        mn[i] = min(mn[i - 1], dp[i] - s[i] * a);
        while (!dq.empty() && cmp(dq.back(), i))
            dq.pop_back();
        dq.push_back(i);
    }
    cout << dp[n] << '\n';
}
