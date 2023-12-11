#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
const int MOD = 1000000007;

int cnt[N][2], way[N][2];
vector <int> adj[N];

int add(int x, int y) {
    if ((x += y) >= MOD) x -= MOD;
    return x;
}

int mul(int x, int y) {
    return (long long)x * y % MOD;
}

void DFS(int u, int p) {
    cnt[u][1] = way[u][0] = way[u][1] = 1;
    for (int v : adj[u]) if (v != p) {
        DFS(v, u);
        cnt[u][0] += max(cnt[v][0], cnt[v][1]);
        if (cnt[v][0] > cnt[v][1])
            way[u][0] = mul(way[u][0], way[v][0]);
        else if (cnt[v][0] < cnt[v][1])
            way[u][0] = mul(way[u][0], way[v][1]);
        else way[u][0] = mul(way[u][0], add(way[v][0], way[v][1]));
        cnt[u][1] += max(cnt[v][0], cnt[v][1] - 1);
        if (cnt[v][0] > cnt[v][1] - 1)
            way[u][1] = mul(way[u][1], way[v][0]);
        else if (cnt[v][0] < cnt[v][1] - 1)
            way[u][1] = mul(way[u][1], way[v][1]);
        else way[u][1] = mul(way[u][1], add(way[v][0], way[v][1]));
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1, 0);
    int acnt = max(cnt[1][0], cnt[1][1]), away = 0;
    if (acnt == cnt[1][0]) away = add(away, way[1][0]);
    if (acnt == cnt[1][1]) away = add(away, way[1][1]);
    cout << acnt << ' ' << away << '\n';
}