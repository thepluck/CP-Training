#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MAXN = 1e15 + 5;

ll DP[45][85][45][2], fib[85], N, K;
bool dgt[85];

ll calc(int pos, int cnt, bool last, bool tight) {
    if (!pos) return cnt >= K ? cnt : 0;
    if (tight && DP[K][pos][cnt][last] >= 0)
        return DP[K][pos][cnt][last];
    ll res = 0;
    if (!last && (tight || (!tight && dgt[pos])))
        res += calc(pos - 1, cnt + 1, 1, tight);
    res += calc(pos - 1, cnt, 0, tight || dgt[pos]);
    if (tight) DP[K][pos][cnt][last] = res;
    return res;
}

void solve() {
    cin >> N >> K;
    if (K >= 40) return void(cout << "0\n");
    for (int i = 79; i > 0; i--)
        if (N >= fib[i]) {
            N -= fib[i]; dgt[i] = 1;
        } else dgt[i] = 0;
    cout << calc(79, 0, 0, 0) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    fib[0] = 1; fib[1] = 1;
    for (int i = 2; i < 80; i++)
        fib[i] = min(MAXN, fib[i - 1] + fib[i - 2]);
    memset(DP, -1, sizeof DP);
    int T; cin >> T;
    while (T--) solve();
}
