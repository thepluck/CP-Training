#include "network.h"
#include <bits/stdc++.h>

using namespace std;

struct HopcroftKarp {
    vector <int> mat, dis;
    int N; queue <int> que;
    vector <vector <int>> adj;
    vector <char> vis;

    void init(int N) {
        this->N = N;
        mat.assign(N + 5, -1);
        dis.assign(N + 5, -1);
        vis.assign(N + 5, 0);
        adj.assign(N + 5, vector <int> ());
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool BFS() {
        for (int u = 0; u < N; u++)
            if (mat[u] < 0) {
                dis[u] = 0; que.push(u);
            }
            else dis[u] = -1;
        bool flag = 0;
        while (que.size()) {
            int u = que.front(); que.pop();
            for (int v : adj[u])
                if (mat[v] < 0) flag = true;
                else if (dis[mat[v]] < 0) {
                    dis[mat[v]] = dis[u] + 1;
                    que.push(mat[v]);
                }
        }
        return flag;
    }

    bool DFS(int u) {
        for (int v : adj[u])
            if (mat[v] < 0 || (dis[mat[v]]
            == dis[u] + 1 && DFS(mat[v]))) {
                mat[v] = u; mat[u] = v;
                return true;
            }
        dis[u] = -1; return false;
    }

    int maxMatching() {
        int matching = 0;
        while (BFS())
            for (int u = 0; u < N; u++)
                if (mat[u] < 0)
                    matching += DFS(u);
        return matching;
    }

    vector <int> maxIndSet
    (const vector <int> &L,
    const vector <int> &R) {
        maxMatching();
        for (int u : L) 
            if (mat[u] < 0) que.push(u);
        for (int v : R)
            if (mat[v] < 0) que.push(v);
        while (que.size()) {
            int u = que.front(); que.pop();
            for (int v : adj[u])
                if (!vis[v]) {
                    vis[v] = true;
                    que.push(mat[v]);
                }
        }
        vector <int> ans;
        for (int u : L)
            if (mat[u] >= 0 && !vis[u]
            && !vis[mat[u]]) vis[u] = true;
        for (int u : L)
            if (!vis[u]) ans.push_back(u);
        for (int v : R)
            if (!vis[v]) ans.push_back(v);
        return ans;
    }
};

struct point {
    int x, y;

    point(int x = 0, int y = 0): x(x), y(y) {}

    point& operator += (const point &o) {
        x += o.x; y += o.y; return *this;
    }

    point& operator -= (const point &o) {
        x -= o.x; y -= o.y; return *this;
    }

    point& operator *= (const int &k) {
        x *= k; y *= k; return *this;
    }

    point operator + (const point &o) const {
        return point(*this) += o;
    }

    point operator - (const point &o) const {
        return point(*this) -= o;
    }

    point operator * (const int &k) const {
        return point(*this) *= k;
    }
};

int dot(const point &a, const point &b) {
    return a.x * b.x + a.y * b.y;
}

int cross(const point &a, const point &b) {
    return a.x * b.y - a.y * b.x;
}

int orient(const point &a,
const point &b, const point &c) {
    return cross(b - a, c - b);
}

int norm(const point &p) {
    return dot(p, p);
}

int abs(const point &p) {
    return sqrt(norm(p));
}

bool ccw(const point &a,
const point &b, const point &c) {
    return orient(a, b, c) > 0;
}

bool cw(const point &a,
const point &b, const point &c) {
    return orient(a, b, c) < 0;
}

vector <int> getMaximumSubset
(int N, int D, int subtask, int X[], int Y[]) {
    HopcroftKarp HK; D *= D;
    vector <point> P(N);
    for (int i = 0; i < N; i++)
        P[i] = {X[i], Y[i]};
    vector <int> ans(1, 0), cur;
    for (int i = 0; i + 1 < N; i++)
        for (int j = i + 1; j < N; j++)
            if (norm(P[i] - P[j]) <= D) {
                int d = norm(P[i] - P[j]);
                vector <int> lef, rig;
                for (int x = 0; x < N; x++)
                    if (max(norm(P[x] - P[i]),
                    norm(P[x] - P[j])) <= d) {
                        if (ccw(P[i], P[x], P[j]))
                            lef.push_back(x);
                        else rig.push_back(x);
                    }
                HK.init(N);
                for (int x : lef)
                    for (int y : rig)
                        if (norm(P[x] - P[y]) > d)
                            HK.addEdge(x, y);
                cur = HK.maxIndSet(lef, rig);
                if (cur.size() > ans.size())
                    ans = cur;
            }
    return ans;
}