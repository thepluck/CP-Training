#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e3 + 7;
int a[maxn][maxn];
int f[maxn][maxn];
int g[maxn][maxn];

int main() {
    //freopen("chessboard.inp", "r", stdin);
    //freopen("chessboard.out", "w", stdout);
	int n, q;
	cin >> n;
	memset(f, 0, sizeof(f));
	memset(g, 0, sizeof(g));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++){
			cin >> a[i][j];
			if ((i + j) % 2 == 0) {f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + a[i][j]; g[i][j] = g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];}
			else {g[i][j] = g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1] + a[i][j]; f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];}
		}
	cin >> q;
	int x1, x2, y1, y2;
	while (q--){
		cin >> x1 >> y1 >> x2 >> y2;
		cout << abs((f[x2][y2] - f[x2][y1 - 1] - f[x1 - 1][y2] + f[x1 - 1][y1 - 1]) - (g[x2][y2] - g[x2][y1 - 1] - g[x1 - 1][y2] + g[x1 - 1][y1 - 1])) << '\n';
	}
	return 0;
}
