#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector <vector <int>> adj(m);
        vector <int> cnt(n), use(n), ans(m, -1);
        for (int i = 0; i < m; i++) {
            int k; cin >> k;
            while (k--) {
                int j; cin >> j; j--;
                adj[i].push_back(j);
                cnt[j]++;
            }
        }
        for (int i = 0; i < m; i++)
            if (adj[i].size() == 1) {
                int j = adj[i][0];
                if (use[j] < (m + 1) / 2) {
                    use[j]++; ans[i] = j;
                }
            }
        for (int i = 0; i < m; i++)
            if (ans[i] < 0)
                for (int j : adj[i])
                    if (use[j] < (m + 1) / 2) {
                        use[j]++; ans[i] = j; break;
                    }
        if (count(ans.begin(), ans.end(), -1))
            cout << "NO\n";
        else {
            cout << "YES\n";
            for (int j : ans) cout << j + 1 << ' ';
            cout << '\n';
        }
    }
}
