#include<bits/stdc++.h>
#define int 			long long
#define X				first
#define Y				second
#define FOR(i, a, b)	for (int i = a; i <= (int) b; ++i)
#define REP(i, a, b)	for (int i = a; i <  (int) b; ++i)
using namespace std;

typedef pair<int, int> ii;
typedef pair<long double, long double> dd;

const long double eps = 1e-17;
int n, k;

long double sqr(long double a) { return a*a; }
long double getDist(dd a, dd b) { return sqrt( sqr(a.X-b.X) + sqr(a.Y-b.Y) ); }

namespace Sub1 {
	const int N = 20, MASK = 33333;
	dd a[N];

	bool BIT(int n, int k) { return n & (1<<k); }

	dd curPoint;
	vector<ii> V;
	long double curDist;

	long double get_sum_dist(dd point) {
		long double ans = (long double) 0;
		for (dd ore : V) ans += getDist(ore, point);
		return ans;
	}

	long double h[4] = { 0, 0, -1, 1 }, c[4] = { -1, 1, 0, 0 };

	void Find_geometric_median() {
		int sz = (int) V.size();

		curPoint = dd(0, 0); curDist = (long double) 1e14;
		for (int i = 0; i < sz; ++i) curPoint.X += V[i].X, curPoint.Y += V[i].Y;
		curPoint.X /= (long double) sz; curPoint.Y /= (long double) sz;

		curDist = get_sum_dist(curPoint);

		long double test_Dist = (long double) 10000;
		long double limit = 0.01;
		while (test_Dist > limit) {
			bool flag = false;
			for (int dir = 0; dir < 4; ++dir) {
				dd newPoint;
				newPoint.X = curPoint.X + h[dir] * test_Dist;
				newPoint.Y = curPoint.Y + c[dir] * test_Dist;

				long double newDist = get_sum_dist(newPoint);
				if (newDist + eps < curDist) {
					curDist = newDist; curPoint = newPoint;
					flag = true;
				}
			}

			if (!flag) test_Dist /= (long double) 2;
		} 
	}

	long double median_dist[MASK], dp[MASK][N];
	dd median_point[MASK];
	int Trace[MASK][N];

	void sol() {
		for (int i = 0; i < n; ++i) cin >> a[i].X >> a[i].Y;

		for (int mask = 0; mask < (1<<n); ++mask) {
			V.clear();
			for (int i = 0; i < n; ++i) 
				if (BIT(mask, i)) V.push_back(a[i]);
			Find_geometric_median();

			median_dist[mask] = curDist;
			median_point[mask] = curPoint;
		}

		for (int mask = 0; mask < (1<<n); ++mask) {
			dp[mask][1] = median_dist[mask]; Trace[mask][1] = mask;
			for (int i = 2; i <= k; ++i) dp[mask][i] = (long double) 1e15;
		}

		for (int mask = 0; mask < (1<<n); ++mask) for (int i = 2; i <= k; ++i) {
			for (int sub = mask; sub > 0; sub = (sub-1) & mask) {
				int remain = mask - sub;
				if (dp[mask][i] > dp[remain][i-1] + median_dist[sub]) {
					dp[mask][i] = dp[remain][i-1] + median_dist[sub];
					Trace[mask][i] = sub;
				}
			}
		}

		int mask = (1<<n)-1;
		while (mask > 0) {
			int sub = Trace[mask][k];
			cout << median_point[sub].X << " " << median_point[sub].Y << '\n';
			mask -= sub; --k;
		}
	}
}

namespace Sub2 {
	const int N = 1004;
	dd a[N];

	int belong[N], Prev[N];
	dd curPoint, center[N];
	vector<ii> V, ls[N];
	long double curDist;

	long double get_sum_dist(dd point) {
		long double ans = (long double) 0;
		for (dd ore : V) ans += getDist(ore, point);
		return ans;
	}

	long double h[4] = { 0, 0, -1, 1 }, c[4] = { -1, 1, 0, 0 };

	void Find_geometric_median() {
		int sz = (int) V.size();

		curPoint = dd(0, 0); curDist = (long double) 1e17;
		for (int i = 0; i < sz; ++i) curPoint.X += V[i].X, curPoint.Y += V[i].Y;
		
		curPoint.X /= (long double) sz; curPoint.Y /= (long double) sz;
		curDist = get_sum_dist(curPoint);

		long double test_Dist = (long double) 1000000;
		long double limit = 0.01;
		while (test_Dist > limit) {
			bool flag = false;
			for (int dir = 0; dir < 4; ++dir) {
				dd newPoint;
				newPoint.X = curPoint.X + h[dir] * test_Dist;
				newPoint.Y = curPoint.Y + c[dir] * test_Dist;

				long double newDist = get_sum_dist(newPoint);
				if (newDist + eps < curDist) {
					curDist = newDist; curPoint = newPoint;
					flag = true;
				}
			}

			if (!flag) test_Dist /= (long double) 2;
		} 
	}

	void sol() {
		for (int i = 1; i <= n; ++i) cin >> a[i].X >> a[i].Y, belong[i] = 1;
		for (int i = 1; i <= k; ++i) center[i] = a[i]; 

		while (true) {
			FOR(i, 1, k) Prev[i] = belong[i];

			FOR(i, 1, n) FOR(part, 1, k) 
				if ( getDist(a[i], center[part]) + eps < getDist(a[i], center[belong[i]]) ) belong[i] = part;

			bool isEnd = true;
			FOR(i, 1, k) if (Prev[i] != belong[i]) { isEnd = false; break; }
			if (isEnd) break;

			FOR(i, 1, k) ls[i].clear();
			FOR(i, 1, n) ls[belong[i]].push_back(a[i]);

			FOR(i, 1, k) {
				V = ls[i];
				Find_geometric_median();
				center[i] = curPoint;
			}
		}

		FOR(i, 1, k) cout << center[i].X << " " << center[i].Y << '\n';
	}
}

main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	else if (fopen("sieuthi.inp", "r")) {
		freopen("sieuthi.inp", "r", stdin);
		freopen("sieuthi.out", "w", stdout);
	}

	cin >> n >> k;

	if (n <= 15) Sub1::sol();
	else Sub2::sol();

	return 0;
}