#include "supertrees.h"
#include <bits/stdc++.h>

using namespace std;

int construct(vector <vector <int>> p) {
	int n = p.size();
	vector <vector <int>> b(n, vector <int> (n));
        vector <int> vis(n), root(n), cmp;
        auto add_edge = [&](int u, int v) {
            b[u][v] = b[v][u] = 1;
        };
        queue <int> que;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (p[i][j] == 3) return 0;
        for (int i = 0, u; i < n; i++) {
            if (vis[i]) continue;
            vis[i] = root[i] = 1;
            que.push(i); cmp.clear();
            while (que.size()) {
                u = que.front(); que.pop();
                cmp.push_back(u);
                for (int v = 0; v < n; v++)
                    if (p[u][v] == 1 && !vis[v]) {
                        vis[v] = 1; que.push(v);
                    }
            }
            for (int j = 1; j < cmp.size(); j++) {
                add_edge(cmp[j - 1], cmp[j]);
                for (int k = 0; k < j; k++)
                    if (p[cmp[j]][cmp[k]] != 1)
                        return 0;
            }
        }
        fill(vis.begin(), vis.end(), 0);
        for (int i = 0, u; i < n; i++) {
            if (!root[i] || vis[i]) continue;
            vis[i] = 1; que.push(i); cmp.clear();
            while (que.size()) {
                u = que.front(); que.pop();
                cmp.push_back(u);
                for (int v = 0; v < n; v++)
                    if (root[v] && p[u][v] == 2 && !vis[v]) {
                        vis[v] = 1; que.push(v);
                    }
            }
            if (cmp.size() == 2) return 0;
            if (cmp.size() == 1) continue;
            add_edge(cmp.front(), cmp.back());
            for (int j = 1; j < cmp.size(); j++) {
                add_edge(cmp[j - 1], cmp[j]);
                for (int k = 0; k < j; k++)
                    if (p[cmp[k]][cmp[j]] != 2)
                        return 0;
            }
        }
        build(b); return 1;
}
