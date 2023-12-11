#include "walk.h"
#include <vector>
#include <array>
#include <iostream>

namespace {

    using namespace std;

    using ll = long long;

    const int S = 123;
    const ll K = 1e18 + 100;
    const int LOG = 64;

    using mat = array<array<ll, S>, S>;

    ll mul(ll x, ll y) {
        if (!x || !y) return 0;
        return x <= K / y ? x * y : K;
    }

    ll add(ll x, ll y) {
        return x <= K - y ? x + y : K;
    }

    mat mul(mat a, mat b) {
        mat c;
        for (int i = 0; i < S; i++)
            for (int j = 0; j < S; j++) {
                c[i][j] = 0;
                for (int k = 0; k < S; k++)
                    c[i][j] = add(c[i][j],
                    mul(a[i][k], b[k][j]));
            }
        return c;
    }

    mat val[LOG];
}

ll find_best_walk(int n, ll k,
vector<int> a, vector<int> b, vector<int> w) {
    for (int i = 0; i < S; i++)
        for (int j = 0; j < S; j++)
            val[0][i][j] = 0;
    for (int i = 0; i < a.size(); i++) {
        if (w[i] == 2) {
            val[0][a[i]][a[i] + n] = 1;
            val[0][a[i] + n][b[i]]++;
        } else if (w[i] == 3) {
            val[0][a[i]][a[i] + n] = 1;
            val[0][a[i] + n][b[i] + n * 2]++;
            val[0][b[i] + n * 2][b[i]] = 1;
        } else val[0][a[i]][b[i]]++;
    }
    for (int i = 0; i < n; i++)
        val[0][i][3 * n]++;
    val[0][3 * n][3 * n]++;
    for (int i = 1; i < LOG; i++)
        val[i] = mul(val[i - 1], val[i - 1]);
    ll res = 0; array<ll, S> cur, nxt;
    for (int i = 0; i < S; i++)
        cur[i] = 0;
    for (int i = 0; i < n; i++)
        cur[i] = 1;
    k += n;
    for (int b = LOG - 1; b >= 0; b--) {
        for (int i = 0; i < S; i++)
            nxt[i] = 0;
        for (int i = 0; i < S; i++)
            for (int j = 0; j < S; j++)
                nxt[j] = add(nxt[j], mul
                (cur[i], val[b][i][j]));
        if (b == LOG - 1 && nxt[3 * n] < k)
            return -1;
        if (nxt[3 * n] < k) {
            res += 1ll << b; swap(cur, nxt);
        }    
    }
    return res;
}
