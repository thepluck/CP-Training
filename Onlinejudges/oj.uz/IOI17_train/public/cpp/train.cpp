#include <bits/stdc++.h>

using namespace std;

vector<int> who_wins(vector<int> own,
vector <int> imp, vector<int> from, vector<int> to) {
    int n = own.size(), m = from.size();
    vector<int> deg(n), cnt(n), win(n);
    vector<vector<int>> adj(n);
    queue <int> que;
    for (int i = 0; i < m; i++) {
        adj[to[i]].push_back(from[i]);
        deg[from[i]]++;
    }
    for (bool flag = 1; flag; ) {
        fill(cnt.begin(), cnt.end(), 0);
        fill(win.begin(), win.end(), 0);
        for (int i = 0; i < n; i++)
            if (imp[i]) {
                que.push(i); win[i] = 1;
            }
        while (que.size()) {
            int u = que.front(); que.pop();
            for (int v : adj[u]) {
                if (win[v]) continue;
                if (own[v]) {
                    win[v] = 1; que.push(v);
                } else if (++cnt[v] == deg[v]) {
                    win[v] = 1; que.push(v);
                }
            }
        }
        flag = 0;
        for (int i = 0; i < n; i++)
            if (!win[i]) que.push(i);
        while (que.size()) {
            int u = que.front(); que.pop();
            if (imp[u]) {
                flag = true; imp[u] = 0;
            }
            for (int v : adj[u]) {
                if (!win[v]) continue;
                if (!own[v]) {
                    win[v] = 0; que.push(v);
                } else if (++cnt[v] == deg[v]) {
                    win[v] = 0; que.push(v);
                }
            }
        }
    }
    return win;
}
