#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

int col[MAXN], cnt[MAXN];
vector <int> adj[MAXN];
int N, M, dep[MAXN], dis[MAXN];
int ans[MAXN], cur;
vector <int> st;

void DFS1(int u, int p) {
    for (int v : adj[u]) if (v != p) {
        dis[v] = dis[u] + 1; DFS1(v, u);
    }
}

void DFS2(int u, int p) {
    dep[u] = 0;
    for (int v : adj[u]) if (v != p) {
        DFS2(v, u);
        dep[u] = max(dep[u], dep[v]);
    }
    dep[u]++;
}

void Add(int c) {
    cnt[c]++;
    if (cnt[c] == 1) cur++;
}

void Remove(int c) {
    cnt[c]--;
    if (cnt[c] == 0) cur--;
}

void Pop() {
    Remove(col[st.back()]);
    st.pop_back();
}

void Push(int u) {
    Add(col[u]);
    st.push_back(u);
}

void DFS3(int u, int p) {
    vector <pair <int, int>> ch;
    for (int v : adj[u]) if (v != p)
        ch.emplace_back(dep[v], v);
    if (ch.size()) {
        swap(ch[0], *max_element(ch.begin(), ch.end()));
        int len = ch.size() > 1 ? max_element
        (ch.begin() + 1, ch.end())->first : 0;
        for (auto c : ch) {
            int v = c.second;
            while (st.size() && dis[st.back()] >= dis[u] - len) Pop();
            Push(u); DFS3(v, u);
            if (st.size() && st.back() == u) Pop();
            len = max(len, c.first);
        }
        while (st.size() && dis[st.back()] >= dis[u] - len) Pop();
    }
    ans[u] = max(ans[u], cur);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for (int i = 1; i < N; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= N; i++)
        cin >> col[i];
    dis[1] = 0; DFS1(1, 0);
    int u = max_element(dis + 1, dis + N + 1) - dis;
    dis[u] = 0; DFS1(u, 0);
    DFS2(u, 0); DFS3(u, 0);
    u = max_element(dis + 1, dis + N + 1) - dis;
    dis[u] = 0; DFS1(u, 0);
    DFS2(u, 0); DFS3(u, 0);
    for (int i = 1; i <= N; i++)
        cout << ans[i] << '\n';
}
