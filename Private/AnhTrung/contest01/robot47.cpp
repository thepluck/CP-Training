#include <bits/stdc++.h>
using namespace std;

struct node{
    int u, v, w;
    bool operator < (const node &o){
        return w < o.w;
    }
};
vector <vector <int>> a;
vector <vector <int>> h;
vector <vector <long long>> dp;
vector <vector <bool>> used;
int r[] = {-1, 0, 0, 1};
int c[] = {0, -1, 1, 0};
int n, m;

bool is_node(int x, int y){
    return x > 0 && y > 0 && x <= n && y <= m;
}
long long longest(int i, int j){
    if (used[i][j]) return dp[i][j];
    used[i][j] = true; dp[i][j] = a[i][j];
    for (int k = 0; k < 4; k++)
        if (is_node(i + r[k], j + c[k]) && h[i][j] < h[i + r[k]][j + c[k]])
            dp[i][j] = max(dp[i][j], longest(i + r[k], j + c[k]) + a[i][j]);
    return dp[i][j];
}

int main(){
    cin >> n >> m;
    a.resize(n + 1, vector <int> (m + 1));
    h.resize(n + 1, vector <int> (m + 1));
    dp.resize(n + 1, vector <long long> (m + 1));
    used.resize(n + 1, vector <bool> (m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> h[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    long long ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            ans = max(ans, longest(i, j));
    cout << ans << '\n';
}