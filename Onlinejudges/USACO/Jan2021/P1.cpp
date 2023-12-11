#include <bits/stdc++.h>

using namespace std;

struct node {
    int id, u, dis; bool tp;
};

const int MOD = 1e9 + 7;
const int N = 100005;
const int INF = 0x3f3f3f3f;

int cnt[N][2], inv[N], dis[N][2], cnt2[N][2];
queue <pair <int, int>> que;
vector <int> adj[N];

int madd(int x, int y) {
    if ((x += y) >= MOD) x -= MOD;
    return x;
}

int msub(int x, int y) {
    if ((x -= y) < 0) x += MOD;
    return x;
}

int mmul(int x, int y) {
    return (long long)x * y % MOD;
}

int mdiv(int x, int y) {
    return mmul(x, inv[y]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    inv[1] = 1;
    for (int i = 2; i < N; i++)
        inv[i] = MOD - mmul(MOD / i, inv[MOD % i]);
    int k; cin >> k;
    vector <node> pool;
    for (int id = 1; id <= k; id++) {
        int n, m; cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            dis[i][0] = dis[i][1] = INF;
            adj[i].clear();
        }
        for (int i = 1; i <= m; i++) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dis[1][0] = 0; que.emplace(1, 0);
        while (que.size()) {
            int u, t;
            tie(u, t) = que.front(); que.pop();
            for (int v : adj[u])
                if (dis[v][t ^ 1] == INF) {
                    dis[v][t ^ 1] = dis[u][t] + 1;
                    que.emplace(v, t ^ 1);
                }
        }
        for (int u = 1; u <= n; u++) {
            bool tp = dis[u][0] < dis[u][1];
            if (dis[u][0] != INF)
                pool.push_back({id, u, dis[u][0], tp});
            if (dis[u][1] != INF)
                pool.push_back({id, u, dis[u][1], tp});
        }
    }
    sort(pool.begin(), pool.end(),
    [](const node &a, const node &b) {
        return a.dis < b.dis;
    });
    int mul[2], res = 0, zero[2], mul2[2], zero2[2];
    mul[0] = mul[1] = mul2[0] = mul2[1] = 1;
    zero[0] = zero[1] = zero2[0] = zero2[1] = k;
    for (auto pt : pool) {
        int id = pt.id;
        bool t = pt.dis & 1, tp = pt.tp;
        if (cnt[id][t] == 0) zero[t]--;
        else mul[t] = madd(mul[t], mdiv(mul[t], cnt[id][t]));
        cnt[id][t]++;
        if (zero[t] == 0)
            res = madd(res, mmul(mdiv(mul[t], cnt[id][t]), pt.dis));
        if (t == tp) {
            if (cnt2[id][0] == 0) zero2[0]--;
            else mul2[0] = madd(mul2[0], mdiv(mul2[0], cnt2[id][0]));
            cnt2[id][0]++;
            if (cnt2[id][1] == 0) zero2[1]--;
            else mul2[1] = madd(mul2[1], mdiv(mul2[1], cnt2[id][1]));
            cnt2[id][1]++;
            if (zero2[t] == 0)
                res = msub(res, mmul(mdiv(mul2[t], cnt2[id][t]), pt.dis));
        }
    }
    cout << res << '\n';
}