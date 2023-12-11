#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
using ll = long long;
const int C = 1e5 + 5;
const int N = 1e5 + 5;
const ll inf = 1e18;

struct line{
    ll a, b;

    line(): a(0), b(0){}

    line(ll a, ll b): a(a), b(b){}

    ll operator () (ll x){
        return a * x + b;
    }
};

struct node{
    line d; int lson, rson;

    node(): lson(0), rson(0){}

    node(line d): d(d), lson(0), rson(0){}

    ll operator () (ll x){
        return d(x);
    }
};

vector <node> s; ll dp[N], a[N], b[N];
int hv[N], in[N], out[N], ver[N], tim;
vector <int> adj[N];

void add_edge(int u, int v){
    adj[u].eb(v); adj[v].eb(u);
}

void insert(int i, int l, int r, line d){
    if (l + 1 == r){
        if (d(l) < s[i](l)) s[i].d = d;
        return;
    }
    int m = (l + r) / 2;
    if (d.a < s[i].d.a) swap(d, s[i].d);
    if (s[i](m) > d(m)){
        swap(s[i].d, d);
        if (s[i].rson) insert(s[i].rson, m, r, d);
        else {
            s.push_back(node(d));
            s[i].rson = s.size() - 1;
        }
    }
    else {
        if (s[i].lson) insert(s[i].lson, l, m, d);
        else {
            s.push_back(node(d));
            s[i].lson = s.size() - 1;
        }
    }
}

ll query(int i, int l, int r, ll x){
    if (l + 1 == r) return s[i](x);
    int m = (l + r) / 2;
    if (x < m && s[i].lson)
        return min(s[i](x), query(s[i].lson, l, m, x));
    else if (s[i].rson)
        return min(s[i](x), query(s[i].rson, m, r, x));
    return s[i](x);
}

int dfs_hv(int v, int p){
    int v_sz = 1, maxc_sz = 0, c_sz;
    in[v] = ++tim; ver[tim] = v;
    for (int c : adj[v]) if (c != p){
        v_sz += c_sz = dfs_hv(c, v);
        if (c_sz > maxc_sz){
            maxc_sz = c_sz; hv[v] = c;
        }
    }
    out[v] = tim; return v_sz;
}

void dfs_sol(int v, int p, bool cl){
    for (int c : adj[v])
        if (c != p && c != hv[v])
            dfs_sol(c, v, 1);
    if (hv[v]) dfs_sol(hv[v], v, 0);
    if (s.empty()) s.eb(line(0, inf));
    for (int c : adj[v])
        if (c != p && c != hv[v])
            for (int i = in[c]; i <= out[c]; i++)
                insert(0, -C, C, {b[ver[i]], dp[ver[i]]});
    dp[v] = hv[v] ? query(0, -C, C, a[v]) : 0;
    insert(0, -C, C, {b[v], dp[v]});
    if (cl) s.clear();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, u, v; cin >> n;
    for (int i = 1; i <= n; cin >> a[i++]);
    for (int i = 1; i <= n; cin >> b[i++]);
    for (int i = 1; i < n; i++){
        cin >> u >> v; add_edge(u, v);
    }
    dfs_hv(1, 0); dfs_sol(1, 0, 0);
    for (int i = 1; i <= n; i++)
        cout << dp[i] << " \n"[i == n];
}