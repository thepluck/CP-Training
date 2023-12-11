#define fi first
#define se second
#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef priority_queue <ii, vii, greater <ii> > pqii;

struct Graph{
    int n; vii *Edge;
    Graph(int n) : n(n) {
        Edge = new (nothrow) vii [n + 1];
    }
    void addEdge(int u, int v, int w){
        Edge[u].push_back(ii(v, w));
        Edge[v].push_back(ii(u, w));
    }
    void minPath(int s){
        pqii pq;
        int Dis[n + 1];
        fill(Dis, Dis + n + 1, INT_MAX);
        Dis[s] = 0; int u, v, cost; ii t;
        pq.push(ii(0, s));
        while (!pq.empty()){
            t = pq.top(); pq.pop(); u = t.se;
            if (t.fi > Dis[u]) continue;
            if (u == n){
                cout << Dis[n] << endl; goto gg;
            }
            for (auto i : Edge[u]){
                v = i.fi; cost = i.se;
                if (Dis[v] > Dis[u] + cost){
                    Dis[v] = Dis[u] + cost;
                    pq.push(ii(Dis[v], v));
                }
            }
        }
        gg:;
    }
};

int main(){
    int n, m, c; cin >> n >> m;
    Graph G(n * m);
    for (int i = 0; i < n; i++){
        for (int j = 1; j <= m; j++){
            cin >> c;
            if (i) G.addEdge((i - 1) * m + j, i * m + j, c);
            else G.addEdge(0, j, c);
        }
        for (int j = 1; j < m; j++){
            cin >> c;
            G.addEdge(i * m + j, i * m + j + 1, c);
        }
    }
    G.minPath(0);
    return 0;
}
