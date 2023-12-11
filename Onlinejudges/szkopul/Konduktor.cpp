#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

using ii = pair <int, int>;

const int MAXN = 500005;
const int MOD = 1000000007;

ii BIT[MAXN * 2]; int M, N;

int add(int x, int y) {
    if ((x += y) >= MOD) x -= MOD;
    return x;
}

int mul(int x, int y) {
    return (long long)x * y % MOD;
}

ii add(ii x, ii y) {
    if (x.fi != y.fi) return min(x, y);
    x.se = add(x.se, y.se); return x;
}

void add(int i, ii v) {
    for (; i > 0; i -= i & -i)
        BIT[i] = add(BIT[i], v);
}

ii get(int i) {
    ii res(INT_MAX, 0);
    for (; i <= 2 * N; i += i & -i)
        res = add(res, BIT[i]);
    return res;
}

void solve() {
    cin >> M >> N;
    vector <int> X(1, 0);
    vector <ii> S;
    for (int i = 1; i <= 2 * N; i++)
        BIT[i] = {INT_MAX, 0};
    for (int i = 0; i < N; i++) {
        int l, r; cin >> l >> r;
        S.emplace_back(l, r);
        X.push_back(l); X.push_back(r);
    }
    sort(S.begin(), S.end(), [](ii x, ii y) {
        return x.se < y.se;
    });
    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    add(1, {0, 1}); int lim = 0;
    for (int i = 1, j = 0; i < X.size(); i++) {
        while (j < S.size() && S[j].se <= X[i])
            lim = max(lim, S[j++].fi);
        auto res = get(upper_bound
        (X.begin(), X.end(), lim) - X.begin());
        if (i == X.size() - 1)
            cout << res.fi << ' ' << res.se << '\n';
        else add(i + 1, {res.fi + 1,
            mul(res.se, X[i + 1] - X[i])});
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}