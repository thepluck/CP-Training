#include <bits/stdc++.h>
#include "hoax.h"

using namespace std;

struct item {
    int t, type, id;
    item(int t, int type, int id):
    t(t), type(type), id(id) {}
    bool operator < (const item &oth){
        if (t != oth.t)
            return t < oth.t;
        return type > oth.type;
    }
};

struct DSU {
    vector<int> par, siz;
    
    DSU(int N = 0): par(N, -1), siz(N, 1) {}

    int root(int u) {
        return par[u] < 0 ? u : par[u] = root(par[u]);
    }
    void join(int u, int v) {
        u = root(u); v = root(v);
        if (u != v) {
            if (siz[u] < siz[v]) swap(u, v);
            siz[u] += siz[v]; par[v] = u;
        }
    }
    int size(int u){
        return siz[root(u)];
    }
} D;

void init(int N, int S, vector <int> T,
vector <vector <int>> A, vector <vector <int>> B) {
    vector <item> C;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < T[i]; j++) {
            C.emplace_back(A[i][j], 1, i);
            C.emplace_back(B[i][j], -1, i);
        }
    sort(C.begin(), C.end());
    vector <int> cur;
    int cnt = 0; D = DSU(N);
    for(item it : C){
        cnt += it.type;
        cur.push_back(it.id);
        if (!cnt) {
            while (cur.size() > 1) {
                D.join(cur[cur.size() - 1],
                cur[cur.size() - 2]);
                cur.pop_back();
            }
            cur.clear();
        }
    }
}

int count_users(int p) {
    return D.size(p);
}