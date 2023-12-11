#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

const int MOD = 1000000007;
const int N = 2000005;

int cnt[N], sum[N];
set <int> pos, val;
map <int, int> nxt;
pair <int, int> dp[N];

void add(int &x, int y) {
    if ((x += y) >= MOD) x -= MOD;
}

void sub(int &x, int y) {
    if ((x -= y) < 0) x += MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int m, n; cin >> m >> n;
    dp[0] = {1, m};
    for (int i = 1; i <= n; i++) {
        int v; cin >> v; val.insert(v);
        if (nxt[v]) {
            int p = nxt[v] - 1;
            if (cnt[dp[p].fi]-- == 1)
                pos.erase(dp[p].fi);
            sub(sum[dp[p].fi], dp[p].se);
        }
        if (cnt[dp[i - 1].fi]++ == 0)
            pos.insert(dp[i - 1].fi);
        add(sum[dp[i - 1].fi], dp[i - 1].se);
        if (val.size() < m)
            dp[i] = {1, m - val.size()};
        else {
            int l = *pos.begin();
            dp[i] = {l + 1, sum[l]};
        }
        nxt[v] = i;
    }
    cout << dp[n].fi << ' ' << dp[n].se << '\n';
}