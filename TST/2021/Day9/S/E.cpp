#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

using ii = pair <int, int>;

const int N = 155;
const int STATE = 5000005;

int dp[STATE], trc[STATE];
int p[N], cost[N][N], ans[N];
int coeff[N], cnt[N], digit[N], n;
bool vis[N]; ii c[N];
vector <int> can[N], need;

int calc(int num, int sum) {
    if (sum == n) return 0;
    if (dp[num] >= 0) return dp[num];
    dp[num] = INT_MAX;
    for (int len : need)
        if (digit[len] < cnt[len]) {
            digit[len]++;
            if (cmin(dp[num], max(calc
            (num + coeff[len], sum + len),
            cost[sum + 1][sum + len])))
                trc[num] = len;
            digit[len]--;
        }
    return dp[num];
}

void trace(int num, int sum) {
    if (sum == n) return;
    int len = trc[num];
    can[len].push_back(sum + 1);
    trace(num + coeff[len], sum + len);
}

void assign(vector <int> ver, int start) {
    ans[ver[0]] = c[start++].se;
    int lo = 1, hi = ver.size() - 1;
    while (lo <= hi) {
        ans[ver[lo]] = c[start++].se;
        if (lo != hi)
            ans[ver[hi]] = c[start++].se;
        lo++; hi--;
    }
}

int main() {
    freopen("vrtic.inp", "r", stdin);
    freopen("vrtic.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) {
        cin >> c[i].fi; c[i].se = i;
    }
    sort(c + 1, c + n + 1);
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        int u = i, len = 0;
        while (!vis[u]) {
            vis[u] = 1; len++; u = p[u];
        }
        cnt[len]++;
    }
    for (int len = 1; len <= n; len++)
        if (cnt[len]) need.push_back(len);
    coeff[1] = 1;
    for (int i = 1; i < n; i++)
        coeff[i + 1] = coeff[i] * (cnt[i] + 1);
    for (int i = 1; i < n; i++) {
        cost[i][i + 1] = c[i + 1].fi - c[i].fi;
        for (int j = i + 2; j <= n; j++)
            cost[i][j] = max(cost[i][j - 1],
            c[j].fi - c[j - 2].fi);
    }
    memset(dp, -1, sizeof dp);
    cout << calc(0, 0) << '\n'; trace(0, 0);
    memset(vis, 0, sizeof vis);
        for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        int u = i; vector <int> ver;
        while (!vis[u]) {
            ver.push_back(u);
            vis[u] = 1; u = p[u];
        }
        assign(ver, can[ver.size()].back());
        can[ver.size()].pop_back();
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
}