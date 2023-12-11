#include <bits/stdc++.h>
using namespace std;

class modular{
public:
    using ll = long long; ll val;
    static const int mod = 1e9 + 7;

    modular(): val(0){}

    template <typename T>
    modular(T _val): val(_val % mod){
        if (val < 0) val += mod;
    }

    bool operator != (const modular &o){
        return val != o.val;
    }

    bool operator == (const modular &o){
        return val == o.val;
    }

    friend modular operator + (const modular &a, const modular &b){
        return modular(a.val + b.val);
    }

    friend modular operator - (const modular &a, const modular &b){
        return modular(a.val - b.val);
    }

    friend modular operator * (const modular &a, const modular &b){
        return modular(a.val * b.val);
    }

    friend void operator += (modular &a, const modular &b){
        a = modular(a.val + b.val);
    }

    friend void operator -= (modular &a, const modular &b){
        a = modular(a.val - b.val);
    }

    friend void operator *= (modular &a, const modular &b){
        a = modular(a.val * b.val);
    }

    template <class T>
    friend modular pow(const modular &a, const T &k){
        modular res = 1, x = a;
        for (T i = k; i > 0; i >>= 1){
            if (i & 1) res *= x; x = x * x;
        }
        return res;
    }

    friend modular inverse(const modular &a){
        return pow(a, modular::mod - 2);
    }

    friend modular operator / (const modular &a, const modular &b){
        return a * inverse(b);
    }

    friend void operator /= (modular &a, const modular &b){
        a = a * inverse(b);
    }

    friend istream& operator >> (istream &is, modular &a){
        modular::ll x; is >> x; a = modular(x); return is;
    }

    friend ostream& operator << (ostream &os, const modular &a){
        return os << a.val;
    }
};

const int N = 1e5 + 5;
const int base = 31;
char s[N], t[N]; int n, q, cnt[N], k;
modular hash_t[N], pow_t[N];

void build(){
    pow_t[0] = 1;
    for (int i = 1; i <= n; i++){
        hash_t[i] = hash_t[i - 1] * base + s[i] - 'a' + 1;
        pow_t[i] = pow_t[i - 1] * base;
    }
}

modular get_hash(int i, int j){
    return hash_t[j] - hash_t[i - 1] * pow_t[j - i + 1];
}

int query(){
    int m = strlen(t + 1);
    int lo = m, hi = n, mi, ans = -1;
    modular hasht;
    for (int i = 1; i <= m; i++)
        hasht = hasht * base + t[i] - 'a' + 1;
    while (lo <= hi){
        mi = (lo + hi) / 2; bool flag = false;
        for (int i = 1; i <= n; i++) cnt[i] = 0;
        for (int i = m; i <= n; i++)
            if (get_hash(i - m + 1, i) == hasht){
                cnt[max(i - mi + 1, 1)]++; cnt[i - m + 2]--;
            }
        for (int i = 1; i <= n; i++) cnt[i] += cnt[i - 1];
        for (int i = 1; i <= n; i++)
            if (cnt[i] >= k) flag = true;
        if (flag){
            ans = mi; hi = mi - 1;
        }
        else lo = mi + 1;
    }
    return ans;
}

int main(){
    scanf("%s%d", s + 1, &q); n = strlen(s + 1);
    build();
    while (q--){
        scanf("%d%s", &k, t + 1); printf("%d\n", query());
    }
}