#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000005;
const int MAXM = 25;

vector <int> adj[MAXN];
int U[MAXN], V[MAXN], W[MAXN];
vector <int> path;
bool mark[MAXN];
int idx[MAXN], bel[MAXN];
queue <int> que;
int need[MAXM][MAXM];
int cost[MAXM][MAXM];
int be[MAXM], en[MAXM], in[MAXM];
int DP[20][1 << 20];

bool find_path(int u, int p) {
    path.push_back(u);
    if (mark[u]) return true;
    for (int i : adj[u]) {
        int v = u ^ U[i] ^ V[i];
        if (v != p && find_path(v, u)) {
            if (W[i]) {
                que.push(W[i]);
                be[i] = v; en[i] = u;
            }
            return true;
        }
    }
    path.pop_back();
    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, S, T, cnt = 0;
    cin >> N >> S >> T;
    memset(bel, -1, sizeof bel);
    memset(idx, -1, sizeof idx);
    for (int i = 0; i + 1 < N; i++) {
        cin >> U[i] >> V[i] >> W[i];
        adj[U[i]].push_back(i);
        adj[V[i]].push_back(i);
        if (W[i]) {
            in[cnt] = W[i];
            bel[U[i]] = bel[V[i]] = cnt;
            bel[W[i]] = idx[i] = cnt++;
        }
    }
    mark[S] = true; que.push(T);
    while (que.size()) {
        int u = que.front();
        que.pop(); path.clear();
        if (mark[u]) continue;
        find_path(u, 0);
        for (int v : path)
            mark[v] = true;
    }
    for (int i = 0; i < cnt; i++) {
        queue <tuple <int, int, int>> que;
        que.emplace(en[i], 0);
        memset(mark, 0, sizeof mark);
        mark[en[i]] = true;
        while (que.size()) {
            int u, mask, dist;
            tie(u, mask, dist) = que.front();
            if (bel[u] >= 0 && u == in[bel[u]]) {
                need[i][bel[u]] = mask;
                cost[i][bel[u]] = dist;
            }
            for (int e : adj[u]) {
                int v = u ^ U[e] ^ V[e];
                if (!mark[v]) {
                    int nmask = mask;
                    if (idx[e] >= 0)
                        nmask |= 1 << idx[e];
                    mark[v] = true;
                    que.emplace(v, nmask, dist + 1);
                }
            }
        }
        memset(mark, 0, sizeof mark);
        mark[in[i]] = true;
        while (que.size()) {
            int u, mask, dist;
            tie(u, mask, dist) = que.front();
            if (bel[u] == i) {
                need[i][bel[u]] |= mask;
                cost[i][bel[u]] += dist;
            }
            for (int e : adj[u]) {
                int v = u ^ U[e] ^ V[e];
                if (!mark[v]) {
                    int nmask = mask;
                    if (idx[e] >= 0)
                        nmask |= 1 << idx[e];
                    mark[v] = true;
                    que.emplace(v, nmask, dist + 1);
                }
            }
        }
    }

}