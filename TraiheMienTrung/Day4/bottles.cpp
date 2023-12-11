#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using ii = pair <int, int>;

const int N = 4e5 + 5;
ll dp[N][2], a[N]; ii tr[N][2];

bool cmp(int i, int j){
    return dp[i][0] - a[i] >= dp[j][0] - a[j];
}

int main(){
    freopen("bottles.inp", "r", stdin);
    freopen("bottles.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    deque <int> dq; dq.push_back(0);
    for (int i = 1; i <= n; i++){
        cin >> a[i]; a[i] += a[i - 1];
        if (dp[i - 1][0] > dp[i - 1][1]){
            tr[i][0] = {i - 1, 0};
            dp[i][0] = dp[i - 1][0];
        }
        else {
            tr[i][0] = {i - 1, 1};
            dp[i][0] = dp[i - 1][1];
        }
        dp[i][1] = a[i] - a[dq[0]] + dp[dq[0]][0];
        tr[i][1] = {dq[0], 0};
        while (!dq.empty() && cmp(i, dq.back()))
            dq.pop_back();
        dq.push_back(i);
        while (!dq.empty() && dq.front() <= i - k + 1)
            dq.pop_front();
    }
    int t = dp[n][0] < dp[n][1];
    ll res = max(dp[n][0], dp[n][1]);
    vector <int> ans;
    while (n){
        if (t){
            for (int i = n; i > tr[n][t].first; i--)
                ans.push_back(i);
        }
        tie(n, t) = tr[n][t];
    }
    cout << ans.size() << ' ' << res << '\n';
    reverse(ans.begin(), ans.end());
    for (int x : ans) cout << x << ' ';
}
