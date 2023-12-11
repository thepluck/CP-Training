
// Problem : E. Lucky Country
// Contest : Codeforces - Codeforces Beta Round #77 (Div. 1 Only)
// URL : https://codeforces.com/contest/95/problem/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int inf = 0x3f3f3f3f;

int f[N], g[N], p[N], s[N], a[N];

int fin(int u) {
    return p[u] != u ?
    p[u] = fin(p[u]) : u;
}

void mer(int u, int v) {
    p[fin(v)] = fin(u);
}

bool check(int x) {
    while (x) {
        if (x % 10 != 4 && x % 10 != 7)
            return 0;
        x /= 10;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++)
        p[i] = i;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        mer(u, v);
    }
    for (int i = 1; i <= n; i++)
        s[fin(i)]++;
    for (int i = 1; i <= n; i++)
        if (p[i] == i) a[s[i]]++;
    m = 0;
    for (int i = 1; i <= n; i++)
        if (a[i]) {
            s[++m] = a[i]; a[m] = i;
        }
    memset(f, 0x3f, sizeof f);
    memset(g, 0x3f, sizeof g);
    f[0] = 0; deque <int> dq;
    for (int i = 1; i <= m; i++) {
        int mx = a[i] * s[i];
        for (int j = 0; j < a[i]; j++) {
            dq.clear();
            for (int k = j; k <= n; k += a[i]) {
                while (!dq.empty() && dq[0] < k - mx)
                    dq.pop_front();
                while (!dq.empty() && f[dq.back()] +
                (k - dq.back()) / a[i] >= f[k])
                    dq.pop_back();
                dq.push_back(k);
                if (f[dq[0]] < inf)
                    g[k] = f[dq[0]] + (k - dq[0]) / a[i];
                else g[k] = inf;
            }
        }
        swap(f, g);
    }
    int res = inf;
    for (int i = 1; i <= n; i++)
        if (check(i))
            res = min(res, f[i]);
    if (res == inf) res = 0;
    cout << res - 1 << '\n';
}