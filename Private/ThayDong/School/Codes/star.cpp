#include <bits/stdc++.h>
using namespace std;

namespace dinic{
    #define eb emplace_back
    
    const int inf = numeric_limits <int>::max();
    
    vector <int> dist, to, nxt, head;
    vector <int> flow, capa, work;
    int n, m; queue <int> q;
    
    void init(int n = 0) {
        dinic::n = n; m = 0;
        dist.assign(n + 5, 0);
        head.assign(n + 5, -1);
        work.assign(n + 5, 0);
        to.clear(); capa.clear();
        nxt.clear(); flow.clear();
    }
    
    int add_edge(int u, int v, int c, bool r = 0) {
        to.eb(v); capa.eb(c); flow.eb(0);
        nxt.eb(head[u]); head[u] = m++;
        to.eb(u); capa.eb(r ? c : 0); flow.eb(0);
        nxt.eb(head[v]); head[v] = m++;
        return m - 2;
    }
    
    bool bfs(int s, int t) {
        for (int i = 0; i <= n; i++)
            dist[i] = -1;
        dist[s] = 0; q.emplace(s);
        while (q.size()) {
            int u = q.front(); q.pop();
            for (int i = head[u]; i >= 0; i = nxt[i])
                if (flow[i] < capa[i] && dist[to[i]] < 0) {
                    dist[to[i]] = dist[u] + 1;
                    q.emplace(to[i]);
                }
        }
        return dist[t] >= 0;
    }
    
    int dfs(int s, int t, int f) {
        if (s == t) return f;
        for (int &i = work[s]; i >= 0; i = nxt[i])
            if (flow[i] < capa[i] && dist[to[i]] == dist[s] + 1) {
                int d = dfs(to[i], t, min(f, capa[i] - flow[i]));
                if (d > 0) {
                    flow[i] += d; flow[i ^ 1] -= d; return d;
                }
            }
        return 0;
    }
    
    int max_flow(int s, int t) {
        int res = 0, new_flow;
        while (bfs(s, t)) {
            for (int i = 0; i <= n; i++)
                work[i] = head[i];
            while ((new_flow = dfs(s, t, inf)) > 0)
                res += new_flow;
        }
        return res;
    }
};

const int N = 105;
const int inf = numeric_limits <int>::max();

char s[N][N], row[N], col[N];

int main() {
    //freopen("star.inp", "r", stdin);
    //freopen("star.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> (s[i] + 1);
        for (int j = 1; j <= m; j++) {
            row[i] += s[i][j] == '1';
            col[j] += s[i][j] == '1'; 
        }
    }
    int lo = (n | m) & 1, hi = max(n, m);
    int src = n + m + 2, sink = n + m + 3;
    while (lo < hi) {
        int mi = (lo + hi) / 2, tot = 0;
        dinic::init(n + m + 4);
        dinic::add_edge(n + m + 1, 0, inf);
        int high = min((m + mi) / 2, m);
        int low = m - high;
        for (int i = 1; i <= n; i++) {
            dinic::add_edge(0, i, high - low);
            dinic::add_edge(src, i, low);
            dinic::add_edge(0, sink, low);
            tot += low;
        }
        high = min((n + mi) / 2, n);
        low = n - high;
        for (int i = 1; i <= m; i++) {
            dinic::add_edge(i + n, n + m + 1, high - low);
            dinic::add_edge(src, n + m + 1, low);
            dinic::add_edge(i + n, sink, low);
            tot += low;
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                if (s[i][j] == '1') {
                    dinic::add_edge(src, j + n, 1);
                    dinic::add_edge(i, sink, 1);
                    tot++;
                }
                if (s[i][j] == '*')
                    dinic::add_edge(i, j + n, 1);
            }
        cerr << tot << '\n';
        if (dinic::max_flow(src, sink) >= tot) hi = mi;
        else lo = mi + 1;
    }
    cout << hi << '\n';
}