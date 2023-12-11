#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int up[maxn];

int findset(int u){
    if (up[u] == u) return u;
    else return up[u] = findset(up[u]);
}

bool same(int u, int v){
    return findset(u) == findset(v);
}

void bunion(int u, int v){
    up[findset(u)] = findset(v);
}

int main(){
    int n; cin >> n;
    int c, u, v;
    for (int i = 1; i <= n; i++) up[i] = i;
    for (int i = 1; i <= n; i++){
        cin >> u >> v >> c;
        if (c == 2) cout << same(u, v) << ' ';
        else bunion (u, v);
    }
}