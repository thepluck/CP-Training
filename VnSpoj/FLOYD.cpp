#include <bits/stdc++.h>
using namespace std;

typedef vector <int> vi;
typedef vector <vector <int> > vvi;
const int inf  = 0x3f3f3f3f;
vi s; int x;
struct Graph{
    int n; vvi Edge;
    Graph(int n) : n(n) {
        Edge.resize(n + 1, vi(n + 1, inf));
    }
    void addEdge(int u, int v, int w){
        Edge[u][v] = Edge[v][u] = w;
    }
    void Enter(){
        int m, u, v, w; cin >> m >> x;
        while (m--){
            cin >> u >> v >> w;
            addEdge(u, v, w);
        }
    }
    void Floyd(){
        for (int i = 1; i <= n; i++) Edge[i][i] = 0;
        for (int k = 1; k <= n; k++)
            for (int i = 1; i < n; i++)
                for (int j = i + 1; j <= n; j++)
                    Edge[i][j] = Edge[j][i] = min(Edge[i][j], Edge[i][k] + Edge[k][j]);
    }
    void Trace(int u, int v){
        for (int k = 1; k <= n; k++)
            if (Edge[u][v] == Edge[u][k] + Edge[k][v] && k != u && k != v){
                Trace(u, k); s.push_back(k);
                Trace(k, v); goto gg;
            }
        gg:;
    }
    void Queries(int q, int u, int v){
        if (q == 0) cout << Edge[u][v] << '\n';
        else{
            s.clear(); Trace(u, v);
            cout << s.size() + 2 << ' ' << u << ' ';
            for (auto i : s) cout << i << ' ';
            cout << v << '\n';
        }
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    Graph G(n); G.Enter();
    int u, v, q;
    G.Floyd();
    while (x--){
        cin >> q >> u >> v;
        G.Queries(q, u, v);
    }
}
