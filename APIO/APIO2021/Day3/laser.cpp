#include <bits/stdc++.h>

using namespace std;

struct DinicFlow {
    vector <int> head, dist, work;
    vector <int> to, nxt, capa, flow;
    queue <int> que;
 
    void init(int n) {
        head.assign(n + 5, -1);
        dist.assign(n + 5, 0);
        work.assign(n + 5, 0);
        to.clear(); nxt.clear();
        capa.clear(); flow.clear();
    }
 
    int addEdge(int u, int v, int c, bool r = 0) {
        cerr << u << ' ' << v << ' ' << c << '\n';
        to.push_back(v); nxt.push_back(head[u]);
        capa.push_back(c); flow.push_back(0);
        head[u] = to.size() - 1;
        to.push_back(u); nxt.push_back(head[v]);
        capa.push_back(c * r); flow.push_back(0);
        head[v] = to.size() - 1;
        return head[u];
    }
 
    bool BFS(int s, int t) {
        fill(dist.begin(), dist.end(), -1);
        dist[s] = 0; que.push(s);
        while (que.size()) {
            s = que.front(); que.pop();
            for (int i = head[s]; i >= 0; i = nxt[i])
                if (dist[to[i]] < 0 && capa[i] > flow[i]) {
                    dist[to[i]] = dist[s] + 1; que.push(to[i]);
                }
        }
        return dist[t] >= 0;
    }
 
    int DFS(int s, int t, int f) {
        if (s == t) return f;
        for (int &i = work[s]; i >= 0; i = nxt[i])
            if (dist[to[i]] == dist[s] + 1 && capa[i] > flow[i]) {
                int d = DFS(to[i], t, min(f, capa[i] - flow[i]));
                if (d > 0) {
                    flow[i] += d; flow[i ^ 1] -= d; return d;
                }
            }
        return 0;
    }
 
    int maxFlow(int s, int t) {
        int tot = 0, aug;
        while (BFS(s, t)) {
            copy(head.begin(), head.end(), work.begin());
            while ((aug = DFS(s, t, INT_MAX)) > 0) tot += aug;
        }
        return tot;
    }
};

const int MAXN = 55;
const int INF = 0x3f3f3f3f;

char S[MAXN][MAXN];
int M, N, res = 0; bool mark[20];

#define flat(i, j) (i - 1) * M + (j)

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> M >> N;
    for (int i = 1; i <= M; i++)
        cin >> (S[i] + 1);
    DinicFlow MF; MF.init(M * N + 2);
    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= N; j++)
            if (S[i][j] == '<') {
                MF.addEdge(flat(i, j), M * N + 1, INF);
                S[i][j] = '0'; int x = j;
                for (int y = j - 1; y > 0; y--)
                    if (S[i][y] > S[i][x]) {
                        MF.addEdge(flat(i, x - 1),
                        flat(i, x), S[i][y] - S[i][x]);
                        while (--x > y)
                            MF.addEdge(flat(i, x - 1),
                            flat(i, x), 0);
                    }
                res += S[i][x] - '0';
            } else if (S[i][j] == '>') {
                MF.addEdge(flat(i, j), M * N + 1, INF);
                S[i][j] = '0'; int x = j;
                for (int y = j + 1; y <= N; y++)
                    if (S[i][y] > S[i][x]) {
                        MF.addEdge(flat(i, x + 1),
                        flat(i, x), S[i][y] - S[i][x]);
                        while (++x < y)
                            MF.addEdge(flat(i, x + 1),
                            flat(i, x), 0);
                    }
                res += S[i][x] - '0';
            } else if (S[i][j] == 'A') {
                MF.addEdge(0, flat(i, j), INF);
                S[i][j] = '0'; int x = i;
                for (int y = i - 1; y > 0; y--)
                    if (S[y][j] > S[x][j]) {
                        MF.addEdge(flat(x, j), flat
                        (x - 1, j), S[y][j] - S[x][j]);
                        while (--x > y)
                            MF.addEdge(flat(x, j),
                            flat(x - 1, j), 0);
                    }
                res += S[x][j] - '0';
            } else if (S[i][j] == 'V') {
                MF.addEdge(0, flat(i, j), INF);
                S[i][j] = '0'; int x = i;
                for (int y = i + 1; y <= M; y++)
                    if (S[y][j] > S[x][j]) {
                        MF.addEdge(flat(x, j), flat
                        (x + 1, j), S[y][j] - S[x][j]);
                        while (++x > y)
                            MF.addEdge(flat(x, j),
                            flat(x + 1, j), 0);
                    }
                res += S[x][j] - '0';
            }
    cout << res - MF.maxFlow(0, M * N + 1);
}
