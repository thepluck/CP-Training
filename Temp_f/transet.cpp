#include <bits/stdc++.h>
using namespace std;

template <class X, class Y>
bool chkmax(X &a, const Y &b){
    return a < b ? a = b, 1 : 0;
}

#define eb emplace_back

const int N = 1e3 + 5;
const int S = 105;
const int K = 35;
vector <int> adj[N];
int f[S][N], g[S][N][K], sz[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, s; cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> sz[i]; int j;
        for (int k = 0; k < sz[i]; k++){
            cin >> j; adj[i].eb(j);
            g[0][i][k] = k + 1;
        }
        f[0][i] = 1;
    }
    cin >> s;
    for (int i = 1; i <= s; i++){
        for (int u = 1; u <= n; u++)
            f[i][u] = g[i - 1][u][sz[u] - 1];
        for (int u = 1; u <= n; u++){
            g[i][u][0] = f[i][adj[u][0]];
            for (int j = 1; j < sz[u]; j++)
                for (int k = 0; k <= i; k++)
                    chkmax(g[i][u][j],
                    g[i - k][u][j - 1] + f[k][adj[u][j]]);
        }
    }
    cout << *max_element(f[s] + 1, f[s] + n + 1) << '\n';
}