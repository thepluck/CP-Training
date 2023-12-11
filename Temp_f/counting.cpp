//http://lqdoj.edu.vn/problem/demso
#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define fi first
#define se second

using ll = long long;
using ii = pair <int, int>;

const int MOD = 1e9 + 7;

ii dp[20][5433][181];
int wb[10], pw[20]; 
bool cc[5433][181];
vector <int> dgt;

int madd(int x, int y) {
    if ((x += y) >= MOD) x -= MOD;
    return x;
}

int msub(int x, int y) {
    if ((x -= y) < 0) x += MOD;
    return x;
}

int mmul(int x, int y) {
    return ll(x) * y % MOD;
}

ii rec(int i, int s1, int s2, bool l) {
    if (i == -1) return {0, cc[s1][s2]};
    if (l && dp[i][s1][s2] != ii(-1, 0))
        return dp[i][s1][s2];
    ii res;
    for (int d = 0; d < 10; d++) {
        if (!l && d > dgt[i]) continue;
        ii nxt = rec(i - 1, s1 + wb[d],
        s2 + d, l | (d < dgt[i]));
        res.se = madd(res.se, nxt.se);
        res.fi = madd(res.fi, madd(nxt.fi,
        mmul(nxt.se, mmul(d, pw[i]))));
    }
    if (l) dp[i][s1][s2] = res;
    return res;
}

int cal(ll x) {
    dgt.clear();
    for (; x; x /= 10) dgt.eb(x % 10);
    return rec(dgt.size() - 1, 0, 0, 0).fi;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    pw[0] = 1;
    for (int i = 1; i < 10; i++)
        wb[i] = wb[i - 1] + i * i;
    for (int i = 1; i <= 18; i++)
        pw[i] = mmul(pw[i - 1], 10);
    for (int i = 1; i < 5433; i++)
        for (int j = 1; j < 181; j++)
            cc[i][j] = __gcd(i, j) == 1;
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 5433; j++)
            for (int k = 0; k < 181; k++)
                dp[i][j][k] = ii(-1, 0);
    int q; cin >> q;
    while (q--) {
        ll l, r; cin >> l >> r;
        cout << msub(cal(r), cal(l - 1)) << '\n';
    }
}