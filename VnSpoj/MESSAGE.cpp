#include <bits/stdc++.h>
using namespace std;

template <typename T> inline void read(T &x){
    register char c;
    bool nega = 0;
    while((!isdigit(c = getchar())) && (c != '-'));
    if (c == '-'){
        nega = 1;
        c = getchar();
    }
    x = c - 48;    while (isdigit(c = getchar()))
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

int par[1000], rnk[1000];
typedef vector <int> vi;

vi Adj[1000]; bool Avail[1000], inStack[1000];
stack <int> s; int cnt[1000];

int find_set(int u){
    if (u != par[u]) par[u] = find_set(par[u]);
    return par[u];
}

void union_set(int u, int v){
    u = find_set(u);
    v = find_set(v);
    if (rnk[u] == rnk[v]) rnk[u]++;
    if (rnk[v] > rnk[u]) par[u] = v;
    else par[v] = u;
}

void dfs(int u){
    s.push(u); Avail[u] = 0;
    inStack[u] = 1;
    for (auto v : Adj[u]){
        if (inStack[v]){
            v = find_set(v);
            while (s.top() != v){
                par[s.top()] = v;
                s.pop();
            }
        }
        if (Avail[v]) dfs(v);
    }
    inStack[u] = 0;
    if (s.top() == u) s.pop();
}

int main(){
    int n, m; read(n); read(m);
    for (int i = 0, u, v; i < m; i++){
        read(u); read(v);
        Adj[u].push_back(v);
    }
    fill(Avail + 1, Avail + n + 1, 1);
    for (int i = 1; i <= n; i++) par[i] = i;
    for (int i = 1; i <= n; i++)
        if (Avail[i]) dfs(i);
    for (int i = 1; i <= n; i++) cnt[i] = (i == par[i]);
    for (int u = 1; u <= n; u++)
        for (auto v : Adj[u])
            if (find_set(u) != find_set(v)) cnt[find_set(v)] = 0;
    int res = 0;
    for (int i = 1; i <= n; i++) res += cnt[i];
    write(res);
}
