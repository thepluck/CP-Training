#include <bits/stdc++.h>
using namespace std;

int mod[200], mark[200];

long long mpow(long long x, long long k, int mod) {
    long long res = 1;
    for (; k; k >>= 1, x = x * x % mod)
        if (k & 1) res = res * x % mod;
    return res;
}

int main() {
    //freopen("game.inp", "r", stdin);
    //freopen("game.out", "w", stdout);
    long long n, k; cin >> k >> n;
    long long res = 0;
    for (int i = 0; i <= min(n, 99ll); i++) {
        int x = 1, fi, se;
        memset(mark, 0, sizeof mark);
        mod[0] = 1;
        for (int j = 1; j <= 100; j++) {
            x = x * i % 100;
            if (mark[x]) {
                fi = mark[x];
                se = j; break;
            }
            mark[x] = j; mod[j] = x;
        }
        int num = ((n - i) / 100 + 1) % 100;
        if (k <= 10 && (1 << k) < fi) {
            res += num * mod[1 << k];
            res %= 100;
        }
        else {
            int tmp = mod[fi];
            int cc = mpow(2, k, se - fi);
            cc -= fi;
            while (cc < 0) cc += se - fi;
            tmp = tmp * mod[cc] % 100;
            res += num * tmp;
            res %= 100;
        }
    }
    cout << res << '\n';
}
