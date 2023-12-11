#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 150005;
 
int x[N][3];
set<pair<int, int>> s[3];
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++) {
            cin >> x[i][j];
            s[j].emplace(x[i][j], i);
        }
    while (s[0].size()) {
        int p = -1;
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++) {
                if (j == k) continue;
                int q = s[j].rbegin()->second;
                if (x[q][k] == s[k].rbegin()->first)
                    p = q;
            }
        if (p < 0) {
            cout << s[0].rbegin()->first
            + s[1].rbegin()->first
            + s[2].rbegin()->first;
            return 0;
        }
        for (int j = 0; j < 3; j++)
            s[j].erase(make_pair(x[p][j], p));
    }
    cout << -1;
}