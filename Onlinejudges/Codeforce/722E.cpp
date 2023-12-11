#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

const int N = 200005;
const int MOD = 1000000007;

int fac[N], ifac[N];

int mul(int x, int y) {
    return (long long)x * y % MOD;
}

int add(int x, int y) {
    return (x += y) >= MOD ? x - MOD : x;
}

int sub(int x, int y) {
    return (x -= y) < 0 ? x + MOD : x;
}

int bin(int n, int k) {
    return mul(fac[n], mul(ifac[k], ifac[n - k]));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    fac[0] = ifac[0] = ifac[1] = 1;
    for (int i = 2; i < N; i++)
        ifac[i] = MOD - mul(ifac[MOD % i], MOD / i);
    for (int i = 1; i < N; i++) {
        fac[i] = mul(fac[i - 1], i);
        ifac[i] = mul(ifac[i - 1], ifac[i]);
    }
    int r, c, k, s;
    cin >> r >> c >> k >> s;
    bool src = false, dest = false;
    vector<pair<int, int>> cells(k);
    for (auto &cell : cells) {
        cin >> cell.fi >> cell.se;
        if (cell.fi == 1 && cell.se == 1)
            src = true;
        if (cell.fi == r && cell.se == c)
            dest = true;
    }
    if (src) s = (s + 1) >> 1;
    else {
        cells.emplace_back(1, 1); k++;
    }
    if (dest) s = (s + 1) >> 1;
    else {
        cells.emplace_back(r, c); k++;
    }
    sort(cells.begin(), cells.end());
    vector<int> prv(k), cur(k); prv[0] = 1;
    vector<int> sum = prv;
    int res = bin(r + c - 2, r - 1);
    while (s > 1) {
        for (int i = 0; i < k; i++) {
            cur[i] = sub(bin(cells[i].fi + cells[i].se - 2, cells[i].fi - 1), sum[i]);
            for (int j = 0; j < i; j++)
                if (cells[i].fi >= cells[j].fi && cells[i].se >= cells[j].se)
                    cur[i] = sub(cur[i], mul(cur[j], bin(cells[i].fi - cells[j].fi
                    + cells[i].se - cells[j].se, cells[i].fi - cells[j].fi)));
        }
        for (int i = 0; i < k; i++) {
            prv[i] = cur[i]; sum[i] = add(sum[i], prv[i]);
        }
        res = add(res, mul(prv.back(), s - 1));
        s = (s + 1) >> 1;
    }
    cout << mul(res, mul(fac[r - 1], mul(fac[c - 1], ifac[r + c - 2])));
}