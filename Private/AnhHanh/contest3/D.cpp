#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100020;
const int MOD = 1000000007;
const int MAXSIZ = 1e7;

struct node {
    int cnt, val, lef, rig;

    node(): cnt(0), val(0), lef(0), rig(0) {}
};

int N, M, S, T;

int par[MAXN], root[MAXN], pow2[MAXN];

node tree[MAXSIZ]; int siz;

int &cnt(int x) {
    return tree[x].cnt;
}

int &val(int x) {
    return tree[x].val;
}

int &lef(int x) {
    return tree[x].lef;
}

int &rig(int x) {
    return tree[x].rig;
}

int add(int x, int y) {
    if ((x += y) >= MOD) x -= MOD;
    return x;
}

bool comp(int x, int y, int l, int r) {
    if (l == r) return cnt(x) > cnt(y);
    int m = (l + r) / 2;
    if (val(rig(x)) == val(rig(y)))
        return comp(lef(x), lef(y), l, m);
    return comp(rig(x), rig(y), m + 1, r);
}

bool comp(int x, int y) {
    return comp(x, y, 0, MAXN);
}

bool add(int x, int &y, int l, int r, int p) {
    y = ++siz; tree[y] = tree[x];

    if (l >= p && cnt(x) == r - l + 1) {
        tree[y] = node(); return 1;
    }

    if (l == r) {
        cnt(y) = 1; val(y) = pow2[l]; return 0;
    }

    bool ans = 0; int m = (l + r) / 2;

    if (m >= p) {
        if (add(lef(x), lef(y), l, m, p))
            ans = add(rig(x), rig(y), m + 1, r, m + 1);
    } else ans = add(rig(x), rig(y), m + 1, r, p);

    cnt(y) = cnt(lef(y)) + cnt(rig(y));
    val(y) = add(val(lef(y)), val(rig(y)));

    return ans;
}

struct edge {
    int v, x;

    edge(int v, int x): v(v), x(x) {}

    bool operator < (const edge &o) const {
        return comp(x, o.x);
    }
};

vector <edge> adj[MAXN];
vector <int> path;

void trace(int u) {
    path.push_back(u);
    if (u != S) trace(par[u]);
}

void answer() {
    trace(T);
    cout << val(root[T]) << '\n';
    cout << path.size() << '\n';

    while (path.size()) {
        cout << path.back() << ' ';
        path.pop_back();
    }
    exit(0);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;

    pow2[0] = 1;
    for (int i = 1; i < MAXN; i++)
        pow2[i] = add(pow2[i - 1], pow2[i - 1]);

    for (int i = 0; i < M; i++) {
        int u, v, x; cin >> u >> v >> x;
        adj[u].emplace_back(v, x);
        adj[v].emplace_back(u, x);
    }

    cin >> S >> T; int tmp;

    priority_queue <edge> pq;
    pq.emplace(S, root[S] = ++siz);

    while (pq.size()) {
        auto p = pq.top(); pq.pop();
        if (p.x != root[p.v]) continue;
        if (p.v == T) answer();
        for (auto e : adj[p.v]) {
            add(p.x, tmp, 0, MAXN, e.x);
            if (!root[e.v] || comp(root[e.v], tmp)) {
                root[e.v] = tmp; par[e.v] = p.v;
                pq.emplace(e.v, root[e.v]);
            }
        }
    }
    cout << "-1\n";
}