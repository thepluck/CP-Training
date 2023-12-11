#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

vector <int> adj[MAXN];
int B[MAXN], P[MAXN], N, K, A[MAXN];
int deg[MAXN]; set <int> can;
vector <int> topo;

void rec(int dep) {
    int u = 0;
    if (dep == N) {
        topo.push_back(*can.begin());
        if (--K == 0) {
            for (int i = 0; i < N; i++)
                A[topo[i]] = i + 1;
            for (int i = 1; i <= N; i++)
                cout << A[i] << ' ';
            exit(0);
        }
        topo.pop_back();
    }
    while (true) {
        auto it = can.upper_bound(u);
        if (it == can.end()) break;
        u = *it; can.erase(it);
        topo.push_back(u);
        for (int v : adj[u])
            if (--deg[v] == 0)
                can.insert(v);
        rec(dep + 1);
        for (int v : adj[u])
            if (deg[v]++ == 0)
                can.erase(v);
        topo.pop_back();
        can.insert(u);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> K;
    for (int i = 1, j = 0; i <= N; i++) {
        cin >> B[i];
        if (B[i] < 0) {
            if (j) adj[i].push_back(j);
            j = i; B[i] = N + 1;
        }
        P[i] = N + 1;
    }
    if (B[N] != N + 1) return cout << -1, 0;
    vector <int> S;
    for (int i = N; i > 0; i--) {
        while (S.size() && B[i] > B[S.back()])
            S.pop_back();
        if (B[i] != N + 1) {
            adj[i].push_back(S.back());
            if (B[i] > 1) {
                if (P[B[i] - 1] >= S.back())
                    return cout << -1, 0;
                adj[P[B[i] - 1]].push_back(i);
            }
            P[B[i]] = i;
        }
        S.push_back(i);
    }
    for (int u = 1; u <= N; u++)
        for (int v : adj[u])
            deg[v]++;
    for (int u = 1; u <= N; u++)
        if (deg[u] == 0) can.insert(u);
    rec(1); cout << -1;
}