#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define fi first
#define se second
using ii = pair <int, int>;

const int N = 2e5 + 5;
vector <int> pr, adj[N], vs[N];
int lp[N], a[N], n, ans, dis[2][N];
queue <int> q;

void sieve(){
    for (int i = 2; i < N; i++){
        if (!lp[i]) lp[i] = i, pr.eb(i);
        for (int j = 0; j < int(pr.size()) &&
        pr[j] <= lp[i] && i * pr[j] < N; j++)
            lp[i * pr[j]] = pr[j];
    }
}

ii bfs(int u, int p, int t){
    q.push(u); dis[t][u] = 1; ii res;
    while (!q.empty()){
        u = q.front(); q.pop();
        res = ii(u, dis[t][u]);
        for (int v : adj[u])
            if (!(~dis[t][v]) && a[v] % p == 0){
                dis[t][v] = dis[t][u] + 1; q.push(v);
            }
    }
    return res;
}

void calc(int p){
    for (int u : vs[p]) if (!(~dis[0][u]))
        ans = max(ans, bfs(bfs(u, p, 0).fi, p, 1).se);
    for (int u : vs[p]) dis[0][u] = dis[1][u] = -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); sieve();
    cin >> n;
    memset(dis, -1, sizeof dis);
    for (int i = 1; i <= n; i++){
        cin >> a[i]; int x = a[i], cur;
        while (x > 1){
            cur = lp[x]; vs[cur].eb(i);
            while (x % cur == 0) x /= cur;
        }
    }
    for (int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        adj[u].eb(v); adj[v].eb(u);
    }
    for (int i = 2; i < N; i++) calc(i);
    cout << ans << '\n';
}