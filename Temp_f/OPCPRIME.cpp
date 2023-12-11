#include <bits/stdc++.h>
using namespace std;

namespace prime_test{
    using ll = long long;
    using ull = unsigned long long;
    #define ctz __builtin_ctzll
    int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

    ull mod_plus(ull a, ull b, ull mod){
        a %= mod; b %= mod;
        return a < mod - b ? a + b : a - mod + b;
    }

    ull mod_mul(ull a, ull b, ull mod){
        ll res = 0; a %= mod; b %= mod;
        for (; b > 0; b >>= 1){
            if (b & 1) res = mod_plus(res, a, mod);
            a = mod_plus(a, a, mod);
        }
        return res;
    }

    ull mod_pow(ull x, ull k, ull mod){
        ll res = 1;
        for (; k > 0; k >>= 1){
            if (k & 1) res = mod_mul(res, x, mod);
            x = mod_mul(x, x, mod);
        }
        return res;
    }

    bool witness(int s, ull d, ull a, ull p){
        if (a == p) return true;
        ull wit = mod_pow(p, d, a);
        if (wit == 1) return true;
        for (; s > 0; s--){
            if (wit == a - 1) return true;
            wit = mod_mul(wit, wit, a);
        }
        return false;
    }

    bool miller(ull a){
        int s = ctz(a - 1); ull d = (a - 1) >> s;
        for (int p : prime)
            if (a == p) return true;
            else if (!witness(s, d, a, p)) return false;
        return true;
    }
}

using namespace prime_test;

void solve(ull a){
    if (miller(a)){
        printf("%llu", a); return;
    }
    int k = ctz(a);
    if (k > 0){
        puts("2"); a >>= k;
    }
    for (ull i = 3; i <= a; i += 2){
        if (a % i == 0){
            printf("%llu\n", i);
            while (a % i == 0) a /= i;
        }
    }
}

int main(){
    ull a; while (scanf("%llu", &a) == 1) solve(a);
}