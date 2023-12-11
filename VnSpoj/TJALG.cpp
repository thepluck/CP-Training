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
typedef pair <int, int> ii;
typedef long long ll;

const int inf = 0x3f3f3f3f;

struct Graph{
    int n; vi* Edge; bool* Avail;
    int *Num, *Low; int cnt = 0, scc = 0;
    stack <int> st;
    Graph(int n) : n(n) {
        Edge = new (nothrow) vi[n + 1];
        Avail = new (nothrow) bool[n + 1];
        fill(Avail + 1, Avail + n + 1, 1);
        Num = new (nothrow) int[n + 1];
        Low = new (nothrow) int[n + 1];
        memset(Num, 0, sizeof Num);
    }
    void addEdge(int u, int v){
        Edge[u].push_back(v);
    }
    void Enter(){
        int m, u, v; read(m);
        while (m--){
            read(u); read(v);
            addEdge(u, v);
        }
    }
    void Dfs(int u){
        cnt++; Low[u] = Num[u] = cnt; st.push(u);
        for (auto v : Edge[u])
            if (Avail[v]){
                if (Num[v] != 0)
                    Low[u] = min(Low[u], Num[v]);
                else {
                    Dfs(v);
                    Low[u] = min(Low[u], Low[v]);
                }
            }
        if (Low[u] == Num[u]){
            scc++; int v;
            do {
                v = st.top(); st.pop();
                Avail[v] = 0;
            }
            while (u != v);
        }
    }
    int Cpn(){
        for (int i = 1; i <= n; i++)
            if (Avail[i]) Dfs(i);
        return scc;
    }
};

int main(){
    int n; read(n);
    Graph G(n); G.Enter();
    cout << G.Cpn();
}
