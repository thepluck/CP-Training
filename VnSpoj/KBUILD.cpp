#include <bits/stdc++.h>
using namespace std;

namespace fastio{
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

template <class X, class Y>
bool chkmin(X &a, const Y &b){
    return a > b ? a = b, 1 : 0;
}

const int N = 2e5 + 5;
int low[N], num[N], trace[N];
int n, m, color, bridge;
vector <int> adj[N];

void dfs(int u){
    low[u] = num[u] = ++color;
    for (int v : adj[u])
        if (num[v] == 0){
            trace[v] = u; dfs(v);
            if (low[v] > num[u]) bridge++;
            chkmin(low[u], low[v]);
        }
        else if (v != trace[u])
            chkmin(low[u], num[v]);
}

int main(){
    using fastio::read;
    read(n); int u, v;
    for (int i = 1; i < n; i++){
        read(u); read(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    read(m);
    for (int i = 0; i < m; i++){
        read(u); read(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        if (num[i] == 0) dfs(i);
    fastio::writeln(bridge);
}