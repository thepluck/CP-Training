#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const int M = 15;
const int L = 105;
const int MOD = 1000000009;

int dp[N][L][M], sz, go[256];
int nxt[L][4], aut[L][4], dep[L];
int link[L], leaf[L], last[L];

int& madd(int &x, int y) {
    if ((x += y) >= MOD) x -= MOD;
    return x;
}

void insert(const string &s) {
    int pt = 0;
    for (char c : s) {
        if (!nxt[pt][go[c]]) {
            nxt[pt][go[c]] = ++sz;
            dep[sz] = dep[pt] + 1;
        }
        pt = nxt[pt][go[c]];
    }
    leaf[pt]++;
}

void automata() {
    queue <int> q; q.push(0);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        last[u] = leaf[u] ? u : last[link[u]];
        for (int c = 0; c < 4; c++) {
            int v = nxt[u][c];
            if (v) {
                link[v] = u ? aut[link[u]][c] : 0;
                q.push(v); aut[u][c] = v;
            }
            else aut[u][c] = aut[link[u]][c];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    go['A'] = 0; go['C'] = 1;
    go['G'] = 2; go['T'] = 3;
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        string s; cin >> s; insert(s);
    }
    automata(); dp[0][0][0] = 1;
    /// len i, node j, k characters left
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= sz; j++)
            for (int c = 0; c < 4; c++) {
                int t = aut[j][c];
                for (int k = 0; k < dep[t]; k++) {
                    int nk = k + 1;
                    if (dep[last[t]] >= nk) nk = 0;
                    madd(dp[i + 1][t][nk], dp[i][j][k]);
                }
            }
    int res = 0;
    for (int j = 0; j <= sz; j++)
        madd(res, dp[n][j][0]);
    cout << res << '\n';
}