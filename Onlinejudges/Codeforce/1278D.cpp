#include <bits/stdc++.h>
using namespace std;

#define all(v) begin(v), end(v)
#define fi first
#define se second
#define eb emplace_back
using ii = pair <int, int>;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n; set <ii> cur;
    vector <vector <int>> adj(n);
    vector <ii> seg(n), cmp(2 * n);
    for (int i = 0; i < n; i++){
        cin >> seg[i].fi >> seg[i].se;
        cmp[i] = {seg[i].fi, i};
        cmp[i + n] = {seg[i].se, i};
    }
    sort(all(cmp)); int c = 0;
    for (int i = 0; i < 2 * n; i++){
        if (cur.count(cmp[i])) 
            cur.erase(cmp[i]);
        else {
            int id = cmp[i].se;
            int r = seg[id].se;
            for (auto ss : cur){
                if (ss.fi >= r) break;
                adj[id].eb(ss.se);
                adj[ss.se].eb(id);
                if (++c >= n)
                    return puts("NO"), 0;
            }
            cur.emplace(r, id);
        }
    }
    queue <int> q; vector <char> used(n);
    used[0] = 1; q.push(0);
    while (!q.empty()){
        int u = q.front(); q.pop();
        for (int v : adj[u])
            if (!used[v]){
                used[v] = true; q.push(v);
            }
    }
    if (count(all(used), 1) < n) puts("NO");
    else puts("YES");

}