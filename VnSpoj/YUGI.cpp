#include <bits/stdc++.h>
using namespace std;

const int N = 205;
int a[N][N], n, k;
bitset <N> used;

void dfs(int u, int lim){
    used[u] = true;
    for (int v = 1; v <= n; v++)
        if (!used[v] && a[u][v] < lim)
            dfs(v, lim);
}

bool ok(int lim){
    used.reset(); int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (!used[i])
            cnt++, dfs(i, lim);
    return cnt >= k;
}

int main(){
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    int l = 0, r = 32767, res, m;
    while (l <= r){
        m = (l + r) >> 1;
        if (ok(m)) res = m, l = m + 1;
        else r = m - 1;
    }
    cout << res << '\n';
}