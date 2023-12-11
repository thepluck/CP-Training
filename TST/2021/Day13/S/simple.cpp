#include <bits/stdc++.h>

using namespace std;

struct twoSAT {
    vector <vector <int>> adj, rev;
    vector <int> cmp, ord; int n;
    vector <char> ass;

    void DFS1(int u) {
        cmp[u] = 0;
        for (int v : adj[u])
            if (cmp[v] < 0) DFS1(v);
        ord.push_back(u);
    }

    void DFS2(int u, int num) {
        cmp[u] = num;
        for (int v : rev[u])
            if (!cmp[v]) DFS2(v, num);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        rev[v].push_back(u);
    }

    bool solve() {
        for (int u = 1; u <= n; u++)
            if (cmp[u] < 0) DFS1(u);
        reverse(ord.begin(), ord.end());
        int num = 0;
        for (int u : ord)
            if (!cmp[u]) DFS2(u, ++num);
        for (int u = 1; u <= n / 2; u++) {
            if (cmp[u] == cmp[u + n / 2])
                return false;
            ass[u] = cmp[u] > cmp[u + n / 2];
        }
        return true;
    }

    twoSAT(int n): n(n), adj(n + 1), rev(n + 1),
    cmp(n + 1, -1), ass(n + 1) {}
};

int main() {
#define X(i) i
#define Y(i) i + n
#define Z(i) i + 2 * n
#define notX(i) i + 3 * n
#define notY(i) i + 4 * n
#define notZ(i) i + 5 * n
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    twoSAT sat(6 * n);
    for (int u = 1; u <= n; u++) {
        sat.addEdge(X(u), notY(u));
        sat.addEdge(X(u), notZ(u));
        sat.addEdge(Y(u), notX(u));
        sat.addEdge(Y(u), notZ(u));
        sat.addEdge(Z(u), notX(u));
        sat.addEdge(Z(u), notY(u));
    }
    while (m--) {
        int u, v; char c;
        cin >> u >> v >> c;
        if (c == 'x') {
            sat.addEdge(notX(u), X(v));
            sat.addEdge(notX(v), X(u));
        }
        else if (c == '-') {
            
        }
    }
}