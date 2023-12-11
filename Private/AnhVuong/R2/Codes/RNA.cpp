#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back

int encode(char c) {
    if (c == 'A') return 0;
    if (c == 'G') return 1;
    if (c == 'C') return 2;
    return 3;
}

struct Trie {
    vector <array <int, 4>> nxt;
    vector <int> tin, tout;
    vector <vector <int>> has;
    int timer; vector <int> ord;

    Trie() {
        nxt.eb(); has.eb();
        tin.eb(); tout.eb();
        timer = 0;
    }

    void addStr(const string &s, int id) {
        int u = 0, t;
        for (char c : s) {
            t = encode(c);
            if (!nxt[u][t]) {
                nxt[u][t] = nxt.size();
                nxt.eb(); has.eb();
                tin.eb(); tout.eb();
            }
            u = nxt[u][t];
        }
        has[u].eb(id);
    }

    int getNode(const string &s) {
        int u = 0;
        for (char c : s) {
            u = nxt[u][encode(c)];
            if (!u) break;
        }
        return u;
    }

    void DFS(int u) {
        tin[u] = ++timer;
        for (int id : has[u])
            ord[id] = timer;
        for (int t = 0; t < 4; t++)
            if (nxt[u][t]) DFS(nxt[u][t]);
        tout[u] = timer;
    }
};

struct query {int l, r, t, id;};

const int N = 2e6 + 5;

vector <query> que[N];
vector <int> pts[N];
int ans[N], bit[N];

void update(int i, int v) {
    for (i++; i < N; i += i & -i)
        bit[i] += v;
}

int getSum(int i) {
    int res = 0;
    for (i++; i > 0; i -= i & -i)
        res += bit[i];
    return res;
}

int getSum(int l, int r) {
    return getSum(r) - getSum(l - 1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    Trie up, down;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        up.addStr(s, i);
        reverse(s.begin(), s.end());
        down.addStr(s, i);
    }
    up.ord.resize(n); down.ord.resize(n);
    up.DFS(0); down.DFS(0);
    for (int i = 0; i < n; i++)
        pts[down.ord[i]].pb(up.ord[i]);
    for (int i = 0; i < m; i++) {
        string s, t; cin >> s >> t;
        int u = up.getNode(s);
        reverse(t.begin(), t.end());
        int v = down.getNode(t);
        if (!u || !v) continue;
        que[down.tin[v] - 1].pb
        ({up.tin[u], up.tout[u], -1, i});
        que[down.tout[v]].pb
        ({up.tin[u], up.tout[u], 1, i});
    }
    int mx = down.nxt.size();
    for (int x = 1; x <= mx; x++) {
        for (int y : pts[x]) update(y, 1);
        for (auto q : que[x])
            ans[q.id] +=
            getSum(q.l, q.r) * q.t;
    }
    for (int i = 0; i < m; i++)
        cout << ans[i] << '\n';
}