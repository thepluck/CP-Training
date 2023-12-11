#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 100005;
vector <int> adj[N];
int w[N], n, k;

deque <ll> cal(int u, int p) {
    deque <ll> res(1, w[u]);
    for (int v : adj[u]) {
        if (v == p) continue;
        auto tmp = cal(v, u);
        tmp.push_front(tmp[0]);
        if (tmp.size() > res.size())
            swap(tmp, res);
        for (int i = 0; i < tmp.size(); i++) {
            ll t1 = tmp[i] + (k - i < res.size() ?
            res[max(i, k - i)] : 0);
            ll t2 = res[i] + (k - i < tmp.size() ?
            tmp[max(i, k - i)] : 0);
            res[i] = max({res[i], t1, t2});
        }
        for (int j = tmp.size() - 1; ~j; j--)
            if (j + 1 < res.size())
                res[j] = max(res[j], res[j + 1]);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> k; k++;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << cal(1, 0)[0] << '\n';
}