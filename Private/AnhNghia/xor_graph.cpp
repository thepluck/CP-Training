//https://codeforces.com/gym/102419/problem/D
#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

vector <int> adj[N], val;
int a[N], n, m, mex;
int side[N]; bool bipar = 1;
queue <int> q;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; side[i] = -1;
    }
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        if (a[u] == a[v]) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        val.push_back(a[u] ^ a[v]);
    }
    sort(val.begin(), val.end());
    for (int x : val)
        if (x == mex) mex++;
    for (int i = 1; i <= n; i++)
        if (side[i] < 0) {
            q.push(i); side[i] = 0;
            while (q.size()) {
                int u = q.front(); q.pop();
                for (int v : adj[u])
                    if (side[v] < 0) {
                        side[v] = side[u] ^ 1;
                        q.push(v);
                    }
                    else if (side[u] == side[v])
                        bipar = 0;
            }
        }
    if (!bipar) {
        cout << "-1\n"; return 0;
    }
    int k = 0;
    for (int i = 1; i <= n; i++)
        k += side[i] == 0;
    cout << k << ' ' << mex << '\n';
    for (int i = 1; i <= n; i++)
        if (!side[i]) cout << i << ' ';
}