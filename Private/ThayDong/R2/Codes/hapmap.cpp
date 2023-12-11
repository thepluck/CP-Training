#include <bits/stdc++.h>

using namespace std;

const int N = 201;

mt19937 rng(chrono::high_resolution_clock
::now().time_since_epoch().count());

int pos[N][2], nxt[N * N][2], siz = 0;
string str[N]; bool mark[N * N];
int ans[N * N][2]; bool same[N][N][N];
vector <string> all; bool prio[N * N][2];
vector <int> hav[N * N];

int getNxt(int p, int t) {
    if (!nxt[p][t]) nxt[p][t] = ++siz;
    return nxt[p][t];
}

void DFS(int p, string cur) {
    if (ans[p][0] || ans[p][1]) {
        if (ans[p][0]) DFS(ans[p][0], cur + '0');
        if (ans[p][1]) DFS(ans[p][1], cur + '1');
    }
    else all.push_back(cur);
}

int main() {
    freopen("hapmap.inp", "r", stdin);
    freopen("hapmap.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> str[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            same[i][j][m] = true;
            for (int k = m - 1; k >= 0; k--)
                if (str[i][k] == str[j][k]
                && str[i][k] < '2')
                    same[i][j][k] = true;
                else break;
        }
    int bestCnt = INT_MAX;
    while (clock() < CLOCKS_PER_SEC * 5) {
        memset(pos, 0, sizeof pos);
        memset(nxt, 0, sizeof nxt);
        siz = 0;
        for (int i = 0; i < m; i++) {
            vector <int> allPos;
            for (int j = 0; j < n; j++) {
                hav[pos[j][0]].clear();
                hav[pos[j][1]].clear();
                allPos.push_back(pos[j][0]);
                allPos.push_back(pos[j][1]);
            }
            for (int j = 0; j < n; j++) {
                hav[pos[j][0]].push_back(j);
                hav[pos[j][1]].push_back(j);
            }
            sort(allPos.begin(), allPos.end());
            allPos.erase(unique(allPos.begin(),
            allPos.end()), allPos.end());
            for (int p : allPos) {
                sort(hav[p].begin(), hav[p].end());
                hav[p].erase(unique(hav[p].begin(),
                hav[p].end()), hav[p].end());
                for (int x : hav[p])
                    for (int y : hav[p])
                        if (x != y)
                            if (same[x][y][i])
                                prio[p][str[x][i] - '0'] = 1;
                            else prio[p][str[x][i] - '0'] = 0; 
            }
            for (int j = 0; j < n; j++)
                if (str[j][i] <= '1') {
                    int t = str[j][i] - '0';
                    pos[j][0] = getNxt(pos[j][0], t);
                    pos[j][1] = getNxt(pos[j][1], t);
                }
            
            for (int j = 0; j < n; j++)
                if (str[j][i] == '2') {
                    
                }
        }
        for (int j = 0; j < n; j++)
            mark[pos[j][0]] = mark[pos[j][1]] = 1;
        int cnt = 0;
        for (int p = 1; p <= siz; p++)
            if (mark[p]) cnt++;
        for (int j = 0; j < n; j++)
            mark[pos[j][0]] = mark[pos[j][1]] = 0;
        if (bestCnt > cnt) {
            bestCnt = cnt;
            memcpy(ans, nxt, sizeof ans);
        }
        shuffle(str, str + n, rng);
    }
    DFS(0, ""); cout << all.size() << '\n';
    for (auto s : all) cout << s << '\n';
}