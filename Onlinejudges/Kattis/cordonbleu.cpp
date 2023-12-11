#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

const int N = 2005;
const int INF = 0x3f3f3f3f;

int cost[N][N], dis[N], trc[N];
int px[N], py[N], mat[N]; bool vis[N];
pair <int, int> a[N], b[N];

int cal(pair <int, int> a, pair <int, int> b) {
    return abs(a.first - b.first)
    + abs(a.second - b.second);
}

struct MCMM {
    vector <vector <long long>> cost;
    vector <long long> dis, px, py;
    vector <int> trc, mat;
    vector <char> vis; int n, m;
    
    MCMM(int n, int m) {init(n, m);}
    
    void init(int n, int m) {
        cost.assign(n + 5,
        vector <long long> (m + 5, 1e9)); 
        px.assign(n + 5, 0);
        py.assign(m + 5, 0);
        dis.assign(m + 5, 0);
        trc.assign(m + 5, 0);
        mat.assign(m + 5, 0);
        vis.assign(m + 5, 0);
        this->n = n; this->m = m;
    }
    
    void add_edge(int u, int v, int c) {
        cost[u][v] = c;
    }
    
    long long hungarian() {
        for (int i = 1; i <= n; i++) {
            int u = 0; mat[0] = i;
            fill(dis.begin(), dis.end(), 1e18);
            fill(vis.begin(), vis.end(), false);
            fill(trc.begin(), trc.end(), -1);
            while (mat[u]) {
                long long delta = 1e18;
                int w; vis[u] = true;
                for (int v = 0; v <= m; v++) {
                    if (vis[v]) continue;
                    if (cmin(dis[v], cost[mat[u]][v]
                    - px[mat[u]] - py[v])) trc[v] = u;
                    if (cmin(delta, dis[v])) w = v;
                }
                for (int v = 0; v <= m; v++)
                    if (vis[v]) {
                        px[mat[v]] += delta;
                        py[v] -= delta;
                    }
                    else dis[v] -= delta;
                u = w;
            }
            for (int v; u; u = v)
                mat[u] = mat[v = trc[u]];
        }
        return -py[0];
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;
    for (int i = 1; i <= m; i++)
        cin >> b[i].first >> b[i].second;
    pair <int, int> r;
    cin >> r.first >> r.second;
    MCMM MC(n, n + m - 1);
    for (int i = 1; i <= n; i++) {
        int tmp = cal(a[i], r);
        for (int j = 1; j <= m; j++)
            MC.add_edge(i, j, tmp + cal(a[i], b[j]));
        for (int j = m + 1; j < n + m; j++)
            MC.add_edge(i, j, tmp * 2);
    }
    cout << MC.hungarian();
}
