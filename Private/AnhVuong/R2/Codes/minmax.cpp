#include <bits/stdc++.h>

using namespace std;

const int N = 200005, LG = 18, MOD = 1e9 + 7;

int mi[LG][N], ma[LG][N], lef[N], rig[N];
int nxt[N], n, q, BIT[N], id[N]; bool root[N];
vector <int> adj[N], val; set <pair <int, int>> seg;

void update(int i, int v) {
    for (; i < N; i += i & -i) BIT[i] += v;
}

int findPos(int k) {
    int pos = 0;
    for (int len = 1 << LG; len > 0; len >>= 1)
        if (pos + len < N && BIT[pos + len] < k) {
            pos += len; k -= BIT[pos];
        }
    return pos + 1;
}

int queryMin(int l, int r) {
    if (l > r) return INT_MAX;
    int k = __lg(r - l + 1);
    return min(mi[k][l], mi[k][r + 1 - (1 << k)]);
}

int queryMax(int l, int r) {
    if (l > r) return INT_MIN;
    int k = __lg(r - l + 1);
    return max(ma[k][l], ma[k][r + 1 - (1 << k)]);
}

void buildRMQ() {
    for (int k = 1; k < LG; k++)
        for (int i = 1; i + (1 << k) <= n + 1; i++) {
            mi[k][i] = min(mi[k - 1][i],
            mi[k - 1][i + (1 << (k - 1))]);
            ma[k][i] = max(ma[k - 1][i],
            ma[k - 1][i + (1 << (k - 1))]);
        }
}

void DFS(int u) {
    if (u <= n) {
        auto it = seg.upper_bound({mi[0][u], -1});
        if (it != seg.begin() && prev(it)->second >= mi[0][u])
            val.push_back(mi[0][u]);
        return;
    }
    vector <int> preMin(adj[u].size() + 1, 0);
    vector <int> preMax(adj[u].size() + 1, 1e9);
    vector <int> sufMin(adj[u].size() + 1, 0);
    vector <int> sufMax(adj[u].size() + 1, 1e9);
    for (int i = 0; i < int(adj[u].size()); i++) {
        int v = adj[u][i];
        preMin[i + 1] = max(queryMin(lef[v], rig[v]), preMin[i]);
        preMax[i + 1] = min(queryMax(lef[v], rig[v]), preMax[i]);
    }
    for (int i = adj[u].size() - 1; i >= 0; i--) {
        int v = adj[u][i];
        sufMin[i] = max(queryMin(lef[v], rig[v]), sufMin[i + 1]);
        sufMax[i] = min(queryMax(lef[v], rig[v]), sufMax[i + 1]);
    }
    for (int i = 0; i < int(adj[u].size()); i++) {
        int v = adj[u][i];
        int hi = max(preMin[i], sufMin[i + 1]);
        int lo = min(preMax[i], sufMax[i + 1]);
        vector <pair <int, int>> add, rmv;
        if (lo + 1 <= hi - 1) {
            auto it = seg.lower_bound({lo + 1, -1});
            if (it != seg.begin() && prev(it)->second > lo)
                it = prev(it);
            while (it != seg.end() && it->first < hi) {
                rmv.push_back(*it);
                if (it->first <= lo)
                    add.emplace_back(it->first, lo);
                if (it->second >= hi)
                    add.emplace_back(hi, it->second);
                it = next(it);
            }
        }
        for (auto p : rmv) seg.erase(p);
        for (auto p : add) seg.insert(p);
        DFS(v);
        for (auto p : add) seg.erase(p);
        for (auto p : rmv) seg.insert(p);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n; int res = 1;
    vector <int> cmp;
    fill(root, root + N, 1);
    for (int i = 1; i <= n; i++) {
        cin >> mi[0][i]; ma[0][i] = mi[0][i];
        nxt[i] = i; id[i] = i; update(i, 1);
        lef[i] = rig[i] = i;
    }
    buildRMQ(); cin >> q;
    for (int i = 1; i <= q; i++) {
        int l, r; cin >> l >> r;
        int len = r - l + 1, curl = l = findPos(l);
        while (len > 0) {
            update(curl, -1); r = nxt[curl];
            adj[i + n].push_back(id[curl]);
            root[id[curl]] = 0; curl = r + 1; len--;
        }
        update(l, 1); nxt[l] = r; id[l] = i + n;
        lef[i + n] = l; rig[i + n] = r;
    }
    seg.emplace(0, 1e9);
    for (int i = 1; i <= n + q; i++)
        if (root[i]) {
            val.clear(); DFS(i);
            sort(val.begin(), val.end());
            val.erase(unique(val.begin(), val.end()), val.end());
            res = val.size() * res % MOD;
        }
    cout << res << '\n';
}