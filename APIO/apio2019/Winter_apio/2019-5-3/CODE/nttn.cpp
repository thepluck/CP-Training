#include<bits/stdc++.h>
#define int 					long long
#define BIG						vector<int>
#define FOR(i, a, b)			for (int i = a; i <= (int) b; ++i)
#define REP(i, a, b)			for (int i = a; i <  (int) b; ++i)
using namespace std;

const int BASE = 1e8;

void fix(BIG &a) {
	a.push_back(0);
	for (int i = 0; i < (int) a.size()-1; ++i) {
		a[i+1] += a[i] / BASE; a[i] %= BASE;
		if (a[i] < 0) { a[i] += BASE; a[i+1]--; }
	}
	while (a.size() >= 2 && a.back() == 0) a.pop_back();
}

BIG to_BIG(int x) { 
	BIG tmp = BIG(1, x);
	fix(tmp);
	return tmp; 
}

void operator += (BIG &a, BIG &b) {
	a.resize(max(a.size(), b.size()));
	for (int i = 0; i < (int) a.size(); ++i) a[i] += b[i];
	fix(a);
}

BIG operator * (const BIG a, const BIG b) {
	BIG c; c.resize(a.size() + b.size());
	REP(i, 0, a.size()) REP(j, 0, b.size()) 
		c[i+j] += a[i] * b[j];
	fix(c);
	return c;
}

bool operator < (const BIG &a, const BIG &b){
    if (a.size() != b.size()) return a.size() < b.size();
    for (int i = (int) a.size()-1; i >= 0; i--)
    if (a[i] != b[i]) return a[i] < b[i];
    return false;
}

void Print(BIG a) {
	cout << a.back();
	for (int i = (int) a.size()-2; i >= 0; --i) cout << setfill('0') << setw(8) << a[i];
	cout << '\n'; 
}

const int N = 14;
int k, m, n, a[N][N];

int best[7][N][N][N][N];
bool vis[7][N][N][N][N];

void process() {
	FOR(xo, 1, m) FOR(yo, 1, n) FOR(xi, xo+1, m) FOR(yi, yo+1, n) {
		int ore1 = a[xo][yo] * a[xi][yo];
		int ore2 = a[xo][yi] * a[xi][yi]; 
		int ore = 1;
		if (ore1 < 0 && ore2 > 0) ore = -1;
		if (ore1 > 0 && ore2 < 0) ore = -1;
		int cmpVal = abs(ore1*ore2);

		if (ore >= 0) {
			int &foo_0 = best[0][xo][yo][xi][yi];
			int &foo_1 = best[1][xo][yo][xi][yi];
			bool &vis_0 = vis[0][xo][yo][xi][yi];
			bool &vis_1 = vis[1][xo][yo][xi][yi];

			if (!vis_0 || foo_0 < cmpVal) {
				foo_1 = foo_0; foo_0 = cmpVal; 
				if (!vis_0) vis_0 = true;
				else vis_0 = vis_1 = true;
			}
			else if (!vis_1 || foo_1 < cmpVal) foo_1 = cmpVal, vis_1 = true;
		}
		else {
			int &foo_0 = best[2][xo][yo][xi][yi];
			int &foo_1 = best[3][xo][yo][xi][yi];
			bool &vis_0 = vis[2][xo][yo][xi][yi];
			bool &vis_1 = vis[3][xo][yo][xi][yi];

			if (!vis_0 || foo_0 < cmpVal) {
				foo_1 = foo_0; foo_0 = cmpVal; 
				if (!vis_0) vis_0 = true;
				else vis_0 = vis_1 = true;
			}
			else if (!vis_1 || foo_1 < cmpVal) foo_1 = cmpVal, vis_1 = true;
		}

		if (ore >= 0) {
			int &foo_0 = best[4][xo][yo][xi][yi];
			bool &vis_0 = vis[4][xo][yo][xi][yi];

			if (!vis_0 || cmpVal < foo_0) foo_0 = cmpVal, vis_0 = true;
		}
		else {
			int &foo_0 = best[5][xo][yo][xi][yi];
			bool &vis_0 = vis[5][xo][yo][xi][yi];

			if (!vis_0 || cmpVal < foo_0) foo_0 = cmpVal, vis_0 = true;
		}
	}
}

#undef int
int main() {
#define int 					long long
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
	}
	else {
		freopen("prod.inp", "r", stdin);
		freopen("prod.out", "w", stdout);
	}

	cin >> k >> m >> n;

	for (int i = 1; i <= k; ++i) {
		FOR(x, 1, m) FOR(y, 1, n) cin >> a[x][y];
		process();
	}

	bool flag = false;
	BIG res;
	FOR(xo, 1, m) FOR(yo, 1, n) FOR(xi, xo+1, m) FOR(yi, yo+1, n) {
		int &foo_0 = best[0][xo][yo][xi][yi];
		int &foo_1 = best[1][xo][yo][xi][yi];
		bool &vis_0 = vis[0][xo][yo][xi][yi];
		bool &vis_1 = vis[1][xo][yo][xi][yi];

		BIG cmpVal = to_BIG(foo_0) * to_BIG(foo_1);

		if (vis_0 && vis_1) {
			if (!flag) {
				res = cmpVal;
				flag = true;
			}
			else {
				if (res < cmpVal) res = cmpVal;
			}
		}

		int &foo_2 = best[2][xo][yo][xi][yi];
		int &foo_3 = best[3][xo][yo][xi][yi];
		bool &vis_2 = vis[2][xo][yo][xi][yi];
		bool &vis_3 = vis[3][xo][yo][xi][yi];

		cmpVal = to_BIG(foo_2) * to_BIG(foo_3);

		if (vis_2 && vis_3) {
			if (!flag) {
				res = cmpVal;
				flag = true;
			}
			else {
				if (res < cmpVal) res = cmpVal;
			}
		}
	}

	if (flag) Print(res);
	else {
		FOR(xo, 1, m) FOR(yo, 1, n) FOR(xi, xo+1, m) FOR(yi, yo+1, n) {
			int &foo_4 = best[4][xo][yo][xi][yi];
			int &foo_5 = best[5][xo][yo][xi][yi];
			bool &vis_4 = vis[4][xo][yo][xi][yi];
			bool &vis_5 = vis[5][xo][yo][xi][yi];

			BIG cmpVal = to_BIG(foo_4) * to_BIG(foo_5);

			if (vis_4 && vis_5) {
				if (!flag) {
					res = cmpVal;
					flag = true;
				}
				else {
					if (cmpVal < res) res = cmpVal;
				}
			}
		}
		cout << "-";
		Print(res);
	}

	return 0;
}