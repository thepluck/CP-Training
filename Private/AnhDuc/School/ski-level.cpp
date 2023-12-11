#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
using ll = long long;
const int N = 505;
int h[N][N], n, m, t; bool st[N][N];

struct node{
    int x, y;

    node(): x(0), y(0){}

    node(int x, int y): x(x), y(y){}

    bool operator != (const node &o){
        return x != o.x || y != o.y;
    }

    bool operator == (const node &o){
        return x == o.x && y == o.y;
    }
};

struct edge{
    node u, v; int w;

    edge(): w(0){}

    edge(node u, node v, int w): u(u), v(v), w(w){}

    bool operator < (const edge &o) const {
        return w < o.w;
    }
};

node anc[N][N]; int sz[N][N], cnt[N][N];

node find_set(node u){
    if (u != anc[u.x][u.y])
        anc[u.x][u.y] = find_set(anc[u.x][u.y]);
    return anc[u.x][u.y];
}

node union_set(node u, node v){
    u = find_set(u); v = find_set(v);
    if (u == v) return u;
    if (sz[u.x][u.y] >= sz[v.x][v.y]){
        sz[u.x][u.y] += sz[v.x][v.y];
        cnt[u.x][u.y] += cnt[v.x][v.y];
        anc[v.x][v.y] = u; return u;
    }
    else {
        sz[v.x][v.y] += sz[u.x][u.y];
        cnt[v.x][v.y] += cnt[u.x][u.y];
        anc[u.x][u.y] = v; return v;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> t;
    vector <edge> lst; ll res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> h[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> cnt[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            if (i < n){
                auto u = node(i, j), v = node(i + 1, j);
                lst.eb(u, v, abs(h[i][j] - h[i + 1][j]));
            }
            if (j < m){
                auto u = node(i, j), v = node(i, j + 1);
                lst.eb(u, v, abs(h[i][j] - h[i][j + 1]));
            }
        }
    sort(lst.begin(), lst.end());
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            anc[i][j] = node(i, j); sz[i][j] = 1;
        }
    for (auto e : lst){
        auto r = union_set(e.u, e.v);
        if (sz[r.x][r.y] >= t){
            res += 1ll * cnt[r.x][r.y] * e.w;
            cnt[r.x][r.y] = 0;
        }
    }
    cout << res << '\n';
}