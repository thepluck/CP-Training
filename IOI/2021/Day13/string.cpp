#include <bits/stdc++.h>

using namespace std;

const int MAXN = 4005;

string str[MAXN];
vector <string> can[MAXN];
bool sub[MAXN][MAXN];
string cur, nxt;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, K; cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> str[i];
        vector <string> V;
        for (int j = 0; j < str[i].size(); j++)
            V.push_back(str[i].substr(j));
        sort(V.begin(), V.end());
        can[i].emplace_back();
        int l = 0;
        for (auto s : V) {
            while (s.size() > l)
                can[i].push_back(s.substr(0, ++l));
        }
        for (int j = 1; j <= str[i].size(); j++)
            sub[i][j] = can[i][j].substr(0, j - 1) == can[i][j - 1];
    }
    int len = str[0].size();
    for (int i = 1; i <= min(len, K); i++)
        if (can[0][i].substr(0, i - 1) == can[0][i - 1])
            cur = can[0][i];
        else break;
    for (int i = 1; i < N; i++) {
        int rest = 0;
        for (int j = i + 1; j < N; j++)
            rest += str[j].size();
        len += str[i].size();
        int ptr = 0, need = max(0, K - rest);
        for (int j = 1; j <= need; j++) {
            if (ptr < str[i].size()) ptr++;
            while (ptr) {
                if (j == need && ptr == 1) break;
                if (cur[j - ptr] <= can[i][ptr][0]) ptr--;
                else break;
            }
        }
        int lim = need;
        for (int j = need + 1; j <= min(len, K); j++) {
            if (ptr < str[i].size()) ptr++;
            if (!sub[i][ptr]) break;
            while (ptr > 1) {
                if (cur[j - ptr] <= can[i][ptr][0]) ptr--;
                else break;
            }
            lim++;
        }
        nxt = cur.substr(0, lim - ptr) + can[i][ptr];
        cur = nxt;
    }
    cout << cur << '\n';
}