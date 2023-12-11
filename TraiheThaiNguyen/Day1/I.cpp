#include <bits/stdc++.h>
using namespace std;

const int N = 3e6 + 5;
int n, sz[N], f[N];
vector <int> adj[N];

void dfs(int u){
    sz[u] = 1;
    for (int v : adj[u]){
        dfs(v); sz[u] += sz[v];
        f[__gcd(sz[v], n - sz[v])]++;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 2; i <= n; i++){
        int j; cin >> j;
        adj[j].push_back(i);
    }
    dfs(1);
    for (int k = 1; k <= n; k++)
        if (n % k == 0){
            int cnt = 0;
            for (int t = n / k;
            t <= n; t += n / k)
                cnt += f[t];
            if (cnt == k - 1)
                cout << k << ' ';
        }
}