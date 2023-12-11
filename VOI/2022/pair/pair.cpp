#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

int a[N], vis[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, d; cin >> n >> d;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<pair<int, int>> b;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            b.emplace_back(i, j);
    sort(b.begin(), b.end(), [&](pair<int, int> x, pair<int, int> y) {
        return a[x.first] + a[x.second] < a[y.first] + a[y.second];
    });
    int res = 0;
    for (int i = 0; i < b.size(); ) {
        int j = i, cur = 0;
        vector<pair<int, int>> c;
        while (j < b.size() && a[b[j].first] + a[b[j].second] <= a[b[i].first] + a[b[i].second] + d)
            c.push_back(b[j++]);
        sort(c.begin(), c.end(), [&](pair<int, int> x, pair<int, int> y) {
            return a[x.first] - a[x.second] < a[y.first] - a[y.second];
        });
        for (pair<int, int> x : c)
            if (vis[x.first] != j && vis[x.second] != j) {
                vis[x.first] = vis[x.second] = j; cur++;
            }
        res = max(res, cur);
        j = i;
        while (j < b.size() && a[b[j].first] + a[b[j].second] == a[b[i].first] + a[b[i].second]) j++;
        i = j;
    }
    cout << res;
}