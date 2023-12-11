#include<bits/stdc++.h>
using namespace std;

const int N = 504;
int m, n, h, Row[N], Col[N];

bool vis[N][N];
char Char[N][N];
vector<int> V;

void sol() {
	for (int i = 1; i <= m; ++i) {
		V.clear();
		for (int j = 1; j <= n; ++j) {
			if (vis[i][j]) continue;
			V.push_back(j);
		}

		sort(V.begin(), V.end(), [] (int a, int b) {
			return Col[a] < Col[b];
		});	

		int num = 0;
		for (int j : V) {
			if (num >= Row[i]) {
				if (i + h - 1 > m) { cout << "NO \n"; exit(0); }
				for (int r = i; r <= i+h-1; ++r) {
					vis[r][j] = true;
					Char[r][j] = (r == i || r == i+h-1) ? '+' : '|';
				}
				Col[j]--;
				if (Col[j] < 0) { cout << "NO \n"; exit(0); }
			}
			else vis[i][j] = true, Char[i][j] = '*';
			++num;
		}
		if (num < Row[i]) { cout << "NO \n"; exit(0); }
	}

	cout << "YES \n";
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) cout << Char[i][j];
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	else if (fopen("chip.inp", "r")) {
		freopen("chip.inp", "r", stdin);
		freopen("chip.out", "w", stdout);
	}
 	
 	cin >> m >> n >> h;
 	for (int i = 1; i <= m; ++i) cin >> Row[i];
 	for (int j = 1; j <= n; ++j) cin >> Col[j];

 	sol();

	return 0;
}