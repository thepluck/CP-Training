#include <bits/stdc++.h>
using namespace std;

const int N = 55;
const int M = 20005;

int dp[N][M]; int s[N][M];
deque <int> dq; int n, m, k;

bool cmp1(int r, int i, int j) {
    return dp[r][i] - s[r][i] > dp[r][j] - s[r][j];
}

bool cmp2(int r, int i, int j) {
    return dp[r][i] + s[r][i - k] > dp[r][j] + s[r][j - k];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> s[i][j];
            s[i][j] += s[i][j - 1];
        }
    for (int i = 2; i <= n + 1; i++) {
        dq.clear();
        for (int j = k; j <= m; j++) {
            while (!dq.empty() && dq.front() <= j - k)
                dq.pop_front();
            while (!dq.empty() && cmp1(i - 1, j, dq.back()))
                dq.pop_back();
            dq.push_back(j);
            dp[i][j] = s[i][j] - s[i][j - k] + dp[i - 1][dq[0]]
                        + s[i - 1][j] - s[i - 1][dq[0]];
        }
        dq.clear();
        for (int j = m; j >= k; j--) {
            while (!dq.empty() && dq.front() >= j + k)
                dq.pop_front();
            while (!dq.empty() && cmp2(i - 1, j, dq.back()))
                dq.pop_back();
            dq.push_back(j);
            dp[i][j] = max(dp[i][j], s[i][j] - s[i][j - k] +
            dp[i - 1][dq[0]] + s[i - 1][dq[0] - k] - s[i - 1][j - k]);
        }
        int tmp = 0;
        for (int j = k; j <= m; j++) {
            tmp = max(tmp, dp[i - 1][j - k]);
            dp[i][j] = max(dp[i][j], tmp + s[i][j]
            - s[i][j - k] + s[i - 1][j] - s[i - 1][j - k]);
        }
        tmp = 0;
        for (int j = m - k; j >= k; j--) {
            tmp = max(tmp, dp[i - 1][j + k]);
            dp[i][j] = max(dp[i][j], tmp + s[i][j]
            - s[i][j - k] + s[i - 1][j] - s[i - 1][j - k]);
        }
    }
    int res = 0;
    for (int j = k; j <= m; j++)
        res = max(res, dp[n + 1][j]);
    cout << res << '\n';
}
