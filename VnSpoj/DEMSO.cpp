#include <bits/stdc++.h>
using namespace std;

using ll = unsigned long long;
using ci = const int&;
ll f[17][10][16][2], g[17][10][16];
int n, k, digit[17], d;
ll go1(ci i, ci dgt, ci npos, bool gr, ci ndgt){
    ll &res = f[i][dgt][npos][gr];
    if (res != -1) return res;
    if (npos > k) return res = 0;
    if (i == ndgt) return res = 1;
    int lim = gr ? digit[i + 1] : 9; res = 0;
    for (int nxt_dgt = 0; nxt_dgt <= lim; nxt_dgt++){
        int _npos = npos + (abs(dgt - nxt_dgt) <= d);
        bool _gr = gr && nxt_dgt == digit[i + 1];
        res += go1(i + 1, nxt_dgt, _npos, _gr, ndgt);
    }
    return res;
}

ll go2(ci i, ci dgt, ci npos, ci ndgt){
    if (ndgt == 0) return 0;
    ll &res = g[i][dgt][npos];
    if (res != -1) return res; res = 1;
    if (npos > k) return res = 0;
    if (i == ndgt) return res;
    for (int nxt_dgt = 0; nxt_dgt <= 9; nxt_dgt++){
        int _npos = npos + (abs(dgt - nxt_dgt) <= d);
        res += go2(i + 1, nxt_dgt, _npos, ndgt);
    }
    return res;
}

ll calc(ll x){
    memset(f, -1, sizeof(ll) * 17 * 10 * 16 * 2);
    memset(g, -1, sizeof(ll) * 17 * 10 * 16);
    if (x == 0) return 0;
    int cnt = 0;
    while (x > 0){
        digit[++cnt] = x % 10; x /= 10;
    }
    reverse(digit + 1, digit + 1 + cnt);
    ll res = 0; 
    for (int i = 1; i < digit[1]; i++)
        res += go1(1, i, 0, 0, cnt);
    res += go1(1, digit[1], 0, 1, cnt);
    for (int i = 1; i <= 9; i++)
        res += go2(1, i, 0, cnt - 1);
    return res;
}

int main(){
    ll a, b; cin >> a >> b >> d >> k;
    cout << calc(b) - calc(a - 1) << '\n';
}
