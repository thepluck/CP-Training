#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int S = 100;
const int N = 305;

ll pos[N], neg[N], zero;
ll f[S], g[S];
int dq[S], fi, se;

int main() {
    cin.tie(0)->sync_with_stdio(0);   
    int n; long long need;
    cin >> n >> need;
    for (int i = n; i > 0; i--)
        cin >> neg[i];
    cin >> zero;
    for (int i = 1; i <= n; i++)
        cin >> pos[i];
    memset(f, 0xc0, sizeof f);
    f[S / 2] = 0;
    for (int i = 1; i <= n; i++) {
        int d = min(ll(n), pos[i]);
        for (int r = 0; r < i; r++) {
            /// remainder
            fi = 0; se = -1;
            for (int s = r; s < S; s += i) {
                while (se >= fi && f[dq[se]] -
                f[s] < (dq[se] - s) / i) se--;
                dq[++se] = s;
                if (s - dq[fi] > i * d) fi++;
                g[s] = f[dq[fi]] + (s - dq[fi]) / i;
            }
        }
        d = min(ll(n), neg[i]);
        for (int r = 0; r < i; r++) {
            fi = 0; se = -1;
            int lim = (S - r - 1) / i * i + r;
            for (int s = lim; s >= r; s -= i) {
                while (se >= fi && g[dq[se]] -
                g[s] < (s - dq[se]) / i) se--;
                dq[++se] = s;
                if (dq[fi] - s > i * d) fi++;
                f[s] = g[dq[fi]] + (dq[fi] - s) / i;
            }
        }
    }
    ll cur = 0, res = -1e18, num = 0;
    for (int i = 1; i <= n; i++) {
        int d = min(ll(n), neg[i]);
        cur -= (neg[i] - d) * i;
        num += neg[i] - d;
    }
    for (int i = 0; i <= n; i++) {
        int d = min(ll(n), pos[i]);
        cur += (pos[i] - d) * i;
        num += pos[i] - d;
        if (-S / 2 < need - cur && need - cur < S / 2)
            res = max(res, num + f[need - cur]);
    }
    cur = num = 0;
    for (int i = 1; i <= n; i++) {
        int d = min(ll(n), pos[i]);
        cur += (pos[i] - d) * i;
        num += pos[i] - d;
    }
    for (int i = 0; i <= n; i++) {
        int d = min(ll(n), neg[i]);
        cur -= (neg[i] - d) * i;
        num += neg[i] - d;
        if (-S / 2 < need - cur && need - cur < S / 2)
            res = max(res, num + f[need - cur + S / 2]);
    }
    if (res < 0) cout << "impossible";
    else cout << res + zero;
}