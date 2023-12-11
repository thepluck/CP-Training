#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock
::now().time_since_epoch().count());

int randInt(int l, int r) {
    return uniform_int_distribution <int> (l, r)(rng);
}

const int N = 1005;

int pos[N], val[N], n, dep[N], tmp[N];
vector <pair <int, int>> edge;
vector <int> adj[N];
int par[N], deg[N];

void BFS() {
    map <vector <int>, int> dis, trace;
    vector <int> start, target;
    vector <pair <int, int>> ans;
    for (int i = 1; i <= n; i++) {
        start.push_back(val[i]);
        target.push_back(i);
    }
    dis[start] = 0;
    queue <vector <int>> que;
    que.push(start);
    while (que.size()) {
        auto cur = que.front(); que.pop();
        if (cur == target) break;
        for (int i = 0; i < n - 1; i++) {
            int u, v; tie(u, v) = edge[i];
            auto nxt = cur;
            swap(nxt[u - 1], nxt[v - 1]);
            if (!dis.count(nxt)) {
                dis[nxt] = dis[cur] + 1;
                trace[nxt] = i;
                que.push(nxt);
            }
        }
    }
    while (target != start) {
        int u, v;
        tie(u, v) = edge[trace[target]];
        swap(target[u - 1], target[v - 1]);
        ans.emplace_back(u, v);
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto e : ans)
        cout << e.first << ' ' << e.second << '\n';
}

void DFS(int u) {
    for (int v : adj[u]) if (v != par[u]) {
        dep[v] = dep[u] + 1; par[v] = u; DFS(v);
    }
}

vector <pair <int, int>> cur, ans;

void correct(int u) {
    par[u] = 0; DFS(u); int v = pos[u];
    while (v != u) {
        cur.emplace_back(v, par[v]);
        swap(val[v], val[par[v]]);
        pos[val[v]] = v;
        pos[val[par[v]]] = par[v];
        v = par[v];
    }
}

void greedy() {
    DFS(1);
    while (1.0 * clock() / CLOCKS_PER_SEC < 5.0) {
        cur.clear();
        for (int i = 1; i <= n; i++) {
            val[i] = tmp[i]; pos[val[i]] = i;
        }
        vector <pair <int, int>> perm;
        for (int i = 1; i <= n; i++)
            perm.emplace_back(i, randInt(1, 1000000000));
        sort(perm.begin(), perm.end(),
        [&](const pair <int, int> &p, const pair <int, int> &q) {
            return make_pair(dep[p.first], p.second) >
            make_pair(dep[q.first], q.second);
        });
        for (auto pp : perm) correct(pp.first);
        if (ans.empty()) ans = cur;
        else if (ans.size() > cur.size()) ans = cur;
    }
    while (clock() < 10000) {
        cur.clear();
        for (int u = 1; u <= n; u++)
            deg[u] = adj[u].size();
        deque <int> que;
        for (int i = 1; i <= n; i++) {
            val[i] = tmp[i]; pos[val[i]] = i;
            if (deg[i] == 1) que.push_back(i);
        }
        int cnt = 0;
        while (que.size()) {
            shuffle(que.begin(), que.end(), rng);
            int u = que.front(); que.pop_front();
            for (int v : adj[u])
                if (--deg[v] == 1) que.push_back(v);
            correct(u); cnt++;
        }
        if (ans.empty()) ans = cur;
        else if (ans.size() > cur.size()) ans = cur;
    }
    cout << ans.size() << '\n';
    for (auto e : ans)
        cout << e.first << ' ' << e.second << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edge.emplace_back(u, v);
    }
    for (int i = 1; i <= n; i++) {
        cin >> val[i]; pos[val[i]] = i;
        tmp[i] = val[i];
    }
    greedy();
}