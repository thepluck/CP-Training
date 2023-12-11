#include <bits/stdc++.h>

using namespace std;

using Tp = long double;

const int N = 1005;

Tp prob[N][N], sum[N];
int n, m, inDeg[N];
vector <pair <int, int>> adj[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout << setprecision(10) << fixed;
    cin >> n >> m;
    if (n <= 1005) {
        for (int i = 0; i < m; i++) {
            int u, v, p;
            cin >> u >> v >> p;
            adj[u].emplace_back(v, p);
            inDeg[v]++;
        }
        vector <int> st(1, 1);
        prob[1][0] = 1;
        while (st.size()) {
            int u = st.back(); 
            st.pop_back();
            int deg = adj[u].size();
            for (auto e : adj[u]) {
                int v, p; tie(v, p) = e;
                for (int k = 1; k <= n; k++) {
                    prob[v][k] += prob[u][k - 1]
                    * (100 - p) / (100 * deg);
                    sum[k] += prob[u][k - 1]
                    * p / (100 * deg);
                }
                if (!(--inDeg[v]))
                    st.push_back(v);
            }
        }
        double sum1 = 1, sum2 = 0;
        for (int i = 1; i <= n; i++) {
            sum1 -= sum[i];
            sum2 += (sum[i] + prob[n][i]) * i;
        }
        cout << sum2 / sum1 << '\n';
    }
}