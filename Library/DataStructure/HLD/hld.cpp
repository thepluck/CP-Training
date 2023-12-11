const int MAXN = 100005;

vector <int> adj[MAXN];
int par[MAXN], dep[MAXN], heavy[MAXN];
int tin[MAXN], tout[MAXN], siz[MAXN];
int timer, head[MAXN], N, Q, wpar[MAXN];

void DFS1(int u) {
    siz[u] = 1;
    for (int v : adj[u]) {
		dep[v] = dep[u] + 1; DFS1(v);
        siz[u] += siz[v];
        if (siz[heavy[u]] < siz[v])
            heavy[u] = v; 
    }
}
 
void DFS2(int u) {
    tin[u] = ++timer;
    if (par[u] && u == heavy[par[u]])
        head[u] = head[par[u]];
    else head[u] = u;
    if (heavy[u]) DFS2(heavy[u]);
    for (int v : adj[u])
        if (v != par[u] && v != heavy[u])
            DFS2(v);
    tout[u] = timer;
}
