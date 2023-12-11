/// https://www.codechef.com/problems/TREEQ1

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 1e5 + 5;

struct segmentTree {
    ll tr[N * 4], tg[N * 4];
    int lo, hi, n; ll res;

    void init(int n) {
        this->n = n;
        memset(tr, 0, sizeof tr);
        memset(tg, 0, sizeof tg);
    }

    void pushTag(int i, int l, int r, ll v) {
        tr[i] += v * (r - l + 1); tg[i] += v;
    }

    void update(int i, int l, int r, ll v) {
        if (l >= lo && r <= hi)
            return pushTag(i, l, r, v);
        int m = (l + r) / 2;
        pushTag(i * 2, l, m, tg[i]);
        pushTag(i * 2 + 1, m + 1, r, tg[i]);
        tg[i] = 0;
        if (m >= lo) update(i * 2, l, m, v);
        if (m < hi)
            update(i * 2 + 1, m + 1, r, v);
        tr[i] = tr[i * 2] + tr[i * 2 + 1];
    }

    void update(int l, int r, ll v) {
        lo = l; hi = r; update(1, 1, n, v);
    }

    void query(int i, int l, int r) {
        if (l >= lo && r <= hi)
            return void(res += tr[i]);
        int m = (l + r) / 2;
        pushTag(i * 2, l, m, tg[i]);
        pushTag(i * 2 + 1, m + 1, r, tg[i]);
        tg[i] = 0;
        if (m >= lo) query(i * 2, l, m);
        if (m < hi)
            query(i * 2 + 1, m + 1, r);
    }

    ll query(int l, int r) {
        if (l > r) return 0;
        lo = l; hi = r; res = 0;
        query(1, 1, n); return res;
    }

    int lb(int i, int l, int r, ll v) {
        if (l == r) return l;
        int m = (l + r) / 2;
        pushTag(i * 2, l, m, tg[i]);
        pushTag(i * 2 + 1, m + 1, r, tg[i]);
        tg[i] = 0;
        if (tr[i * 2] >= v)
            return lb(i * 2, l, m, v);
        return lb(i * 2 + 1,
        m + 1, r, v - tr[i * 2]);
    }

    int lb(int l, ll v) {
        v += query(1, l - 1);
        if (tr[1] < v) return -1;
        return lb(1, 1, n, v);
    }
};


int siz[N], par[N], wei[N];
int tin[N], tout[N], timer, cenPar[N];
vector <int> adj[N];
vector <int> child[N];
segmentTree ST; bool vis[N];
vector <int> cenCh[N];

void DFSpre(int u) {
    tin[u] = ++timer;
    for (int v : adj[u])
        if (v != par[u]) {
            par[v] = u; DFSpre(v);
        }
    tout[u] = timer;
}

ll getSum(int u) {
    return ST.query(tin[u], tout[u]);
}

void DFSsiz(int u, int p) {
    siz[u] = 1;
    for (int v : adj[u])
        if (v != p && !vis[v]) {
            DFSsiz(v, u);
            siz[u] += siz[v];
        }
}

int findCen(int u) {
    int p = 0, c = u;
    while (true) {
        bool flag = false;
        for (int v : adj[c])
            if (v != p && !vis[v] &&
            siz[v] * 2 > siz[u]) {
                p = c; c = v;
                flag = true; break;
            }
        if (flag) continue; break;
    }
    return c;
}

int DFScen(int u) {
    DFSsiz(u, 0); u = findCen(u);
    vis[u] = true;
    for (int v : adj[u])
        if (!vis[v]) {
            if (v == par[u])
                cenPar[u] = DFScen(v);
            else {
                cenCh[u].push_back(DFScen(v));
                child[u].push_back(v);
            }
        }
    return u;
}

int findAns(int u) {
    if (getSum(u) * 2 == getSum(1))
        return min(par[u], u);
    ll half = (getSum(1) + 1) / 2;
    if (getSum(u) >= half) {
        if (!child[u].size()) return u;
        int p = ST.lb(tin[u] + 1, half);
        if (p < 0 || p > tout[u]) return u;
        int l = 0, r = child[u].size() - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (tout[child[u][m]] >= p)
                r = m;
            else l = m + 1;
        }
        int v = child[u][r];
        if (getSum(v) >= half)
            return findAns(cenCh[u][r]);
        return u;
    }
    else return findAns(cenPar[u]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> wei[i];
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFSpre(1); ST.init(n);
    int root = DFScen(1); 
    for (int i = 1; i <= n; i++)
        ST.update(tin[i], tin[i], wei[i]);
    while (q--) {
        int cmd, u, w;
        cin >> cmd >> u >> w;
        if (cmd == 1)
            ST.update(tin[u], tin[u], w);
        else ST.update(tin[u], tout[u], w);
        cout << findAns(root) << '\n';
    }
}