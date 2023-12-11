#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

map <int, long long> S[MAXN];
int A[MAXN], W[MAXN];
vector <int> adj[MAXN];

void DFS(int u) {
    S[u][A[u]] = W[u];
    long long sum = W[u], del;
    for (int v : adj[u]) {
        DFS(v); sum += W[v];
        if (S[u].size() < S[v].size())
            swap(S[u], S[v]);
        for (auto p : S[v])
            S[u][p.first] += p.second;
    }
    while (sum > W[u]) {
        auto p = *S[u].begin();
        S[u].erase(p.first);
        del = min(p.second, sum - W[u]);
        sum -= del; p.second -= del;
        if (p.second) S[u].insert(p);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N >> W[0];
    for (int i = 1, p; i <= N; i++) {
        cin >> A[i] >> p >> W[i];
        adj[p].push_back(i);
    }
    DFS(0); long long res = 0;
    for (auto p : S[0])
        res += p.second * p.first;
    cout << res << '\n';
}