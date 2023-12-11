#include<bits/stdc++.h>
#define X 			first
#define Y 			second
using namespace std;

typedef pair<int, int> ii;
struct data {
	int x, y, type;
	data() {}; data(int x, int y, int type) : x(x), y(y), type(type) {};
};

const int N = 1e4 + 1;
const long double pi = acos(-1);
int n;
ii a[N];

vector<int> rarX, rarY;
map<ii, int> Map;
int Row, Col;

void compress() {
	for (int i = 1; i <= n; ++i) {
		rarX.push_back(a[i].X); rarX.push_back(a[i].X+1);
		rarY.push_back(a[i].Y); rarY.push_back(a[i].Y+1);
	}

	sort(rarX.begin(), rarX.end());
	rarX.resize(unique(rarX.begin(), rarX.end()) - rarX.begin());

	sort(rarY.begin(), rarY.end());
	rarY.resize(unique(rarY.begin(), rarY.end()) - rarY.begin());

	for (int i = 1; i <= n; ++i) {
		a[i].X = lower_bound(rarX.begin(), rarX.end(), a[i].X) - rarX.begin() + 1;
		a[i].Y = lower_bound(rarY.begin(), rarY.end(), a[i].Y) - rarY.begin() + 1;
		Map[a[i]] = i;
	}
}

int h[4] = { 0, 0, -1, 1 }, c[4] = { -1, 1, 0, 0 };
bool vis[N][N], spe[N][5];
queue<data> Q;

void sol() {
	compress();

	Row = (int) rarX.size(); Col = (int) rarY.size();
	int res_1 = 0, res_2 = 0, Time = 0;

	Q.push( data(0, 0, 0) ); vis[0][0] = true; res_2++;
	while (Q.size()) {
		data top = Q.front(); Q.pop();

		if (top.type == 0) {
			for (int dir = 0; dir < 4; ++dir) {
				int x = top.x + h[dir], y = top.y + c[dir];
				if (x < 0 || x > Row || y < 0 || y > Col) continue;

				if ( Map.count(ii(x, y)) ) {
					int pos = Map[ii(x, y)];
					if (dir == 0) {
						if (!spe[pos][2]) spe[pos][2] = true, res_1++, Q.push( data(x, y, 2) );
						if (!spe[pos][3]) spe[pos][3] = true, res_1++, Q.push( data(x, y, 3) );
					} 
					else if (dir == 1) {
						if (!spe[pos][1]) spe[pos][1] = true, res_1++, Q.push( data(x, y, 1) );
						if (!spe[pos][4]) spe[pos][4] = true, res_1++, Q.push( data(x, y, 4) );
					}
					else if (dir == 2) {
						if (!spe[pos][3]) spe[pos][3] = true, res_1++, Q.push( data(x, y, 3) );
						if (!spe[pos][4]) spe[pos][4] = true, res_1++, Q.push( data(x, y, 4) );
					}
					else { /// dir = 3
						if (!spe[pos][1]) spe[pos][1] = true, res_1++, Q.push( data(x, y, 1) );
						if (!spe[pos][2]) spe[pos][2] = true, res_1++, Q.push( data(x, y, 2) );
					}
				}
				else {
					if (!vis[x][y]) vis[x][y] = true, res_2++, Q.push( data(x, y, 0) );
				}
			}
		}
		else {
			for (int dir = 0; dir < 4; ++dir) {
				int x = top.x + h[dir], y = top.y + c[dir];
				if (x < 0 || x > Row || y < 0 || y > Col) continue;

				if ( Map.count(ii(x, y)) ) {
					int pos = Map[ii(x, y)];
					if (dir == 0) {
						if (top.type == 1 && !spe[pos][2]) spe[pos][2] = true, res_1++, Q.push( data(x, y, 2) ); 
						if (top.type == 4 && !spe[pos][3]) spe[pos][3] = true, res_1++, Q.push( data(x, y, 3) ); 
					}
					else if (dir == 1) {
						if (top.type == 2 && !spe[pos][1]) spe[pos][1] = true, res_1++, Q.push( data(x, y, 1) ); 
						if (top.type == 3 && !spe[pos][4]) spe[pos][4] = true, res_1++, Q.push( data(x, y, 4) );
					}
					else if (dir == 2) {
						if (top.type == 1 && !spe[pos][4]) spe[pos][4] = true, res_1++, Q.push( data(x, y, 4) ); 
						if (top.type == 2 && !spe[pos][3]) spe[pos][3] = true, res_1++, Q.push( data(x, y, 3) );
					}
					else { /// dir = 3
						if (top.type == 4 && !spe[pos][1]) spe[pos][1] = true, res_1++, Q.push( data(x, y, 1) ); 
						if (top.type == 3 && !spe[pos][2]) spe[pos][2] = true, res_1++, Q.push( data(x, y, 2) );
					}
				}
				else {
					if (dir == 0) {
						if (top.type == 1 && !vis[x][y]) vis[x][y] = true, res_2++, Q.push( data(x, y, 0) ); 
						if (top.type == 4 && !vis[x][y]) vis[x][y] = true, res_2++, Q.push( data(x, y, 0) ); 
					}
					else if (dir == 1) {
						if (top.type == 2 && !vis[x][y]) vis[x][y] = true, res_2++, Q.push( data(x, y, 0) ); 
						if (top.type == 3 && !vis[x][y]) vis[x][y] = true, res_2++, Q.push( data(x, y, 0) );
					}
					else if (dir == 2) {
						if (top.type == 1 && !vis[x][y]) vis[x][y] = true, res_2++, Q.push( data(x, y, 0) ); 
						if (top.type == 2 && !vis[x][y]) vis[x][y] = true, res_2++, Q.push( data(x, y, 0) );
					}
					else { /// dir = 3
						if (top.type == 4 && !vis[x][y]) vis[x][y] = true, res_2++, Q.push( data(x, y, 0) ); 
						if (top.type == 3 && !vis[x][y]) vis[x][y] = true, res_2++, Q.push( data(x, y, 0) );
					}
				}
			}
		}
	}

	long double R = (long double) 1/2;
	long double S_4 = (long double) ( (long double) 1 - (long double) pi * R*R ) / (long double) 4;
	long double S = pi / (long double) 4;
	long double res = (long double) (Row+1) * (Col+1) - (long double) res_2 - res_1 * S_4 - S * (long double) n;

	cout << setprecision(5) << fixed << res << '\n';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	else if (fopen("pre.inp", "r")) {
		freopen("pre.inp", "r", stdin);
		freopen("pre.out", "w", stdout);
	}

	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i].X >> a[i].Y;

	sol();

	return 0;
}