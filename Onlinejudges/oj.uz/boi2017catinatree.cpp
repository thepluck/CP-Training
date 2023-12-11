#include <bits/stdc++.h>
using namespace std;

template <class X, class Y>
bool cmax(X &a, const Y &b) {
    return a < b ? a = b, 1 : 0;
}

const int N = 2e5 + 5;

vector <int> adj[N];
int n, k;

int& rev(vector <int> &a, int i) {
    return a[a.size() - i - 1];
}

vector <int> dfs(int u) {
    vector <int> res(1, 1);
    for (int v : adj[u]) {
        auto add = dfs(v);
        add.push_back(add.back());
        if (add.size() > res.size())
            swap(add, res);
        for (int i = 0; i < add.size(); i++) {
            int a = rev(add, i) + (k - i < res.size() ?
            rev(res, max(i, k - i)) : 0);
            int b = rev(res, i) + (k - i < add.size() ?
            rev(add, max(i, k - i)) : 0);
            cmax(rev(res, i), max(a, b));
        }
        for (int i = add.size() - 1; ~i; i--)
            if (i + 1 < res.size())
                cmax(rev(res, i), rev(res, i + 1));
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int j; cin >> j;
        adj[j].push_back(i);
    }
    cout << dfs(0).back() << '\n';
}