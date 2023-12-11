#include <bits/stdc++.h>
using namespace std;

using ii = pair <int, int>;
const int ninf = 0xc0c0c0c0;
const int inf = 0x3f3f3f3f;
ii dp[1005][5005];
int a[1005], c[1005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, w, h; cin >> n >> w >> h;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> c[i];
    for (int i = 0; i <= n; i++)
        for (int j = 1; j <= w; j++)
            dp[i][j] = {ninf, inf};
    dp[0][0] = {0, 0};
}