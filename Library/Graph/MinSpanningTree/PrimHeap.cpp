#define fi first
#define se second
#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef vector <ii> vii;

struct Graph{
    int n; vii* Adj;
    Graph(int n) : n(n), Adj(new (nothrow) vii[n + 1]) {}
    void addEdge(int u, int v, int w){
        Adj[u].push_back(ii(w, v));
        Adj[v].push_back(ii(w, u));
    }
    void Enter(){
        int m, u, v, w; cin >> m;
        while (m--){
            cin >> u >> v >> w;
            addEdge(u, v, w);
        }
    }
    int Prim(){
        priority_queue <ii, vii, greater <ii> > pq;
        bool Chosen[n + 1]; int total = 0;
        memset(Chosen, 0, sizeof Chosen);
        pq.push({0, 1}); ii tmp; int u;
        while (!pq.empty()){
            while (!pq.empty() && Chosen[pq.top().se]) pq.pop();
            if (pq.empty()) break;
            tmp = pq.top(); pq.pop();
            u = tmp.se; total += tmp.fi;
            Chosen[u] = true; //cout << u << '\n';
            for (auto v : Adj[u]) pq.push(v);
        }
        return total;
    }
};

int main(){
    int n; cin >> n;
    Graph G(n); G.Enter();
    cout << G.Prim();
}
