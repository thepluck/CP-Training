#include <bits/stdc++.h>
using namespace std;
 
#define eb emplace_back
#define ub upper_bound
#define all(v) (v).begin(), (v).end()
mt19937 rng(chrono::steady_clock::now().
time_since_epoch().count());
 
struct custom_hash{
    static int splitmix64(int x){
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    int operator()(int x) const {
        static const int FIXED_RANDOM = rng();
        return splitmix64(x + FIXED_RANDOM);
    }
};
 
const int N = 2e5 + 5;
int in[N], out[N], que[N], bit[N], ans[N];
int tim, cnt, n, ver[N], last[N], c[N];
vector <int> adj[N];

void dfs(int u, int p){
    ver[in[u] = ++tim] = u;
    for (int v : adj[u]) if (v != p) dfs(v, u);
    out[u] = tim; que[++cnt] = u;
}
 
void update(int i, int t){
    for (; i <= n; i += i & -i) bit[i] += t;
}
 
int query(int i){
    int res = 0;
    for (; i > 0; i -= i & -i) res += bit[i];
    return res;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n; vector <int> cmp;
    for (int i = 1; i <= n; i++){
        cin >> c[i]; cmp.eb(c[i]);
    }
    for (int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        adj[u].eb(v); adj[v].eb(u);
    }
    sort(all(cmp));
    cmp.resize(distance(cmp.begin(),
    unique(all(cmp))));
    for (int i = 1; i <= n; i++)
        c[i] = distance(cmp.begin(),
        ub(all(cmp), c[i]));
    dfs(1, 0);
    for (int i = 1; i <= n; i++){
        for (int j = out[que[i - 1]] + 1;
                    j <= out[que[i]]; j++){
            if (last[c[ver[j]]])
                update(last[c[ver[j]]], -1);
            update(last[c[ver[j]]] = j, 1);
        }
        ans[que[i]] = query(out[que[i]])
                    - query(in[que[i]] - 1);
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
}