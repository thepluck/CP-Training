#include<bits/stdc++.h>
using namespace std;

const int N = 4002;

int a[N], b[N], dp[N][N], in[N], out[N];
int tim, id[N], n, in2[N];
vector<int> A[N], B[N]; bool ch[N];

void go(int id, int u, int p){
    dp[id][u] = ch[u];
    for (int v : B[u]) if (v != p){
        go(id, v, u);
        dp[id][u] += dp[id][v];
    }
}

void dfs(int u, int p = -1){
    in[u] = ++tim; id[tim] = u;
    for (int v : A[u]) if (v != p) dfs(v, u);
    out[u] = tim;
    for (int i = 1; i <= n; i++) ch[i] = 0;
    for (int i = in[u]; i <= out[u]; i++)
        ch[id[i]] = 1;
    go(u, 1, 0);
}

void dfs2(int u, int p){
    in2[u] = ++tim;
    for (int v : B[u]) if (v != p) dfs2(v, u);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++){
        cin >> a[i]; a[i]++;
        A[a[i]].push_back(i);
        A[i].push_back(a[i]);
    }
    for (int i = 1; i < n; i++){
        cin >> b[i]; b[i]++;
        B[b[i]].push_back(i);
        B[i].push_back(b[i]);
    }
    dfs(1); tim = 0;
    dfs2(1, 0); long long ans = 0;
    for (int i = 1; i < n; i++)
        for (int j = 1; j < n; j++){
            int u = i, v = a[i];
            if (in[u] > in[v]) swap(u, v);
            int x = j, y = b[j];
            if (in2[x] > in2[y]) swap(x, y);
            x = 1; u = 1; int tm = 0;
            tm = max({tm, dp[u][y] - dp[v][y], dp[v][y], dp[v][x] - dp[v][y]});
            tm = max({tm, dp[u][x] - dp[u][y] - dp[v][x] + dp[v][y]});
            ans += 1ll * tm * tm;
        }
    cout << ans << '\n';
}