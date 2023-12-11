// Problem: C. Sasha and Array
// Contest: Codeforces - Codeforces Round #373 (Div. 1)
// URL: https://codeforces.com/contest/718/problem/C
// Memory Limit: 256 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;
const int INV2 = 500000004;
const int N = 100005;

int add(int x, int y) {
    if ((x += y) >= MOD) x -= MOD;
    return x;
}

int mul(int x, int y) {
    return (long long)x * y % MOD;
}

int sub(int x, int y) {
    if ((x -= y) < 0) x += MOD;
    return x;
}

/// numbers in Z[sqrt(5)] field
struct number {
    int a, b;
    
    number(int a = 0, int b = 0): a(a), b(b) {}
    
    number& operator += (const number &o) {
        a = add(a, o.a); b = add(b, o.b);
        return *this;
    }
    
    number& operator -= (const number &o) {
        a = sub(a, o.a); b = sub(b, o.b);
        return *this;
    }
    
    number& operator *= (const number &o) {
        return *this =
        {add(mul(a, o.a), mul(5, mul(b, o.b))),
        add(mul(b, o.a), mul(a, o.b))};
    }
    
    number operator + (const number &o) const {
        return number(*this) += o;
    }
    
    number operator - (const number &o) const {
        return number(*this) -= o;
    }
    
    number operator * (const number &o) const {
        return number(*this) *= o;
    }
};

const number root(INV2, INV2);

number pw[4][(1 << 16) + 5];

number powRoot(long long k) {
    number res(1, 0);
    for (int i = 0; i < 4; i++) {
        res *= pw[i][k & ((1 << 16) - 1)];
        k >>= 16;
    }
    return res;
}

struct segTree {
    vector <number> val; number res;
    vector <long long> tag; int n, lo, hi;
    
    void build(int i, int l, int r) {
        val[i] = {r - l + 1, 0};
        if (l != r) {
            int m = (l + r) / 2;
            build(i * 2, l, m);
            build(i * 2 + 1, m + 1, r);
        }
    }
    
    void pushTag(int i, long long v) {
        val[i] *= powRoot(v); tag[i] += v;
    }
    
    void pushDown(int i) {
        pushTag(i * 2, tag[i]);
        pushTag(i * 2 + 1, tag[i]);
        tag[i] = 0;
    }
    
    void add(int i, int l, int r, int v) {
        if (l >= lo && r <= hi)
            return pushTag(i, v);
        pushDown(i); int m = (l + r) / 2;
        if (m >= lo) add(i * 2, l, m, v);
        if (m < hi) add(i * 2 + 1, m + 1, r, v);
        val[i] = val[i * 2] + val[i * 2 + 1];
    }
    
    void get(int i, int l, int r) {
        if (l >= lo && r <= hi)
            return void(res += val[i]);
        pushDown(i); int m = (l + r) / 2;
        if (m >= lo) get(i * 2, l, m);
        if (m < hi) get(i * 2 + 1, m + 1, r);
    }
    
    void add(int l, int r, int v) {
        lo = l; hi = r; add(1, 1, n, v);
    }
    
    int get(int l, int r) {
        lo = l; hi = r;
        res = {0, 0}; get(1, 1, n);
        return ::add(res.b, res.b);
    }
    
    segTree(int n): n(n), val(4 * n), tag(4 * n) {
        build(1, 1, n);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    number pwroot = root;
    for (int i = 0; i < 4; i++) {
        pw[i][0] = {1, 0};
        for (int j = 1; j < (1 << 16); j++)
            pw[i][j] = pw[i][j - 1] * pwroot;
        for (int j = 0; j < 16; j++)
            pwroot *= pwroot;
    }
    int n, q; cin >> n >> q;
    segTree ST(n);
    for (int i = 1; i <= n; i++) {
        int v; cin >> v; ST.add(i, i, v);
    }
    while (q--) {
        int cmd, l, r; cin >> cmd >> l >> r;
        if (cmd == 1) {
            int v; cin >> v; ST.add(l, r, v);
        }
        else cout << ST.get(l, r) << '\n';
    }
}