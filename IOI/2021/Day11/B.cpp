#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

struct SplayTree {
    struct Node {
        int ch[2] = {0, 0}, p = 0;
        bool flip = 0;
    };
    vector<Node> T;

    SplayTree(int n) : T(n + 1) {}

    void push(int x) {
        if (!x || !T[x].flip) return;
        int l = T[x].ch[0], r = T[x].ch[1];
        T[l].flip ^= 1, T[r].flip ^= 1;
        swap(T[x].ch[0], T[x].ch[1]);
        T[x].flip = 0;
    }

    void pull(int x) {
        int l = T[x].ch[0], r = T[x].ch[1];
        push(l); push(r);
    }

    void attach(int x, int d, int y) {
        T[x].ch[d] = y;
        T[y].p = x;
        pull(x);
    }

    void splay(int x) {
        auto dir = [&](int x) {
            int p = T[x].p;
            if (!p) return -1;
            if (T[p].ch[0] == x) return 0;
            return T[p].ch[1] == x ? 1 : -1;
        };
        auto rotate = [&](int x) {
            int y = T[x].p, z = T[y].p;
            int dx = dir(x), dy = dir(y);
            attach(y, dx, T[x].ch[!dx]);
            attach(x, !dx, y);
            if (~dy) attach(z, dy, x);
            T[x].p = z;
        };
        for (push(x); ~dir(x); ) {
            int y = T[x].p, z = T[y].p;
            push(z); push(y); push(x);
            int dx = dir(x), dy = dir(y);
            if (~dy) rotate(dx != dy ? x : y);
            rotate(x);
        }
    }
};

struct LinkCut : SplayTree {
    LinkCut(int n) : SplayTree(n) {}

    int access(int x) {
        int u = x, v = 0;
        for (; u; v = u, u = T[u].p) {
            splay(u); T[u].ch[1] = v; pull(u);
        }
        return splay(x), v;
    }

    void reroot(int x) {
        access(x); T[x].flip ^= 1; push(x);
    }

    void Link(int u, int v) {
        reroot(u); access(v);
        T[u].p = v; pull(v);
    }

    void Cut(int u, int v) {
        reroot(u); access(v);
        T[v].ch[0] = T[u].p = 0; pull(v);
    }

    int LCA(int u, int v) {
        static int lca;
        if (u == v) return u;
        access(u); lca = access(v);
        return T[u].p ? lca : 0;
    }
};

struct SegmentTree {
#define il i * 2
#define ir i * 2 + 1
    vector <int> val, cnt, tag;
    int lo, hi, N;

    SegmentTree(int N): N(N),
    val(N * 4), cnt(N * 4), tag(N * 4) {
        build(1, 1, N);
    }

    void build(int i, int l, int r) {
        if (l == r) {
            val[i] = l; cnt[i] = 1;
        }
        else {
            int m = (l + r) / 2;
            build(il, l, m);
            build(ir, m + 1, r);
            pull(i);
        }
    }

    void apply(int i, int v) {
        val[i] += v; tag[i] += v;
    }

    void push(int i) {
        apply(il, tag[i]);
        apply(ir, tag[i]);
        tag[i] = 0;
    }

    void pull(int i) {
        val[i] = min(val[il], val[ir]);
        if (val[i] == val[il])
            cnt[i] = cnt[il];
        else cnt[i] = 0;
        if (val[i] == val[ir])
            cnt[i] += cnt[ir];
    }

    void add(int i, int l, int r, int v) {
        if (l >= lo && r <= hi)
            return apply(i, v);
        push(i);
        int m = (l + r) / 2;
        if (m >= lo) add(il, l, m, v);
        if (m < hi) add(ir, m + 1, r, v);
        pull(i);
    }

    int get(int i, int l, int r) {
        if (l >= lo && r <= hi)
            return (val[i] ? 0 : cnt[i]);
        push(i); int m = (l + r) / 2;
        int res = 0;
        if (m >= lo) res += get(il, l, m);
        if (m < hi) res += get(ir, m + 1, r);
        return res;
    }

    void add(int l, int r, int v) {
        lo = l; hi = r; add(1, 1, N, v);
    }

    int get(int l, int r) {
        lo = l; hi = r; return get(1, 1, N);
    }
};

const int MAXN = 250005;

vector<int> adj[MAXN];
int sum[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vector <pair <int, int>> E;
    for (int i = 1; i <= M; i++) {
        int u, v; cin >> u >> v;
        if (u < v) swap(u, v);
        adj[u].push_back(v); sum[u]++;
    }
    for (int u = 1; u <= N; u++) {
        for (int v : adj[u])
            E.emplace_back(u, v);
        sum[u] += sum[u - 1];
        adj[u].clear();
    }
    sum[N + 1] = 1e9;
    int ptr = 0, lim = 0;
    LinkCut lct(N);
    SegmentTree seg(N);
    long long res = 0;
    for (int i = 1; i <= N; i++) {
        seg.add(i, N, -1);
        while (ptr < M) {
            if (E[ptr].se < i) {
                ptr++; continue;
            }
            int u, v; tie(u, v) = E[ptr];
            if (!lct.LCA(u, v)) {
                adj[v].push_back(u);
                lct.Link(u, v); ptr++;
                seg.add(u, N, -1);
            } else break;
        }
        lim = max(lim, i);
        while (sum[lim + 1] <= ptr) lim++;
        res += seg.get(i, lim);
        seg.add(i, i, N);
        for (int v : adj[i]) {
            lct.Cut(i, v);
            seg.add(v, N, 1);
        }
    }
    cout << res << '\n';
}