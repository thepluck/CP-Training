#include "species.h"
#include <bits/stdc++.h>

namespace {
    using namespace std;

    const int N = 1000005;

    int idx[N], sum[N];
    vector<int> adj[N], ch[N][2];
}

void init(string val, vector<int> par) {
    int n = val.size();
    val = "A" + val; val[1] = 'A';
    for (int i = 1; i < n; i++)
        adj[par[i] + 1].push_back(i + 1);
    vector<int> stk(1, 1);
    int cnt = 1, l = 1, r = 1;
    while (stk.size()) {
        int u = stk.back();
        stk.pop_back();
        if (val[u] == 'B') {
            adj[0].push_back(u); continue;
        }
        idx[u] = 1;
        for (int v : adj[u])
            stk.push_back(v);
    }
    idx[0] = 1; stk.assign(1, 0);
    while (stk.size()) {
        for (int u : stk)
            for (int v : adj[u])
                ch[idx[u]][val[v] - 'A'].push_back(v);
        int nl = -1, nr; stk.clear();
        for (int i = l; i <= r; i++) {
            if (ch[i][0].size()) {
                cnt++;
                if (nl < 0) nl = cnt;
                nr = cnt;
                for (int v : ch[i][0]) {
                    idx[v] = cnt; 
                    stk.push_back(v);
                }
            }
            if (ch[i][1].size()) {
                cnt++;
                if (nl < 0) nl = cnt;
                nr = cnt;
                for (int v : ch[i][1]) {
                    idx[v] = cnt;
                    stk.push_back(v);
                }
            }
        }
        l = nl; r = nr;
    }
    for (int i = 1; i <= n; i++)
        sum[idx[i]]++;
    for (int i = 1; i <= cnt; i++)
        sum[i] += sum[i - 1];
}

int count_species(int s, int t) {
    tie(s, t) = minmax(idx[s + 1], idx[t + 1]);
    return sum[t] - sum[s - 1];
}
