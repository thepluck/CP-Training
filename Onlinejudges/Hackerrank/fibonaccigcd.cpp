#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int DIV = 5e8 + 4;

struct item {
    int a, b;

    item(int a, int b): a(a), b(b) {}

    item& operator += (const item &o) {
        if ((a + o.a) >= MOD) a -= MOD;
        if ((b + o.b) >= MOD) b -= MOD;
        return *this;
    }

    item operator + (const item &o) const {
        return item(*this) += o;
    }

    item& operator *= (const item &o) {
        int t = a;
        a = (ll(a) * o.a + 5ll * b * o.b) % MOD;
        b = (ll(t) * o.b + ll(b) * o.a) % MOD;
        return *this;
    }

    item operator * (const item &o) const {
        return item(*this) *= o;
    }
};

item pow(item x, ll k) {
    item res(1, 0);
    for (; k; k >>= 1, x = x * x)
        if (k & 1) res = res * x;
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n; ll g = 0;
    while (n--) {
        ll x; cin >> x;
        g = __gcd(x, g);
    }
    cout << pow(item(DIV, DIV), g).b * 2 % MOD << '\n';
}