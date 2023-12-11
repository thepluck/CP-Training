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
typedef vector <int> vi;

struct Graph{
    int n; vi* Edge;
    int *Low, *Num, *Trace;
    int cntcut = 0, cntbri = 0, cnt = 0;
    Graph(int n) : n(n) {
        Edge = new (nothrow) vi[n + 1];
        Low = new (nothrow) int[n + 1];
        Num = new (nothrow) int[n + 1];
        Trace = new (nothrow) int[n + 1];
        memset(Trace, 0, sizeof Trace);
        memset(Num, 0, sizeof Num);
        memset(Low, 0, sizeof Low);
    }
    void addEdge(int u, int v){
        Edge[u].push_back(v);
        Edge[v].push_back(u);
    }
    void Enter(){
        int m, u, v; read(m);
        while (m--){
            read(u); read(v); addEdge(u, v);
        }
    }
    void Dfs(int u){
        bool cond = 0; cnt++;
        Low[u] = Num[u] = cnt;
        int cntchild = 0;
        for (auto v : Edge[u])
            if (Num[v] == 0){
                cntchild++; Trace[v] = u; Dfs(v);
                if (Low[v] > Num[u]) cntbri++;
                if (Low[v] >= Num[u]) cond = 1;
                Low[u] = min(Low[v], Low[u]);
            }
            else if (v != Trace[u]){
                Low[u] = min(Low[u], Num[v]);
            }
        if (Trace[u] == 0){
            if (cntchild > 1) cntcut++;
        }
        else if (cond) cntcut++;
    }
    void Count(){
        for (int i = 1; i <= n; i++)
            if (Num[i] == 0) Dfs(i);
        write(cntcut); putchar(' '); write(cntbri);
    }
};

int main(){
    int n; read(n);
    Graph G(n); G.Enter();
    G.Count();
}
