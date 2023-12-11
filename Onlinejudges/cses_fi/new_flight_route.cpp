#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector <int> g[2][N], dag[N], ext;
bitset <N> vs; int hd[N];
int cmp[N], in[N], out[N];

void dfs(int u, int r) {
    vs[u] = 1; cmp[u] = r;
    for (int v : g[r > 0][u])
        if (!vs[v]) dfs(v, r);
    if (!r) ext.push_back(u);
}

int vis(int u) {
    if (vs[u]) return 0;
    vs[u] = 1;
    if (!out[u]) return u;
    for (int v : dag[u]) {
        int r = vis(v);
        if (r) return r;
    }
    return 0;
} 

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[0][u].push_back(v);
        g[1][v].push_back(u);
    }
    for (int u = 1; u <= n; u++)
        if (!vs[u]) dfs(u, 0);
    vs.reset(); int cc = 0;
    reverse(ext.begin(), ext.end());
    for (int u : ext)
        if (!vs[u]) {
            dfs(u, ++cc); hd[cc] = u;
        }
    for (int u = 1; u <= n; u++)
        for (int v : g[0][u])
            if (cmp[u] != cmp[v]) {
                dag[cmp[u]].push_back(cmp[v]);
                out[cmp[u]]++; in[cmp[v]]++;
            }
    if (cc == 1) {
        cout << "0\n"; return 0;
    }
    vs.reset();
    vector <int> m_src, u_src;
    vector <int> m_sink, u_sink;
    for (int u = 1; u <= cc; u++)
        if (!in[u]) {
            int v = vis(u);
            if (v) {
                m_src.push_back(u);
                m_sink.push_back(v);
            }
            else u_src.push_back(u);
        }
    for (int u = 1; u <= cc; u++)
        if (!out[u] && !vs[u])
            u_sink.push_back(u);
    int x = m_src.size();
    m_src.insert(m_src.end(), u_src.begin(), u_src.end());
    m_sink.insert(m_sink.end(), u_sink.begin(), u_sink.end());
    int y = m_src.size(), z = m_sink.size();
    cout << max(m_src.size(), m_sink.size()) << '\n';
    cout << hd[m_sink[0]] << ' ' << hd[m_src[x - 1]] << '\n';
    for (int i = 1; i < x; i++)
        cout << hd[m_sink[i]] << ' ' << hd[m_src[i - 1]] << '\n';
    for (int i = x; i < min(y, z); i++)
        cout << hd[m_sink[i]] << ' ' << hd[m_src[i]] << '\n';
    for (int i = min(y, z); i < y; i++)
        cout << hd[m_sink[0]] << ' ' << hd[m_src[i]] << '\n';
    for (int i = min(y, z); i < z; i++)
        cout << hd[m_sink[i]] << ' ' << hd[m_src[0]] << '\n';
}