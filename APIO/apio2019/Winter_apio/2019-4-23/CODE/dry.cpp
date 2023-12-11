#include<bits/stdc++.h>
#define X 			first
#define Y 			second
using namespace std;

void Read(int &val) {
	val = 0; char c;
	do { c = getchar(); } while (!isdigit(c) && c != '-');
	bool Minus = false; if (c == '-') { Minus = true; c = getchar(); }
	while (isdigit(c)) { val = val * 10 + c - '0'; c = getchar(); }
	if (Minus) val = -val;
}

typedef pair<int, int> ii;
struct data {
	int x, y, type;
	data() {}; data(int x, int y, int type) : x(x), y(y), type(type) {};
};

const int N = 1e4 + 1;
const long double pi = acos(-1);
int n;
ii a[2*N];

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

int res_1 = 0, res_2 = 0, Time = 0;
int h[6] = { 1, 1, 0, -1, -1, 0 };
int c[6] = { 0, 1, 1, 0, -1, -1 };
bool vis[N][N], spe[2*N][7];
queue<data> Q;

void update(int x, int y, int pos, int type) {
	if (pos != 0) {
		if (!spe[pos][type]) spe[pos][type] = true, res_1++, Q.push( data(x, y, type) );
	}
	else {
		if (!vis[x][y]) vis[x][y] = true, res_2++, Q.push( data(x, y, 0) );
	}
}

void sol() {
	compress();

	Row = (int) rarX.size(); Col = (int) rarY.size();

	Q.push( data(0, 0, 0) ); vis[0][0] = true; res_2++;
	while (Q.size()) {
		data top = Q.front(); Q.pop();

		if (top.type == 0) {
			for (int dir = 0; dir < 6; ++dir) {
				int x = top.x + h[dir], y = top.y + c[dir];
				if (x < 0 || x > Row || y < 0 || y > Col) continue;

				if ( Map.count(ii(x, y)) ) {
					int pos = Map[ii(x, y)];
					if (dir == 0) { update(x, y, pos, 4); update(x, y, pos, 5); }
					if (dir == 1) { update(x, y, pos, 5); update(x, y, pos, 6); } 
					if (dir == 2) { update(x, y, pos, 1); update(x, y, pos, 6); } 
					if (dir == 3) { update(x, y, pos, 1); update(x, y, pos, 2); } 
					if (dir == 4) { update(x, y, pos, 2); update(x, y, pos, 3); } 
					if (dir == 5) { update(x, y, pos, 3); update(x, y, pos, 4); } 
				}
				else update(x, y, 0, 0);
			}
		}
		else {
			for (int dir = 0; dir < 6; ++dir) {
				int x = top.x + h[dir], y = top.y + c[dir];
				if (x < 0 || x > Row || y < 0 || y > Col) continue;

				if ( Map.count(ii(x, y)) ) {
					int pos = Map[ii(x, y)];
					if (dir == 0) { 
						if (top.type == 1) update(x, y, pos, 5); 
						if (top.type == 2) update(x, y, pos, 4); 
					}
					if (dir == 1) { 
						if (top.type == 2) update(x, y, pos, 6); 
						if (top.type == 3) update(x, y, pos, 5); 
					}
					if (dir == 2) { 
						if (top.type == 3) update(x, y, pos, 1); 
						if (top.type == 4) update(x, y, pos, 6); 
					}
					if (dir == 3) { 
						if (top.type == 4) update(x, y, pos, 2); 
						if (top.type == 5) update(x, y, pos, 1); 
					}
					if (dir == 4) { 
						if (top.type == 5) update(x, y, pos, 3); 
						if (top.type == 6) update(x, y, pos, 2); 
					}
					if (dir == 5) { 
						if (top.type == 6) update(x, y, pos, 4); 
						if (top.type == 1) update(x, y, pos, 3); 
					}
				}
				else {
					if (dir == 0) { 
						if (top.type == 1) update(x, y, 0, 0); 
						if (top.type == 2) update(x, y, 0, 0); 
					}
					if (dir == 1) { 
						if (top.type == 2) update(x, y, 0, 0); 
						if (top.type == 3) update(x, y, 0, 0); 
					}
					if (dir == 2) { 
						if (top.type == 3) update(x, y, 0, 0); 
						if (top.type == 4) update(x, y, 0, 0); 
					}
					if (dir == 3) { 
						if (top.type == 4) update(x, y, 0, 0); 
						if (top.type == 5) update(x, y, 0, 0); 
					}
					if (dir == 4) { 
						if (top.type == 5) update(x, y, 0, 0); 
						if (top.type == 6) update(x, y, 0, 0); 
					}
					if (dir == 5) { 
						if (top.type == 6) update(x, y, 0, 0); 
						if (top.type == 1) update(x, y, 0, 0); 
					}
				}
			}
		}
	}

	long double R2 = (long double) sqrt(3) / (long double) 6;
	long double S_circle = R2 * pi;
	long double S_6 = (long double) (1 - S_circle) / (long double) 6;
	long double res = (long double) (Row+1) * (Col+1) - (long double) res_2 - (long double) res_1 * S_6;
	res -= (long double) S_circle * n;
	cout << setprecision(5) << fixed << res << '\n';
}

int main() {
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	else if (fopen("dry.inp", "r")) {
		freopen("dry.inp", "r", stdin);
		freopen("dry.out", "w", stdout);
	}

	Read(n);
	for (int i = 1; i <= n; ++i) Read(a[i].X), Read(a[i].Y);

	sol();

	return 0;
}