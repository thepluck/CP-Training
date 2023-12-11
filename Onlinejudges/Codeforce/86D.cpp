
// Problem : D. Powerful array
// Contest : Codeforces - Yandex.Algorithm 2011: Round 2
// URL : https://codeforces.com/contest/86/problem/D
// Memory Limit : 256 MB
// Time Limit : 5000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5 + 5;
const int V = 1e6 + 5;
const int LG = 18;

ll hilbert(int l, int r) {
    ll ord = 0;
    for (int s = 1 << LG; s >>= 1; ) {
        bool ll = l & s, rr = r & s;
        ord = ord << 2 | ll * 3 ^ rr;
        if (!rr) {
            if (ll) {
                l = (1 << LG) - l;
                r = (1 << LG) - r;
            }
            swap(l, r);
        }
    }
    return ord;
}

struct query {
    int l, r, id; ll ord;
    
    query() {}
    
    query(int l, int r, int id):
    l(l), r(r), id(id), ord(hilbert(l, r)) {}
    
    bool operator < (const query &o) const {
        return ord < o.ord;
    }
};

int a[N], c[V];
query que[N]; ll ans[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= q; i++) {
        int l, r; cin >> l >> r;
        que[i] = query(l, r, i);
    }
    sort(que + 1, que + q + 1);
    int l = 0, r = -1; ll cur = 0;
    for (int i = 1; i <= q; i++) {
        while (l > que[i].l) {
            l--;
            cur += (2ll * c[a[l]] + 1) * a[l];
            c[a[l]]++;
        }
        while (r < que[i].r) {
            r++;
            cur += (2ll * c[a[r]] + 1) * a[r];
            c[a[r]]++;
        }
        while (l < que[i].l) {
            c[a[l]]--;
            cur -= (2ll * c[a[l]] + 1) * a[l];
            l++;
        }
        while (r > que[i].r) {
            c[a[r]]--;
            cur -= (2ll * c[a[r]] + 1) * a[r];
            r--;
        }
        ans[que[i].id] = cur;
    }
    for (int i = 1; i <= q; i++)
        cout << ans[i] << '\n';
}