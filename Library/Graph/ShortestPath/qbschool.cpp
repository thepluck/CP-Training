#define fi first
#define se second
#include <bits/stdc++.h>
using namespace std;

typedef vector <int> vi;
typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef long long ll;
const int inf = 0x3f3f3f3f;

struct Graph{
    int n; vii* Edge;
    Graph(int n) : n(n) {
        Edge = new (nothrow) vii[n + 1];
    }
    void addEdge(int k, int u, int v, int w){
        Edge[u].push_back(ii(v, w));
        if (k == 2) Edge[v].push_back(ii(u, w));
    }
    void Enter(){
        int m, k, u, v, w; cin >> m;
        while (m--){
            cin >> k >> u >> v >> w;
            addEdge(k, u, v, w);
        }
    }
    void numPath(){
        int Dis[n + 1];
        long long cnt[n + 1];
        memset(Dis, 0x3f, sizeof Dis);
        memset(cnt, 0, sizeof cnt);
        Dis[1] = 0; cnt[1] = 1;
        priority_queue <ii, vii, greater <ii> > pq;
        pq.push(ii(0, 1)); int u, v, cost; ii t;
        while (!pq.empty()){
            t = pq.top(); pq.pop();
            u = t.se;
            if (Dis[u] < t.fi) continue;
            if (u == n) break;
            for (ii i : Edge[u]){
                v = i.fi; cost = i.se;
                if (Dis[v] == Dis[u] + cost) cnt[v] += cnt[u];
                else if (Dis[v] > Dis[u] + cost)
                    Dis[v] = Dis[u] + cost,
                    cnt[v] = cnt[u],
                    pq.push(ii(Dis[v], v));
            }
        }
        cout << Dis[n] << ' ' << cnt[n];
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    Graph G(n); G.Enter();
    G.numPath();
}
