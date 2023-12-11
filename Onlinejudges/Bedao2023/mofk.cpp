#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
const int maxn = 200005, inf = 1e9 + 9;

typedef tree<
    pair<char, int>,
    null_type,
    less<pair<char, int>>,
    rb_tree_tag,
    tree_order_statistics_node_update>
ordered_set;

int n, q;
int x[maxn], w[maxn];
char d[maxn];
int bucket_id[maxn];
int bucket_rank[maxn];
vector<ordered_set> buckets;
int nbuckets;

char other(char c) {
    return 'R' ^ 'L' ^ c;
}

class HLD {
private:
    int n;
    vector<int> p;
    vector<vector<int>> child;
    vector<int> h;
    vector<int> sz;
    vector<int> nxt;
    vector<int> idx;
    int nchains;
    vector<set<pair<int, int>>> good;

    void dfs(int u) {
        sz[u] = 1;
        for (auto &v: child[u]) {
            h[v] = h[u] + 1;
            dfs(v);
            sz[u] += sz[v];
            if (sz[v] > sz[child[u][0]]) swap(v, child[u][0]);
        }
    }

    void hld(int u) {
        idx[u] = nchains;
        for (auto v: child[u]) {
            if (v == child[u][0]) nxt[v] = nxt[u];
            else ++nchains, nxt[v] = u;
            hld(v);
        }
    }

public:
    HLD() {}
    HLD(int n, vector<int> p, int root) {
        this->n = n;
        this->p = p;
        nchains = 0;
        child.assign(n + 2, vector<int>());
        sz.assign(n + 2, -1);
        h.assign(n + 2, 0);
        nxt.assign(n + 2, -1);
        idx.assign(n + 2, -1);
        for (int i = 1; i <= n; ++i) child[p[i]].push_back(i);
        dfs(root);
        hld(root);
        good.assign(nchains + 1, set<pair<int, int>>());
    }

    void add(int u) {
        good[idx[u]].insert({h[u], u});
    }
    void del(int u) {
        good[idx[u]].erase({h[u], u});
    }
    int ask(int u) {
        while (true) {
            if (good[idx[u]].empty() || h[u] < good[idx[u]].begin()->first) u = nxt[u];
            else return (--good[idx[u]].upper_bound({h[u], u}))->second;
        }
    }
} go_left, go_right;

int ll[maxn], lu[maxn], rl[maxn], ru[maxn];
void build() {
    for (int i = 1; i <= n; ++i) {
        ll[i] = lu[i] = i - 1;
        while (w[ll[i]] < w[i]) ll[i] = ll[ll[i]];
        while (w[lu[i]] <= w[i]) lu[i] = lu[lu[i]];
    }
    for (int i = n; i >= 1; --i) {
        rl[i] = ru[i] = i + 1;
        while (w[rl[i]] < w[i]) rl[i] = rl[rl[i]];
        while (w[ru[i]] <= w[i]) ru[i] = ru[ru[i]];
    }

    go_left = HLD(n, vector<int>(ll, ll + n + 2), 0);
    go_right = HLD(n, vector<int>(rl, rl + n + 2), n + 1);

    for (int i = 0; i <= n + 1; ++i) {
        if (d[i] == 'L') go_right.add(i);
        else go_left.add(i);
    }

    for (int i = 1; i <= n; ++i) {
        int j = ll[i];
        if (w[i] == w[j]) {
            bucket_id[i] = bucket_id[j];
            bucket_rank[i] = bucket_rank[j] + 1;
        }
        else {
            bucket_id[i] = nbuckets++;
            bucket_rank[i] = 0;
        }
    }
    buckets.assign(nbuckets, ordered_set());
    for (int i = 1; i <= n; ++i) {
        int bid = bucket_id[i];
        buckets[bid].insert({d[i], i});
    }
}

void update(int idx) {
    if (d[idx] == 'L') {
        go_right.del(idx);
        go_left.add(idx);
    }
    else {
        go_left.del(idx);
        go_right.add(idx);
    }
    int bid = bucket_id[idx];
    buckets[bid].erase({d[idx], idx});
    d[idx] = other(d[idx]);
    buckets[bid].insert({d[idx], idx});
}

int ask(int idx) {
    int bid = bucket_id[idx];
    int actual = buckets[bid].find_by_order(bucket_rank[idx])->second;
    int old = idx;
    idx = actual;
    
    if (d[idx] == 'L') {
        int idy = go_left.ask(lu[idx]);
        if (old == 187745) cerr<<idy<<'\n';
        if (idy == 0) return -1;
        return x[idx] - x[idy];
    }
    else {
        int idy = go_right.ask(ru[idx]);
        if (idy == n + 1) return -1;
        return x[idy] - x[idx];
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> x[i];
    for (int i = 1; i <= n; ++i) cin >> w[i];
    cin >> (d + 1);
    w[0] = w[n + 1] = inf;
    d[0] = 'R';
    d[n + 1] = 'L';

    build();
    for (int i = 1; i <= q; ++i) {
        int type, idx;
        cin >> type >> idx;
        if (type == 1) update(idx);
        else {
            int ans = ask(idx);
            if (ans < 0) cout << ans << '\n';
            else cout << ans / 2 << '.' << ans % 2 * 5 << '\n';
        }
    }
    return 0;
}
