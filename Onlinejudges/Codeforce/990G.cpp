
// Problem : G. GCD Counting
// Contest : Codeforces - Educational Codeforces Round 45 (Rated for Div. 2)
// URL : https://codeforces.com/contest/990/problem/G
// Memory Limit : 256 MB
// Time Limit : 4500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back

using ll = long long;

const int N = 200001;

int mu[N]; ll x[N], y[N];
vector <int> g[N], c[N];
int vs[N], to[N], a[N], tim;
queue <int> q;

int bfs(int u) {
    int cnt = 0;
    q.emplace(u); vs[u] = tim;
    while (q.size()) {
        u = q.front(); q.pop(); cnt++;
        for (int v : g[u])
            if (vs[v] < tim && to[a[v]] == tim) {
                vs[v] = tim; q.emplace(v);
            }
    }
    return cnt;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    mu[1] = 1;
    for (int i = 1; i < N; i++)
        for (int j = 2 * i; j < N; j += i)
            mu[j] -= mu[i];
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; c[a[i]].eb(i);
    }
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].eb(v); g[v].eb(u);
    }
    for (int i = N - 1; i > 0; i--) {
        tim++;
        for (int j = i; j < N; j += i)
            to[j] = tim;
        for (int j = i; j < N; j += i)
            for (int u : c[j]) {
                if (vs[u] == tim) continue;
                int cnt = bfs(u);
                x[i] += ll(cnt + 1) * cnt / 2;
            }
        for (int j = 1; i * j < N; j++)
            y[i] += x[i * j] * mu[j];
    }
    for (int i = 1; i < N; i++)
        if (y[i]) cout << i << ' ' << y[i] << '\n';
}