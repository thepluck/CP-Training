#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

const int INF = 0x3f3f3f3f;

int t[1005][1005], c[1005], sum[1005];
vector <int> cur[6], ans[6]; int tot[6];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        sum[i] = sum[i - 1] + c[i] / m;
    }
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            cin >> t[i][j];
    int sumt = 0;
    for (int i = 1; i <= n; i++)
        sumt += t[i - 1][i];
    vector <vector <int>> dp(n + 5, vector <int> (int(1e8) / n, INF));
    vector <vector <int>> tr(n + 5, vector <int> (int(1e8) / n, INF));
    int ratio = min(sum[n], sumt) / (int(1e8) / n) + 1;
    int best = INF, mx = dp[0].size();
    dp[0][0] = 0;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < dp[0].size(); j++)
            if (dp[i][j] != INF) {
                if (j + t[i][i + 1] / ratio < mx)
                    if (cmin(dp[i + 1][j + t[i][i + 1] / ratio], dp[i][j]))
                        tr[i + 1][j + t[i][i + 1] / ratio] = i;
                if (j + t[i][i + 2] / ratio < mx)
                    if (cmin(dp[i + 2][j + t[i][i + 2] / ratio], dp[i][j] + c[i + 1] / m))
                        tr[i + 2][j + t[i][i + 2] / ratio] = i;
                if (j + t[i][i + 3] / ratio < mx)
                    if (cmin(dp[i + 3][j + t[i][i + 3] / ratio], dp[i][j] + c[i + 1] / m + c[i + 2] / m))
                        tr[i + 3][j + t[i][i + 3] / ratio] = i;
            }
    for (int i = n - 2; i <= n; i++)
        for (int j = 0; j < dp[0].size(); j++)
            if (dp[i][j] != INF) {
                int curi = i, curj = j, cost1 = t[i][0];
                vector <int> index;
                for (int x = n; x > i; x--)
                    index.push_back(x);
                while (curi) {
                    int pre = tr[curi][curj];
                    for (int x = pre + 1; x < curi; x++)
                        index.push_back(x);
                    cost1 += t[pre][curi];
                    curj -= t[pre][curi] / ratio; curi = pre;
                }
                sort(index.begin(), index.end(),
                [](int p, int q) {return c[p] < c[q];});
                for (int step = 0; step < 5; step++) {
                    for (int y = 0; y < m; y++) {
                        cur[y].clear(); tot[y] = 0;
                    }
                    for (int x : index) {
                        int p = min_element(tot, tot + m) - tot;
                        tot[p] += c[x]; cur[p].push_back(x);
                    }
                    int cost2 = cost1;
                    for (int y = 0; y < m; y++)
                        cost2 = max(cost2, tot[y]);
                    if (best > cost2) {
                        best = cost2;
                        for (int y = 0; y < m; y++)
                            ans[y] = cur[y];
                    }
                    shuffle(index.begin(), index.end(), rng);
                }
            }
    for (int y = 0; y < m; y++) {
        cout << ans[y].size() << ' ';
        sort(ans[y].begin(), ans[y].end());
        for (int x : ans[y]) cout << x << ' ';
        cout << '\n';
    }
    cerr << double(clock()) / CLOCKS_PER_SEC << '\n';
}
