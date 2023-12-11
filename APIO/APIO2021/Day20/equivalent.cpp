#include <bits/stdc++.h>

using namespace std;

const int MAXM = 5005;

int nxt[MAXM][3], last[300], deg[MAXM];
vector <int> cur[300];

int main() {
    freopen("equivalent.inp", "r", stdin);
    freopen("equivalent.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    memset(last, -1, sizeof last);
    set <string> str;
    while (N--) {
        string S; cin >> S;
        int M = S.size(); S += S;
        for (int i = 0; i < M; i++) {
            for (char c = '0'; c <= '9'; c++)
                last[c] = -1;
            for (int j = i + M - 1; j >= i; j--) {
                deg[j] = 0;
                if (last[S[j] - 1] >= 0) {
                    nxt[j][0] = last[S[j] - 1];
                    deg[last[S[j] - 1]]++;
                } else nxt[j][0] = -1;
                if (last[S[j]] >= 0) {
                    nxt[j][1] = last[S[j]];
                    deg[last[S[j]]]++;
                } else nxt[j][1] = -1;
                if (last[S[j] + 1] >= 0) {
                    nxt[j][2] = last[S[j] + 1];
                    deg[last[S[j] + 1]]++;
                } else nxt[j][2] = -1;
                last[S[j]] = j;
            }
            for (int j = i; j < i + M; j++)
                if (deg[j] == 0)
                    cur[S[j]].push_back(j);
            string T;
            for (int j = i, u; j < i + M; j++) {
                for (char c = '0'; c <= '9'; c++)
                    if (cur[c].size()) {
                        u = cur[c].back();
                        cur[c].pop_back();
                        break;
                    }
                T.push_back(S[u]);
                if (nxt[u][0] >= 0 && --deg[nxt[u][0]] == 0)
                    cur[S[nxt[u][0]]].push_back(nxt[u][0]);
                if (nxt[u][1] >= 0 && --deg[nxt[u][1]] == 0)
                    cur[S[nxt[u][1]]].push_back(nxt[u][1]);
                if (nxt[u][2] >= 0 && --deg[nxt[u][2]] == 0)
                    cur[S[nxt[u][2]]].push_back(nxt[u][2]);
            }
            str.insert(T);
        }
    }
    cout << str.size() << '\n';
}