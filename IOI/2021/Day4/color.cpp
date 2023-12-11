#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmax(X &a, const Y &b) {
    return a < b ? a = b, 1 : 0;
}

const int MAXN = 100005;
const int MAXK = 35;

int DP[MAXN][MAXK], N, K;
vector <int> adj[MAXN];
int tmp[MAXN];

void DFS(int u, int p) {
    vector <int> ch;
    for (int v : adj[u])
        if (v != p) {
            DFS(v, u); ch.push_back(v);
        }
    if (ch.empty() && u > 1) {
        for (int i = 0; i < K; i++)
            DP[u][i] = 1;
        return;
    }
    memset(DP[u], 0xc0, sizeof DP[u]);
    for (int i = 0; i + 1 < K; i++) {
        vector <int> pre(1, 0);
        for (int it = 0; it < ch.size(); it++) {
            int val = DP[ch[it]][i] - 1;
            if (K - 1 >= i + 2)
                cmax(val, DP[ch[it]][min(i, K - i - 3)]);
            pre.push_back(pre.back() + val);
        }
        int sum = 0;
        for (int it = ch.size() - 1; it >= 0; it--) {
            cmax(DP[u][i + 1], sum + pre[it] + DP[ch[it]][i]);
            int val = DP[ch[it]][i] - 1;
            if (K - 1 >= i + 2)
                cmax(val, DP[ch[it]][min(i, K - i - 3)]);
            sum += val;
        }
        if (u > 1) {
            int j = K - i - 3;
            if (j >= i) {
                pre.resize(1, 0);
                for (int it = 0; it < ch.size(); it++) {
                    int val = DP[ch[it]][j] - 1;
                    if (K - 1 >= j + 2)
                        cmax(val, DP[ch[it]][min(i, K - j - 3)]);
                    pre.push_back(pre.back() + val);
                }
                sum = 0;
                for (int it = ch.size() - 1; it >= 0; it--) {
                    cmax(DP[u][i + 1], sum + pre[it] + DP[ch[it]][i]);
                    int val = DP[ch[it]][j] - 1;
                    if (K - 1 >= j + 2)
                        cmax(val, DP[ch[it]][min(i, K - j - 3)]);
                    sum += val;
                }
            }
        }
    }
    if (u > 1) {
        DP[u][0] = 0;
        for (int it = 0; it < ch.size(); it++)
            DP[u][0] += DP[ch[it]][K - 2] - 1;
        for (int i = 0; i < K; i++) DP[u][i]++;
    }
    for (int i = 1; i < K; i++)
        cmax(DP[u][i], DP[u][i - 1]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> K;
    for (int i = 1; i < N; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1, 0); cout << DP[1][K - 1];
}