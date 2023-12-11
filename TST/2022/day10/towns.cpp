#include "towns.h"
#include <bits/stdc++.h>

namespace {
    using namespace std;
    
    const int N = 115;

    int dis[N][N];

    int getDis(int i, int j) {
        if (i == j) return 0;
        if (dis[i][j] >= 0) return dis[i][j];
        return dis[i][j] = dis[j][i] = getDistance(i, j);
    }

    mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
}

int hubDistance(int n, int sub) {
    memset(dis, -1, sizeof dis);

    int u = 0;
    for (int i = 0; i < n; i++)
        if (getDis(0, i) > getDis(0, u)) u = i;
    int v = u;
    for (int i = 0; i < n; i++)
        if (getDis(u, i) > getDis(u, v)) v = i;
    int res = 1e9;
    for (int w = 0; w < n; w++) {
        int ab = getDis(u, v);
        int ac = getDis(u, w);
        int bc = getDis(v, w);
        int abc = (ab + bc + ac) / 2;
        res = min(res, max(abc - ac, abc - bc));
    }
    if (sub == 3) {
        for (int u = 0; u < n; u++)
            for (int v = u + 1; v < n; v++)
                for (int w = v + 1; w < n; w++) {
                    int du, dv;
                    int s = (getDis(u, v) +
                    getDis(v, w) + getDis(u, w)) / 2;
                    du = s - getDis(v, w);
                    dv = s - getDis(u, w);
                    vector<pair<int, int>> root;
                    root.emplace_back(u, du);
                    root.emplace_back(v, dv);
                    for (int x = 0; x < n; x++)
                        if (getDis(u, x) + getDis(u, v) - getDis(v, x) == du * 2)
                            root.emplace_back(x, (getDis(x, u) + getDis(x, v) - getDis(u, v)) / 2);
                    bool flag = false;
                    for (int i = 0; i < root.size(); i++) {
                        int x, d, cnt = 0; tie(x, d) = root[i];
                        for (int y = 0; y < n; y++)
                            if (getDis(x, y) + getDis(x, u) - getDis(u, y) <= d * 2)
                                cnt++;
                        if (cnt > n / 2) 
                    }
                }
    }
    return res;
}