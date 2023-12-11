#include "teleport.h"
#include <bits/stdc++.h>

struct item {
    int v, x, y;

    item(int v, int x, int y): v(v), x(x), y(y) {}
};

namespace {
    using namespace std;

    const int N = 205;

    int node = 1, dis[N][N];
    vector<int> adj[N];
    vector<item> stk;


    void dfs(int u) {
        stk.emplace_back(u, ask_last_teleporter(), -1);
        change_news_channel(1);
        int edge = ask_count_teleporters();
        for (int i = 0; i < edge; i++) {
            use_teleporter(i);
            stk.back().y = i;
            if (ask_news_channel() == 0) {
                adj[u].push_back(node);
                adj[node].push_back(u);
                dfs(node++);
            } else {
                change_news_channel(2);
                use_teleporter(ask_last_teleporter());
                int j = stk.size() - 1;
                while (j > 0 && ask_news_channel() != 2)
                    use_teleporter(stk[j--].x);
                if (ask_news_channel() == 2) {
                    adj[u].push_back(stk[j].v);
                    adj[stk[j].v].push_back(u);
                }
                change_news_channel(1);
                while (j + 1 < stk.size())
                    use_teleporter(stk[j++].y);
            }
        }
        if (stk.back().x >= 0)
            use_teleporter(stk.back().x);
        stk.pop_back();
    }
}

vector<int> explore(int n, int x) {
    for (int i = 0; i < n; i++)
        adj[i].clear();
    node = 1; dfs(0);
    memset(dis, -1, sizeof dis);
    for (int i = 0; i < n; i++) {
        dis[i][i] = 0;
        queue<int> que; que.push(i);
        while (que.size()) {
            int u = que.front(); que.pop();
            for (int v : adj[u])
                if (dis[i][v] < 0) {
                    dis[i][v] = dis[i][u] + 1;
                    que.push(v);
                }
        }
    }
    vector<int> ans(n);
    for (int u = 0; u < n; u++)
        for (int v = u; v < n; v++)
            ans[dis[u][v]]++;
    return ans;
}
