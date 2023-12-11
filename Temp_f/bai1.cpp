#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
int a[105][105], col[105], row[105];
vector <pair <int, int>> ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    memset(row, 0x3f, sizeof row);
    memset(col, 0xc0, sizeof col);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            cin >> a[i][j]; 
            row[i] = min(row[i], a[i][j]);
            col[j] = max(col[j], a[i][j]);
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] == row[i] && a[i][j] == col[j])
                ans.push_back(make_pair(i, j));
    cout << ans.size() << '\n';
    for (auto x : ans) cout << x.fi << ' ' << x.se << ' ';
}