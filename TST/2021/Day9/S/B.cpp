#include <bits/stdc++.h>

using namespace std;

const int N = 500005;

int BIT[3][N], val[N];

void update(int id, int i, int v) {
    for (; i < N; i += i & -i)
        BIT[id][i] = max(BIT[id][i], v);
}

int query(int id, int i) {
    int res = 0;
    for (; i > 0; i -= i & -i)
        res = max(res, BIT[id][i]);
    return res;
}

int main() {
    freopen("lis.inp", "r", stdin);
    freopen("lis.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n, res = 0; cin >> n;
    vector <int> rar;
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
        rar.push_back(val[i]);
        rar.push_back(-val[i]);
    }
    sort(rar.begin(), rar.end());
    rar.erase(unique(rar.begin(),
    rar.end()), rar.end());
    for (int i = 1; i <= n; i++) {
        int pos = upper_bound(rar.begin(),
        rar.end(), val[i]) - rar.begin();
        int neg = upper_bound(rar.begin(),
        rar.end(), -val[i]) - rar.begin();
        int dp[3];
        dp[0] = query(0, pos - 1) + 1;
        dp[1] = max(query(0, neg - 1),
        query(1, neg - 1)) + 1;
        dp[2] = max(query(2, pos - 1),
        query(1, pos - 1)) + 1;
        res = max({res, dp[0], dp[1], dp[2]});
        update(0, pos, dp[0]);
        update(1, neg, dp[1]);
        update(2, pos, dp[2]);
    }
    cout << res << '\n';
}