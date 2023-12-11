#include <bits/stdc++.h>

using namespace std;

const int MAXN = (1 << 18) + 5;

int A[MAXN];
multiset <int> S[MAXN];
vector <int> adj[MAXN];

void DFS(int u) {
    for (int v : adj[u]) {
        DFS(v);
        if (S[u].size() < S[v].size())
            swap(S[u], S[v]);
        S[u].insert(S[v].begin(), S[v].end());
    }
    auto it = S[u].lower_bound(A[u]);
    if (it != S[u].end()) S[u].erase(it);
    S[u].insert(A[u]);
}

int main() {
    freopen("tree.inp", "r", stdin);
    freopen("tree.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        int p; cin >> A[i] >> p;
        adj[p].push_back(i);
    }
    DFS(1); cout << S[1].size() << '\n';
}