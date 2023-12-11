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

const int N = 5005;
const int M = 120005;
const int inf = INT_MAX;
struct arc{
    int to, nxt, rev, cap;
};
int head[N], h[N], n, m, s, t, ptr[N], maxh, works, exc[N];
vector <int> act[N]; set <int> vs[N]; arc g[2 * M];

void push(int u, arc &e){
    if (exc[e.to] == 0) 
        act[h[e.to]].push_back(e.to);
    int d = min(exc[u], e.cap);
    exc[u] -= d; exc[e.to] += d; 
    e.cap -= d; g[e.rev].cap += d;
}

void relabel(int u){
    ++works; int minh = 2 * n;
    for (int i = head[u]; i; i = g[i].nxt)
        if (g[i].cap) minh = min(minh, h[g[i].to]);
    if (vs[h[u]].size() == 1){
        for (int i = h[u]; i < n; i++){
            for (int v : vs[i]) h[v] = n;
            act[i].clear(); vs[i].clear();
        }
        return;
    }
    vs[h[u]].erase(u);
    if ((h[u] = minh + 1) < n) 
        vs[maxh = h[u]].insert(u);
}

void discharge(int u){
    int &i = ptr[u];
    while (exc[u]){
        if (i == 0){
            relabel(u); i = head[u]; 
                if (h[u] >= n) break;
        }
        else {
            if (g[i].cap && h[u] > h[g[i].to]) 
                push(u, g[i]);
            else i = g[i].nxt;
        }
    }
}

void global_relabel(){
    for (int i = 1; i <= n; i++){
        ptr[i] = head[i]; h[i] = n;
        act[i].clear(); vs[i].clear();
    }
    maxh = -1; works = 0; queue <int> q;
    h[t] = 0; q.push(t);
    while (!q.empty()){
        int u = q.front(); q.pop(); vs[h[u]].insert(u);
        for (int i = head[u]; i; i = g[i].nxt)
            if (g[g[i].rev].cap && h[g[i].to] == n){
                h[g[i].to] = h[u] + 1; q.push(g[i].to);
                if (exc[g[i].to]) 
                    act[maxh = h[g[i].to]].push_back(g[i].to);
            }
    }
}

int max_flow(){
    exc[s] = inf; exc[t] = -inf;
    for (int i = head[s]; i; i = g[i].nxt);
    global_relabel();
    for (; maxh >= 0; maxh--)
        while (!act[maxh].empty()){
            int u = act[maxh].back(); 
            act[maxh].pop_back();
            discharge(u); 
            if (works > 4 * n) global_relabel();
        }
    return exc[t] + inf;
}

int main(){
    using namespace fast_io;
    read(n); read(m); read(s); read(t);
    for (int i = 1, u, v, c; i <= m; i++){
        read(u); read(v); read(c);
        g[i] = {v, head[u], i + m, c};
        g[i + m] = {u, head[v], i, 0};
        head[u] = i; head[v] = i + m;
    }
    writeln(max_flow());
}