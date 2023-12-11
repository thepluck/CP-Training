#include <bits/stdc++.h>
using namespace std;

template <class T, class _T>
bool chkmax(T &a, const _T &b){
    return a < b ? a = b, true : false;
}

template <class T, class _T>
bool chkmin(T &a, const _T &b){
    return a > b ? a = b, true : false;
}

const int N = 2e5 + 5;
vector <int> adj[N];
vector <int> meet[N / 2];
int dep[N], anc[N][19];
int n, root, q;

void dfs(int u, int par){
    for (auto v : adj[u])
        if (v != par){
            dep[v] = dep[u] + 1;
            dfs(v, u); anc[v][0] = u;
        }
}

void pre_calc(){
    dep[0] = -1; dfs(root, 0);
    for (int k = 1; k <= 18; k++)
        for (int i = 1; i <= n; i++)
            if (dep[i] >= (1 << k))
                anc[i][k] = anc[anc[i][k - 1]][k - 1];
}

int lca(int u, int v){
    if (dep[u] < dep[v]) return lca(v, u);
    for (int k = 18; k >= 0; k--)
        if (dep[anc[u][k]] >= dep[v])
            u = anc[u][k];
    /*for (int k = 18; k >= 0; k--)
        if (dep[anc[v][k]] >= dep[u])
            v = anc[v][k];*/
    if (u == v) return u;
    for (int k = 18; k >= 0; k--)
        if (anc[u][k] != anc[v][k]){
            u = anc[u][k]; v = anc[v][k];
        }
    return anc[u][0];
}

int get_max(int id){
    int ans = 0, u, v;
    u = meet[id][0];
    for (int i = 1; i < (int)meet[id].size(); i++){
        int w = meet[id][i];
        int dis = dep[u] + dep[w] - 2 * dep[lca(u, w)];
        if (dis > ans){
            ans = dis; v = w;
        }
    }
    for (auto w : meet[id])
        chkmax(ans, dep[v] + dep[w] - 2 * dep[lca(v, w)]);
    return ans;
}

void read_input(){
    cin >> n >> q;
    for (int u = 1; u <= n; u++){
        int id, v; cin >> id >> v;
        meet[id].push_back(u);
        if (v == 0) root = u;
        else {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
}

void process(){
    read_input(); pre_calc();
    for (int i = 1; i <= q; i++)
        cout << get_max(i) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    process(); return 0;
}