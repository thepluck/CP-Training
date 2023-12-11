
// Problem : F. Graph and Queries
// Contest : Codeforces - Codeforces Round #673 (Div. 2)
// URL : https://codeforces.com/contest/1417/problem/F
// Memory Limit : 256 MB
// Time Limit : 1500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define eb emplace_back

using ii = pair <int, int>;

const int N = 2e5 + 5;
const int M = 3e5 + 5;

set <int> val[N];
vector <int> cmp[N];
int p[N], a[N], r[M];
ii qr[N + M], ed[M];
bool era[M];

void add(int i) {
    int u = p[ed[i].fi];
    int v = p[ed[i].se];
    if (u == v) return;
    if (cmp[u].size() < cmp[v].size())
        swap(u, v);
    r[i] = v;
    for (int w : cmp[v]) {
        p[w] = u; cmp[u].eb(w);
    }
}

void roll(int i) {
    if (!r[i]) return;
    int u = p[ed[i].fi], v = r[i];
    for (int w : cmp[v]) {
        p[w] = v;
        if (val[u].count(a[w])) {
            val[u].erase(a[w]);
            val[v].insert(a[w]);
        }
        cmp[u].pop_back();
    }
}
void query(int u) {
    u = p[u];
    if (val[u].empty()) {
        cout << "0\n"; return;
    }
    int res = *val[u].rbegin();
    val[u].erase(res);
    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; p[i] = i;
        cmp[i].eb(i);
    }
    for (int i = 1; i <= m; i++)
        cin >> ed[i].fi >> ed[i].se;
    for (int i = 1; i <= q; i++) {
        cin >> qr[i].se >> qr[i].fi;
        if (qr[i].se == 2)
            era[qr[i].fi] = 1;
    }
    for (int i = 1; i <= m; i++)
        if (!era[i]) add(i);
    for (int i = q; i > 0; i--)
        if (qr[i].se == 2)
            add(qr[i].fi);
    for (int i = 1; i <= n; i++)
        val[p[i]].insert(a[i]);
    for (int i = 1; i <= q; i++)
        if (qr[i].se == 1)
            query(qr[i].fi);
        else roll(qr[i].fi);
}