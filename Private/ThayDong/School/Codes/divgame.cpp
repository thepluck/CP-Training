#include <bits/stdc++.h>
using namespace std;

vector <vector <char>> dp;
vector <int> divi[2];
vector <vector <int>> dv[2];
map <int, int> mp[2];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int x, y; cin >> x >> y;
    for (int i = 1; i * i <= x; i++)
        if (x % i == 0) {
            divi[0].push_back(i);
            if (i * i != x)
                divi[0].push_back(x / i);
        }
    for (int i = 1; i * i <= y; i++)
        if (y % i == 0) {
            divi[1].push_back(i);
            if (i * i != y)
                divi[1].push_back(y / i);
        }
    dv[0].resize(divi[0].size());
    dv[1].resize(divi[1].size());
    sort(divi[0].begin(), divi[0].end());
    sort(divi[1].begin(), divi[1].end());
    dp.resize(dv[0].size(),
    vector <char> (dv[1].size()));
    for (int i = 0; i < dv[0].size(); i++) {
        mp[0][divi[0][i]] = i;
        for (int j = 0; j < dv[0].size(); j++)
            if (divi[0][i] % divi[0][j] == 0)
                dv[0][i].push_back(j);
    }
    for (int i = 0; i < dv[1].size(); i++) {
        mp[1][divi[1][i]] = i;
        for (int j = 0; j < dv[1].size(); j++)
            if (divi[1][i] % divi[1][j] == 0)
                dv[1][i].push_back(j);
    }
    for (int i = 0; i < dv[0].size(); i++)
        for (int j = 0; j < dv[1].size(); j++) {
            for (int d : dv[0][i]) {
                if (d != i)
                    dp[i][j] |= !dp[d][j];
                if (d > 0 && divi[1][j] % divi[0][d] == 0)
                    dp[i][j] |= !dp[mp[0][divi[0][i] / divi[0][d]]]
                    [mp[1][divi[1][j] / divi[0][d]]];
                if (dp[i][j]) break;
            }
            for (int d : dv[1][j]) {
                if (d != j) dp[i][j] |= !dp[i][d];
                if (dp[i][j]) break;
            }
        }
    cout << (dp[dv[0].size() - 1][dv[1].size() - 1] ? 'A' : 'B');
}