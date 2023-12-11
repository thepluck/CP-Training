#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 5;
int par[N], dsu_2ecc[N], dsu_cc[N];
int cc_size[N], last_visit[N];
int bridges, lca_iter, n, m;

void init(){
    for (int i = 0; i < n; i++){
        dsu_2ecc[i] = dsu_cc[i] = i;
        cc_size[i] = 1; par[i] = -1;
        last_visit[i] = 0;
    }
    bridges = lca_iter = 0;
}

int find_2ecc(int v){
    if (v == -1) return -1;
    if (v != dsu_2ecc[v]) 
        dsu_2ecc[v] = find_2ecc(dsu_2ecc[v]);
    return dsu_2ecc[v];
}

int find_cc(int v){
    v = find_2ecc(v);
    if (v != dsu_cc[v])
        dsu_cc[v] = find_cc(dsu_cc[v]);
    return dsu_cc[v]; 
}

void make_root(int v){
    v = find_2ecc(v); 
    int root = v, child = -1;
    while (v != -1){
        int p = find_2ecc(par[v]);
        par[v] = child;
        dsu_cc[v] = root;
        child = v; v = p;
    }
    cc_size[root] = cc_size[child];
}

void merge_path(int u, int v){
    ++lca_iter; int lca = -1;
    vector <int> path_u, path_v;
    while (lca == -1){
        if (u != -1){
            u = find_2ecc(u);
            path_u.push_back(u);
            if (last_visit[u] == lca_iter)
                lca = u;
            last_visit[u] = lca_iter;
            u = par[u];
        }
        if (v != -1){
            v = find_2ecc(v);
            path_v.push_back(v);
            if (last_visit[v] == lca_iter)
                lca = v;
            last_visit[v] = lca_iter;
            v = par[v];
        }
    }
    for (int x : path_u){
        dsu_2ecc[x] = lca; 
        if (x == lca) break; --bridges;
    }
    for (int x : path_v){
        dsu_2ecc[x] = lca;
        if (x == lca) break; --bridges;
    }
}

void add_edge(int u, int v){
    u = find_2ecc(u); v = find_2ecc(v);
    if (u == v) return;
    int cu = find_cc(u), cv = find_cc(v);
    if (cu != cv){
        ++bridges;
        if (cc_size[cu] > cc_size[cv]){
            swap(u, v); swap(cu, cv);
        }
        make_root(u);
        par[u] = dsu_cc[u] = v;
        cc_size[cv] += cc_size[cu];
    }
    else merge_path(u, v);
}

void solve(){
    cin >> n >> m; init(); int u, v;
    while (m--){
        cin >> u >> v; add_edge(u, v);
        cout << bridges << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--) solve();
}