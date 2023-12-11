#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000006;

long long maxw[MAXN], sumw[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    long long res = 0;
    for (int i = 1; i < N; i++) {
        int u, v; long long w;
        cin >> u >> v >> w;
        maxw[u] = max(maxw[u], w);
        sumw[u] += w;
        maxw[v] = max(maxw[v], w);
        sumw[v] += w;
        res += w;
    }
    for (int u = 1; u <= N; u++)
        if (maxw[u] * 2 > sumw[u])
            res -= sumw[u] - maxw[u];
        else res -= sumw[u] / 2;
    cout << res << '\n';
}