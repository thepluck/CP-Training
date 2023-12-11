#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
template <typename T> inline void read(T &x){
    char c;
    bool nega = 0;
    while((!isdigit(c = getchar())) && (c != '-'));
    if (c == '-'){
        nega = 1;
        c = getchar();
    }
    x = c - 48;
    while (isdigit(c = getchar()))
        x = x * 10 + c - 48;
    if (nega)
        x = -x;
}
template <typename T> inline void writep(T x){
    if(x > 9) writep(x / 10);
    putchar(x % 10 + 48);
}
template <typename T> inline void write(T x){
    if (x < 0){
        putchar('-');
        x = -x;
    }
    writep(x);
}
template <typename T> inline void writeln(T x){
    write(x);
    putchar('\n');
}
struct Edge{
    int u, v, w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
    Edge() {}
};

bool operator < (Edge& a, Edge& b){
    return a.w > b.w;
}
typedef vector <int> vi;
ll res = 0;
struct Dsu{
    vi par, rate;
    Dsu(int n) : par(n + 1), rate(n + 1, 0) {
        for (int i = 1; i <= n; i++) par[i] = i;
    }
    int find_set(int u){
        if (u != par[u]) par[u] = find_set(par[u]);
        return par[u];
    }
    bool union_set(int u, int v){
        u = find_set(u); v = find_set(v);
        if (u == v) return false;
        if (rate[u] == rate[v]) rate[u]++;
        if (rate[u] > rate[v]) par[v] = u;
        else par[u] = v;
        return true;
    }
};

int main(){
    int n, m; read(n); read(m);
    vector <Edge> Adj(m);
    for (auto &e : Adj){
        read(e.u); read(e.v); read(e.w);
        res += e.w;
    }
    sort(Adj.begin(), Adj.end());
    Dsu D(n);
    for (auto &e : Adj)
        if (D.union_set(e.u, e.v)) res -= e.w;
    write(res); return 0;
}
