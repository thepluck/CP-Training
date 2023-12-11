#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector <int> cnt(n + 1);
    while (m--) {
        int i, j; cin >> i >> j;
        if (i > j) {
            cout << "No\n"; return 0;
        }
        if (j == i + 1) cnt[i]++;
    }
    for (int i = 1; i < n; i++)
        if (!cnt[i]) {
            cout << "No\n"; return 0;
        }
    cout << "Yes\n";
}