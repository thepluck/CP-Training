#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")


#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int rand(int l ,int r) {
    return uniform_int_distribution <int> (l, r)(rng);
}

const int MAXN = 1005;

vector <int> adj[MAXN];
int dis[MAXN][MAXN];
int N, K; int best;
queue <int> que;
int val[MAXN][MAXN];
pair <int, int> cnt[MAXN][MAXN];
bool choose[MAXN];

void recompute() {
    memset(dis, -1, sizeof dis);
    for (int i = 1, u; i <= N; i++) {
        dis[i][i] = 0; que.push(i);
        while (que.size()) {
            u = que.front(); que.pop();
            for (int v : adj[u])
                if (dis[i][v] < 0) {
                    dis[i][v] = dis[i][u] + 1;
                    que.push(v);
                }
        }
    }
    memset(val, 0, sizeof val);
    vector <int> node;
    vector <pair <int, int>> tmp;
    for (int i = 1; i <= N; i++) {
        tmp.emplace_back(adj[i].size(), i);
    }
    sort(tmp.rbegin(), tmp.rend());
    for (int i = 0; i < 100; i++)
        node.push_back(tmp[i].second);
    for (int a : node) {
        for (int c : node)
            for (int d = 1; d <= N; d++)
                cnt[c][d] = {0, 0};
        for (int c : node)
            for (int d : node)
                if (dis[a][d] > dis[c][d]) {
                    int x = dis[a][d] - dis[c][d];
                    cnt[c][x].first += x;
                    cnt[c][x].second++;
                }
        for (int c : node)
            for (int d = N; d > 0; d--) {
                cnt[c][d].first += cnt[c][d + 1].first;
                cnt[c][d].second += cnt[c][d + 1].second;
            }
        for (int b : node)
            for (int c : node) {
                val[b][c] += cnt[c][dis[a][b] + 1].first -
                cnt[c][dis[a][b] + 1].second * (dis[a][b] + 1);
            }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> N >> K >> best;
    for (int i = 1; i < N; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector <pair <int, int>> edge;
    while (K--) {
        recompute();
        int bestB, bestC;
        int mx = 0;
        for (int b = 1; b <= N; b++)
            for (int c = 1; c <= N; c++)
                if (val[b][c] > mx) {
                    mx = val[b][c];
                    bestB = b; bestC = c;
                }
        adj[bestB].push_back(bestC);
        adj[bestC].push_back(bestB);
        edge.emplace_back(bestB, bestC);
    }
    recompute();
    int res = 0;
    for (int i = 1; i <= N; i++)
        for (int j = i + 1; j <= N; j++)
            res += dis[i][j];
    for (auto e : edge)
        cout << e.first << ' ' << e.second << '\n';
    cerr << min(1.0, pow(20, 1.0 - 1.0 * res / best));
}