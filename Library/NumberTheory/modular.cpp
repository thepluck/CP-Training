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

using mint = modular <1000000007>;

int main() {
    mint a, b; cin >> a >> b;
    cout << a / b << '\n';
    cerr << pow(a, 58) << '\n';
;}