// Problem: D. Checkpoints
// Contest: Codeforces - Codeforces Round #688 (Div. 2)
// URL: https://codeforces.com/contest/1453/problem/D
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        long long req; cin >> req;
        if (req & 1) {
            cout << "-1\n"; continue;
        }
        vector <int> stages;
        stages.push_back(1); req -= 2;
        for (int i = 60; i >= 0; i--) {
            long long can = (1ll << (i + 1)) - 2;
            if (req == 0) break;
            while (req >= can) {
                for (int j = 1; j < i; j++)
                    stages.push_back(0);
                stages.push_back(1); req -= can;
            }
        }
        cout << stages.size() << '\n';
        for (int stage : stages)
            cout << stage <<  ' ';
        cout << '\n';
    }
}