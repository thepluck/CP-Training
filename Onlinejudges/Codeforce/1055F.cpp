
// Problem : F. Tree and XOR
// Contest : Codeforces - Mail.Ru Cup 2018 Round 2
// URL : https://codeforces.com/contest/1055/problem/F
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e6 + 5;
const int LG = 62;

struct node {
    int ch[2], cn;
    
    node() {
        ch[0] = ch[1] = cn = 0;
    }
} cur[N], nxt[N];

ll w[N];
int pos[N], opt[N], sz;
vector <int> adj[N];

int ch(int i, bool b, bool f = 0) {
    if (!f && !cur[i].ch[b]) {
        cur[i].ch[b] = sz;
        nxt[sz++] = node();
    }
    return cur[i].ch[b];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; ll k; cin >> n >> k;
    for (int i = 2; i <= n; i++) {
        int j; cin >> j >> w[i];
        w[i] ^= w[j];
    }
    ll res = 0;
    for (int b = LG - 1; ~b; b--) {
        sz = 2; ll cnt = 0;
        nxt[0] = nxt[1] = node();
        for (int i = 1; i <= n; i++) {
            pos[i] = ch(pos[i], w[i] >> b & 1);
            nxt[pos[i]].cn++;
        }
        for (int i = 1; i <= n; i++)
            cnt += nxt[ch(opt[i], w[i] >> b & 1, 1)].cn;
        if (cnt < k) {
            res ^= 1ll << b; k -= cnt;
            for (int i = 1; i <= n; i++)
                opt[i] = ch(opt[i], !(w[i] >> b & 1), 1);
            }
        else {
            for (int i = 1; i <= n; i++)
                opt[i] = ch(opt[i], w[i] >> b & 1, 1);
        }
        swap(nxt, cur);
    }
    cout << res << '\n';
}