#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

using ll = long long;

const int N = 2e5 + 5;

int n, x, y; bool ban[N];
vector <int> adj[N]; ll res = 0;
int val[N], siz[N], BIT[N], cnt;
vector <pair <int, ll>> cur1, cur2;

void add(int i) {
    for (; i <= cnt; i += i & -i)
        BIT[i]++;
}

int get(int i) {
    int ans = 0;
    for (; i > 0; i -= i & -i)
        ans += BIT[i];
    return ans;
}

void DFS1(int u, int p) {
    siz[u] = 1;
    for (int v : adj[u])
        if (v != p && !ban[v]) {
            DFS1(v, u);
            siz[u] += siz[v];
        }
}

int findCen(int u) {
    int c = u, p = 0;
    while (true) {
        bool flag = false;
        for (int v : adj[c])
            if (v != p && !ban[v] &&
            siz[v] * 2 >= siz[u]) {
                p = c; c = v;
                flag = true; break;
            }
        if (!flag) break;
    }
    return c;
}

ll calc(vector <pair <int, ll>> &a,
vector <pair <int, ll>> &b) {
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    vector <ll> rar;
    ll ans = 0;
    for (auto pp : b)
        rar.push_back(-pp.se);
    sort(rar.begin(), rar.end());
    rar.erase(unique(rar.begin(),
    rar.end()), rar.end());
    cnt = a.size();
    for (int i = 1; i <= cnt; i++) BIT[i] = 0;
    for (int i = 0, j = 0; i < cnt; i++) {
        while (j < cnt && a[i].fi + b[j].fi >= 0) {
            int id = upper_bound(rar.begin(),
            rar.end(), -b[j].se) - rar.begin();
            add(id); j++;
        }
        int id = upper_bound(rar.begin(),
        rar.end(), a[i].se) - rar.begin();
        ans += get(id);
    }
    return ans;
}

void DFS2(int u, int p, int a, ll b) {
    a += 2 * (val[u] <= x) - 1;
    b += val[u] - y;
    cur1.emplace_back(a, b);
    for (int v : adj[u])
        if (v != p && !ban[v])
            DFS2(v, u, a, b);
}

void DFS3(int u) {
    DFS1(u, 0); ban[u = findCen(u)] = 1;
    vector <pair <int, ll>> tot1, tot2;
    int a = 2 * (val[u] <= x) - 1;
    ll b = val[u] - y;
    tot1.emplace_back(0, 0);
    tot2.emplace_back(a, b);
    for (int v : adj[u])
        if (!ban[v]) {
            cur1.clear(); cur2.clear();
            DFS2(v, u, 0, 0);
            for (auto pp : cur1) {
                cur2.emplace_back
                (pp.fi + a, pp.se + b);
                tot1.push_back(pp);
                tot2.emplace_back
                (pp.fi + a, pp.se + b);
            }
            res -= calc(cur1, cur2);
        }
    res += calc(tot1, tot2);
    if (a >= 0 && b >= 0) res++;
    for (int v : adj[u])
        if (!ban[v]) DFS3(v);
}

int main() {
    freopen("mean-median.inp", "r", stdin);
    freopen("mean-median.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> n >> x >> y;
    for (int i = 1; i <= n; i++)
        cin >> val[i];
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS3(1);
    cout << (res / 2) % 998244353 << '\n';
}