#include <bits/stdc++.h>
using namespace std;

int Dis[102][100010];
const int inf = 0x3f3f3f3f;
struct data{
    int dis, cost, node;
    data (int dis, int cost, int node) :
        dis(dis), cost(cost), node(node) {}
    data () {}
    bool operator < (const data &other) const {
        return dis > other.dis;
    }
};

struct Graph{
    int n, k, m; vector <data>* Edge;
    Graph(int n, int k, int m) : n(n), k(k), m(m) {
        Edge = new (nothrow) vector <data> [n + 1];
    }
    void addEdge(int u, int v, int dis, int cost){
        Edge[u].push_back(data(dis, cost, v));
    }
    void Enter(){
        int u, v, dis, cost;
        for (int i = 0; i < m; i++){
            cin >> u >> v >> dis >> cost;
            addEdge(u, v, dis, cost);
        }
    }
    void minPath(int s){
        int ans = -1;
        memset(Dis, 0x3f3f3f3f, sizeof Dis);
        Dis[s][0] = 0;
        priority_queue <data> pq;
        pq.push(data(0, 0, s));
        int u, v, c, d; data t;
        while (!pq.empty()){
            t = pq.top(); pq.pop();
            u = t.node;
            if (t.dis > Dis[u][t.cost]) continue;
            if (u == n){
                ans = Dis[u][t.cost];
                goto gg;
            }
            for (data i : Edge[u]){
                v = i.node; c = i.cost;
                d = i.dis;
                if (t.cost + c > k) continue;
                if (Dis[v][t.cost + c] > d + Dis[u][t.cost]){
                    Dis[v][t.cost + c] = d + Dis[u][t.cost];
                    pq.push(data(Dis[v][t.cost + c], t.cost + c, v));
                }
            }
        }
        gg: cout << ans << '\n';
    }
};

int main(){
    //freopen("dijkstra.inp", "rt", stdin);
    //freopen("dijkstra.out", "wt", stdout);
    int t; cin >> t;
    while (t--){
        int n, m, k; cin >> k >> n >> m;
        Graph G(n, k, m);
        G.Enter(); G.minPath(1);
    }
}
