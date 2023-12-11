#include <bits/stdc++.h>

using namespace std;

vector <int> path;
bool used[10000];
vector <pair <int, int>> adj[26];

void euler(int u) {
    for (auto e : adj[u])
        if (!used[e.second]) {
            used[e.second] = true;
            euler(e.first);
        }
    path.push_back(u);        
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
            adj[i].emplace_back(j, i * k + j);
    euler(0); path.pop_back();
    string s; k = path.size();
    for (int c : path) s += char(c + 'a');
    while (n > 0) {
        cout << s.substr(0, min(n, k));
        n -= min(n, k);
    }
}