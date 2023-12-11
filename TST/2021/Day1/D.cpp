#include <bits/stdc++.h>

using namespace std;

namespace dinic {
    const int INF = INT_MAX;
 
    vector <int> head, dis, work;
    vector <int> to, nxt, capa, flow;
    int n; queue <int> q;
 
    void init(int n) {
        dinic::n = n;
        head.assign(n + 5, -1);
        dis.assign(n + 5, 0);
        work.assign(n + 5, 0);
        to.clear(); nxt.clear();
        capa.clear(); flow.clear();
    }
 
    int add_edge(int u, int v, int c, bool r = 0) {
        to.push_back(v); nxt.push_back(head[u]);
        capa.push_back(c); flow.push_back(0);
        head[u] = to.size() - 1;
        to.push_back(u); nxt.push_back(head[v]);
        capa.push_back(c * r); flow.push_back(0);
        head[v] = to.size() - 1;
        return head[u];
    }
 
    bool bfs(int s, int t) {
        fill(dis.begin(), dis.end(), -1);
        dis[s] = 0; q.push(s);
        while (q.size()) {
            int u = q.front(); q.pop();
            for (int i = head[u]; i >= 0; i = nxt[i])
                if (flow[i] < capa[i] && dis[to[i]] < 0) {
                    dis[to[i]] = dis[u] + 1; q.push(to[i]);
                }
        }
        return dis[t] >= 0;
    }
 
    int dfs(int s, int t, int f) {
        if (s == t) return f;
        for (int &i = work[s]; i >= 0; i = nxt[i])
            if (flow[i] < capa[i] && dis[to[i]] == dis[s] + 1) {
                int d = dfs(to[i], t, min(f, capa[i] - flow[i]));
                if (d > 0) {
                    flow[i] += d; flow[i ^ 1] -= d; return d;
                }
            }
        return 0;
    }
 
    int max_flow(int s, int t) {
        int res = 0, aug;
        while (bfs(s, t)) {
            copy(head.begin(), head.end(), work.begin());
            while ((aug = dfs(s, t, INF)) > 0) res += aug;
        }
        return res;
    }
};

int n, m, sum;

int add_edge(int u, int v, int lo, int hi) {
    sum += lo;
    dinic::add_edge(2 * n + 2 * m + 2, v, lo);
    dinic::add_edge(u, 2 * n + 2 * m + 3, lo);
    return dinic::add_edge(u, v, hi - lo);
}

int main() {
    // freopen("rooks.inp", "r", stdin);
    // freopen("rooks.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    dinic::init(2 * n + 2 * m + 10);
    vector <pair <int, int>> in, out;
    vector <vector <char>> mark(n + 1, vector <char> (n + 1));
    for (int i = 1; i <= m; i++) {
        int b, l, t, r, c;
        cin >> b >> l >> t >> r >> c;
        add_edge(2 * n + i, 2 * n + i + m, c, c);
        for (int x = b; x <= t; x++)
            for (int y = l; y <= r; y++) {
                in.emplace_back(x, add_edge(x, 2 * n + i, 0, 1));
                out.emplace_back(y, add_edge(2 * n + i + m, y + n, 0, 1));
                mark[x][y] = true;
            }
    }
    for (int i = 1; i <= n; i++) {
        add_edge(0, i, 1, 1);
        add_edge(i + n, 2 * n + 2 * m + 1, 1, 1);
    }
    dinic::add_edge(2 * n + 2 * m + 1, 0, n + 5);
    vector <tuple <int, int, int>> rem;
    for (int x = 1; x <= n; x++)
        for (int y = 1; y <= n; y++)
            if (!mark[x][y])
                rem.emplace_back(x, y, add_edge(x, y + n, 0, 1));
    if (dinic::max_flow(2 * n + 2 * m + 2, 2 * n + 2 * m + 3) < sum) {
        cout << "NO\n"; return 0;
    }
    vector <int> x, y, a(n + 1), b(n + 1);
    for (auto pp : in)
        if (dinic::flow[pp.second]) x.push_back(pp.first);
    for (auto pp : out)
        if (dinic::flow[pp.second]) y.push_back(pp.first);
    for (int j = 0; j < x.size(); j++) {
        a[x[j]] = y[j];
    }
    for (auto e : rem) {
        int x, y, i; tie(x, y, i) = e;
        if (dinic::flow[i]) a[x] = y;
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
}