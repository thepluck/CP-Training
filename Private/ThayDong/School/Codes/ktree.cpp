#include <bits/stdc++.h>
using namespace std;
 
template <class X, class Y>
bool cmax(X &a, const Y &b) {
    return a < b ? a = b, 1 : 0;
}
 
const int N = 2e5 + 5;
 
vector <int> adj[N]; int d;
 
int& rev(vector <int> &a, int i) {
    return a[a.size() - i - 1];
}
 
vector <int> dfs(int u, int p = 0) {
    vector <int> res(1, 1);
    for (int v : adj[u]) {
        if (v == p) continue;
        auto add = dfs(v, u);
        add.push_back(add.back());
        if (add.size() > res.size())
            swap(add, res);
        for (int i = 0; i < add.size(); i++) {
            int a = rev(add, i) + (d - i < res.size()
            ? rev(res, max(i, d - i)) : 0);
            int b = rev(res, i) + (d - i < add.size()
            ? rev(add, max(i, d - i)) : 0);
            cmax(rev(res, i), max(a, b));
        }
        for (int i = add.size() - 1; ~i; i--)
            if (i + 1 < res.size())
                cmax(rev(res, i), rev(res, i + 1));
    }
    return res;
}

int main() {
    freopen("ktree.inp", "r", stdin);
    freopen("ktree.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int l = 0, r = n - 1, res;
    while (l <= r) {
        d = (l + r) / 2;
        if (dfs(1).back() >= k) {
            res = d; l = d + 1;
        }
        else r = d - 1;
    }
    cout << res << '\n';
}