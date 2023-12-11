#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
const int MOD = 1e9 + 7;

vector <int> p[N];
int l[N], r[N], cl[N], cr[N];
int f[N], h[N];

int main() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int s; cin >> s;
        p[s].push_back(i);
    }
    for (int i = 1; i <= m; i++)
        cin >> f[i] >> h[i];
    for (int i = 1; i <= m; i++) {
        if (h[i] > p[f[i]].size()) {
            l[i] = n + 1; r[i] = 0;
        }
        else {
            l[i] = p[f[i]][h[i] - 1];
            r[i] = p[f[i]][p[f[i]].size() - h[i]];
        }
    }
    int mx = 0; long long cnt = 1;
    for (int i = 0; i <= m; i++) {
        if (l[i] > n) continue;
        for (int j = 1; j <= n; j++)
            cl[j] = cr[j] = 0;
        for (int j = 1; j <= m; j++) {
            if (l[j] <= l[i]) cl[f[j]]++;
            if (r[j] > l[i]) cr[f[j]]++;
        }
        int cur = 0; long long way = 1;
        for (int j = 1; j <= n; j++) {
            if (j == f[i]) {
                cur++; int tmp = cr[j];
                if (r[i] > l[i]) tmp--;
                if (!tmp) continue;
                cur++;
                way = way * tmp % MOD;
                continue;
            }
            int lo = min(cl[j], cr[j]);
            int hi = max(cl[j], cr[j]);
            if (!lo && !hi) continue;
            if (lo == 1 && hi == 1) {
                cur++; way = way * 2 % MOD;
                continue;
            }
            if (!lo) {
                cur++; way = way * hi % MOD;
                continue;
            }
            cur += 2;
            way = way * lo % MOD * (hi - 1) % MOD;
        }
        if (mx < cur) {
            mx = cur; cnt = way;
        }
        else if (mx == cur)
            (cnt += way) %= MOD;
    }
    if (mx == 0) cnt = 1;
    cout << mx << ' ' << cnt << '\n';
}
