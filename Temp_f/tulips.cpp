#include <bits/stdc++.h>
using namespace std;

struct edge{
    int u, v, w;

    bool operator < (const edge &o){
        return w < o.w;
    }
};

using ii = pair <int, int>;

const int N = 2e5 + 5;
int tree[N], tag[N], lo[N], hi[N], p[N];
int par[N], rnk[N], ls[N], rs[N], dep[N];
int anc[18][N], in[N], out[N], tim, w[N];
edge lst[N]; 

void build(int i, int l, int r){
    lo[i] = l; hi[i] = r;
    if (l != r){
        int m = (l + r) / 2;
        build(i * 2, l, m);
        build(i * 2 + 1, m + 1 , r);
    }
}

void push_tag(int i, int tg){
    tree[i] = (hi[i] - lo[i] + 1) * tg;
    tag[i] = tg;
}

void push_down(int i){
    if (tag[i] == -1) return;
    if (lo[i] != hi[i]){
        push_tag(i * 2, tag[i]);
        push_tag(i * 2 + 1, tag[i]);
    }
    tag[i] = -1;
}

void push_up(int i){
    tree[i] = tree[i * 2] + tree[i * 2 + 1];
}

void set_val(int i, int l, int r, int tg){
    push_down(i);
    if (lo[i] > r || hi[i] < l) return;
    if (lo[i] >= l && hi[i] <= r)
        return push_tag(i, tg);
    set_val(i * 2, l, r, tg);
    set_val(i * 2 + 1, l, r, tg);
    push_up(i);
}

int query(int i, int l, int r){
    push_down(i);
    if (lo[i] > r || hi[i] < l) return 0;
    if (lo[i] >= l && hi[i] <= r)
        return tree[i];
    return query(i * 2, l, r) +
            query(i * 2 + 1, l, r);
}

int find_set(int u){
    if (u != par[u])
        par[u] = find_set(par[u]);
    return par[u];
}

int union_set(int u, int v){
    u = find_set(u); v = find_set(v);
    if (u == v) return u;
    if (rnk[u] == rnk[v]) rnk[u]++;
    if (rnk[u] > rnk[v]){
        par[v] = u; return u;
    }
    else {
        par[u] = v; return v;
    }
}

void dfs(int u){
    if (ls[u]){
        dep[ls[u]] = dep[u] + 1;
        anc[0][ls[u]] = u;
        dfs(ls[u]); in[u] = in[ls[u]];
    }
    else in[u] = ++tim;
    if (rs[u]){
        dep[rs[u]] = dep[u] + 1;
        anc[0][rs[u]] = u; dfs(rs[u]);
    }
    out[u] = tim; deque <ii> dq;
}

void solve(){
    int n, ver; cin >> n; ver = n;
    for (int i = 1; i < n; i++){
        cin >> lst[i].u >> lst[i].v;
        cin >> lst[i].w;
    }
    iota(par + 1, par + n + 1, 1);
    iota(p + 1, p + n + 1, 1);
    sort(lst + 1, lst + n);
    for (int i = 1; i < n; i++){
        ls[++ver] = p[lst[i].u];
        rs[ver] = p[lst[i].v];
        w[ver] = lst[i].w;
        p[union_set(lst[i].u, lst[i].v)] = ver;
    }
    tim = 0; dfs(ver); dep[0] = -1;
    for (int k = 1; k < 18; k++)
        for (int u = 1; u <= n; u++)
            if (dep[u] >= (1 << k))
                anc[k][u] = anc[k - 1][anc[k - 1][u]];
    
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

}