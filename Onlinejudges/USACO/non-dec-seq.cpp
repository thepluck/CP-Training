
// Problem : Problem 2. Non-Decreasing Subsequences
// Contest : USACO - USACO 2020 January Contest, Platinum
// URL : http://www.usaco.org/index.php?page=viewproblem2&cpid=997
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template <class T>
T inverse(T a, T m) {
    T u = 0, v = 1;
    while (a != 0) {
        T t = m / a;
        m -= t * a; swap(a, m);
        u -= t * v; swap(u, v);
    }
    return u;
}

template <int MOD>
struct modular {
    int v;
    
    modular(): v(0) {}
    
    template <class T>
    modular(T v): v(v % MOD) {
        if (this->v < 0) this->v += MOD;
    }
    
    modular operator - () const {
        return modular() - *this;
    }
    
    modular& operator += (const modular &o) {
        if ((v += o.v) >= MOD) v -= MOD;
        return *this;
    }
    
    modular& operator -= (const modular &o) {
        if ((v -= o.v) < 0) v += MOD;
        return *this;
    }
    
    modular& operator *= (const modular &o) {
        v = ll(v) * o.v % MOD;
        return *this;
    }
    
    modular& operator /= (const modular &o) {
        v = ll(v) * inverse(o.v, MOD) % MOD;
        return *this;
    }
    
    bool operator == (const modular &o) const {
        return v == o.v;
    }
    
    bool operator != (const modular &o) const {
        return v != o.v;
    }
    
    modular operator + (const modular &o) const {
        return modular(*this) += o;
    }
    
    modular operator - (const modular &o) const {
        return modular(*this) -= o;
    }
    
    modular operator * (const modular &o) const {
        return modular(*this) *= o;
    }
    
    modular operator / (const modular &o) const {
        return modular(*this) /= o;
    }
};

template <int MOD>
istream& operator >> (istream &is, modular <MOD> &o) {
    ll v; is >> v; o.v = v;
    if ((o.v %= MOD) < 0) o.v += MOD;
    return is;
}

template <int MOD>
ostream& operator << (ostream &os, const modular <MOD> &o) {
    return os << o.v;
}

template <int MOD, class T>
modular <MOD> pow(modular <MOD> x, T k) {
    modular <MOD> res(1);
    for (; k; k >>= 1, x *= x)
        if (k & 1) res *= x;
    return res;
}

const int N = 50005;
const int K = 20;
const int MOD = 1e9 + 7;

using mint = modular <MOD>;

array <mint, 20> sto[N], isto[N];
mint inv((MOD + 1) / 2);

int main() {
    //freopen("nondec.in", "r", stdin);
    //freopen("nondec.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    array <array <mint, K>, K> cr, icr;
    for (int i = 0; i < m; i++)
        cr[i][i] = icr[i][i] = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < m; j++)
            for (int k = 0; k < m; k++)
                sto[i][j] += cr[j][k];
        for (int j = 0; j < m; j++)
            isto[i][j] = icr[0][j];
        if (i == n) break;
        int x; cin >> x; x--;
        for (int j = 0; j <= x; j++)
            for (int k = x; k >= j; k--)
                cr[j][x] += cr[j][k];
        for (int j = 0; j < x; j++)
            for (int k = x; k < m; k++)
                icr[j][k] -= inv * icr[x][k];
        for (int j = x; j < m; j++)
            icr[x][j] *= inv;
    }
    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        mint ans = 0;
        for (int j = 0; j < m; j++)
            ans += isto[l - 1][j] * sto[r][j];
        cout << ans << '\n';
    }

}
