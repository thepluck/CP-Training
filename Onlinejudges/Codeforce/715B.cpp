
// Problem : B. Complete The Graph
// Contest : Codeforces - Codeforces Round #372 (Div. 1)
// URL : https://codeforces.com/contest/715/problem/B
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define fi first
#define se second

using ii = pair <int, int>;

struct edge {
    int u, v, w;
    
    edge() {}
    
    edge(int u, int v, int w):
    u(u), v(v), w(w) {}
};

const int N = 1005;
const int M = 10005;
const int inf = 0x3f3f3f3f;

int n, m, s, t, l, k;
bool c[M]; edge ed[M];
vector <ii> g[N]; int d[2][N];
priority_queue <ii, vector <ii>,
greater <ii>> pq;

void input() {
    cin >> n >> m >> l >> s >> t;
    for (int i = 0; i < m; i++) {
        cin >> ed[i].u >> ed[i].v;
        cin >> ed[i].w;
        g[ed[i].u].eb(ed[i].v, i);
        g[ed[i].v].eb(ed[i].u, i);
    }
}

void process() {
    int u, v, w, i;
    fill_n(d[0], n, inf);
    pq.emplace(d[0][t] = 0, t);
    while (pq.size()) {
        tie(w, u) = pq.top(); pq.pop();
        if (d[0][u] < w) continue;
        for (ii e : g[u]) {
            tie(v, i) = e;
            if (!ed[i].w) continue;
            if (d[0][v] > w + ed[i].w) {
                d[0][v] = w + ed[i].w;
                pq.emplace(d[0][v], v);
            }
        }
    }
    fill_n(d[1], n, inf);
    pq.emplace(d[1][s] = 0, s);
    while (pq.size()) {
        tie(w, u) = pq.top(); pq.pop();
        if (d[1][u] < w) continue;
        for (ii e : g[u]) {
            tie(v, i) = e;
            if (!ed[i].w)
                ed[i].w = max(1,
                l - w - d[0][v]);
            if (d[1][v] > w + ed[i].w) {
                d[1][v] = w + ed[i].w;
                pq.emplace(d[1][v], v);
            }
        }
    }
}

void output() {
    if (d[1][t] != l) {
        cout << "NO\n"; return;
    }
    cout << "YES\n";
    for (int i = 0; i < m; i++) {
        cout << ed[i].u << ' ';
        cout << ed[i].v << ' ';
        ed[i].w = max(ed[i].w, 1);
        cout << ed[i].w << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    input(); process(); output();
}