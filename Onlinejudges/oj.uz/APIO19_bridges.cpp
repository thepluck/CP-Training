#include <bits/stdc++.h>

using namespace std;

struct item {
    int a, b, c;
};

const int N = 100005;
const int K = 1000;

int root[N], siz[N], ans[N];
vector <int> pot[N], change;
bool vis[N], mark[N];
item edge[N], quer[N];

int Find(int u) {
    while (root[u] != u) u = root[u];
    return u;
}

void Union(int u, int v, bool type) {
    u = Find(u); v = Find(v);
    if (u == v) return;
    if (siz[u] < siz[v]) swap(u, v);
    siz[u] += siz[v]; root[v] = u;
    if (type) change.push_back(v);
}

void rollBack() {
    while (change.size()) {
        int u = change.back();
        change.pop_back();
        siz[root[u]] -= siz[u];
        root[u] = u;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> edge[i].a >> edge[i].b >> edge[i].c;
    int q; cin >> q;
    for (int i = 1; i <= q; i++)
        cin >> quer[i].a >> quer[i].b >> quer[i].c;
    for (int l = 1; l <= q; l += K) {
        int r = min(q, l + K - 1);
        fill(mark + 1, mark + m + 1, 0);
        iota(root + 1, root + n + 1, 1);
        fill(siz + 1, siz + n + 1, 1);
        vector <int> same, upd, ask;
        for (int i = l; i <= r; i++)
            if (quer[i].a == 1)
                mark[quer[i].b] = 1;
            else ask.push_back(i);
        for (int i = 1; i <= m; i++)
            if (!mark[i])
                same.push_back(i);
            else upd.push_back(i);
        for (int i = l; i <= r; i++) {
            if (quer[i].a == 1)
                edge[quer[i].b].c = quer[i].c;
            else {
                for (int j : upd)
                    if (edge[j].c >= quer[i].c)
                        pot[i].push_back(j);
            }
        }
        sort(same.begin(), same.end(),
        [&](int i, int j) {
            return edge[i].c > edge[j].c;
        });
        sort(ask.begin(), ask.end(),
        [&](int i, int j) {
            return quer[i].c > quer[j].c;
        });
        int ptr = 0;
        for (int i : ask) {
            while (ptr < same.size() &&
            edge[same[ptr]].c >= quer[i].c) {
                Union(edge[same[ptr]].a,
                edge[same[ptr]].b, 0); ptr++;
            }
            for (int j : pot[i])
                Union(edge[j].a, edge[j].b, 1);
            ans[i] = siz[Find(quer[i].b)];
            rollBack();
        }
    }
    for (int i = 1; i <= q; i++)
        if (quer[i].a == 2)
            cout << ans[i] << '\n';
}