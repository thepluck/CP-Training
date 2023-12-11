#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
const int M = 1e4 + 5;
int dis[N][N], isle[M], n, m;

template <class T, class _T>
bool chkmin(T &a, const _T &b){
	return a > b ? a = b, 1 : 0;
}

void floyd(){
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				chkmin(dis[i][j], dis[i][k] + dis[k][j]);
}

long long calc(){
	long long ans = 0;
	for (int i = 0; i < m - 1; i++)
		ans += dis[isle[i]][isle[i + 1]];
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> isle[i];
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++)
			cin >> dis[i][j];
		dis[i][i] = 0x3f3f3f3f;
	}
	floyd(); cout << calc() << '\n';
}