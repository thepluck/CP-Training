#include <bits/stdc++.h>
using namespace std;

namespace fast_io{
    template <typename T>
    void read(T &x){
        char c; bool nega = 0; x = 0;
        while (!isdigit(c = getchar()) && c != '-');
        if (c == '-'){
            nega = 1; c = getchar();
        }
        for (; isdigit(c); c = getchar())
            x = (x << 1) + (x << 3) + c - 48;
        if (nega) x = -x;
    }

    template <typename T>
    void writep(T x){
        if (x > 9) writep(x / 10);
        putchar(x % 10 + 48);
    }

    template <typename T>
    void write(T x){
        if (x < 0){
            x = -x; putchar('-');
        }
        writep(x);
    }

    template <typename T>
    void writeln(T x){
        write(x); putchar('\n');
    }
}

struct edge{
    int v, w;
};

const int N = 2e5 + 5;
const int K = 1e6 + 5;
const int inf = 0x3f3f3f3f;
vector <edge> adj[N]; bitset <N> used; 
int sz[N], dis[N], tim, n, md[K], res;
int in[N], out[N], tr[N], k, dep[N];

void add_edge(int u, int v, int w){
    adj[u].push_back({v, w}); adj[v].push_back({u, w});
}

void dfs_sz(int v, int p){
    sz[v] = 1;
    for (auto e : adj[v])
        if (!used[e.v] && e.v != p){
            dfs_sz(e.v, v); sz[v] += sz[e.v];
        }
}

int dfs_cen(int v, int p, int r){
    for (auto e : adj[v])
        if (!used[e.v] && e.v != p && sz[e.v] * 2 >= sz[r])
            return dfs_cen(e.v, v, r);
    return v;
}

void dfs_dis(int v, int p){
    in[v] = ++tim; tr[tim] = v;
    for (auto e : adj[v])
        if (!used[e.v] && e.v != p){
            dis[e.v] = dis[v] + e.w; dep[e.v] = dep[v] + 1;
            if (dis[e.v] <= k) dfs_dis(e.v, v);
        }
    out[v] = tim;
}

void solve(int v){
    dfs_sz(v, 0); int cen = dfs_cen(v, 0, v);
    tim = 0; dis[cen] = 0; dep[cen] = 0;
    dfs_dis(cen, 0); used[cen] = 1; md[0] = 0;
    for (auto e : adj[cen]) if (!used[e.v] && dis[e.v] <= k){
        for (int i = in[e.v]; i <= out[e.v]; i++)
            res = min(res, dep[tr[i]] + md[k - dis[tr[i]]]);
        for (int i = in[e.v]; i <= out[e.v]; i++)
            md[dis[tr[i]]] = min(md[dis[tr[i]]], dep[tr[i]]);
    }
    for (int i = in[cen]; i <= out[cen]; i++) 
        md[dis[tr[i]]] = inf;
    for (auto e : adj[cen]) if (!used[e.v]) solve(e.v);
}

int main(){
    using namespace fast_io;
    memset(md, 0x3f, sizeof md);
    read(n); read(k); res = n;
    for (int i = 1, u, v, w; i < n; i++){
        read(u); read(v); read(w);
        u++; v++; add_edge(u, v, w);
    }
    solve(1); if (res == n) res = -1;
    writeln(res); return 0;
}