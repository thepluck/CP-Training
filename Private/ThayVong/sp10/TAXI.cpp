#include <bits/stdc++.h>
using namespace std;

class point{
public:
    double x, y;
};

double dis(point a, point b){
    #define sqr(x) (x) * (x)
    return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

const int N = 5005;
point pt[N]; double dp[N][N];

int main(){
    freopen("TAXI.inp", "r", stdin);
    freopen("TAXI.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    cout.precision(3); fixed(cout);
    for (int i = 1; i <= n; i++)
        cin >> pt[i].x >> pt[i].y;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = 1e20;
    dp[0][0] = 0;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++){
            int k = max(i, j) + 1;
            dp[i][k] = min(dp[i][k], dp[i][j] + dis(pt[j], pt[k]));
            dp[k][j] = min(dp[k][j], dp[i][j] + dis(pt[i], pt[k]));
        }
    double res = 1e20;
    for (int i = 0; i <= n; i++)
        res = min({res, dp[i][n], dp[n][i]});
    cout << res << '\n';
}