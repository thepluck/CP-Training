#include<bits/stdc++.h>
using namespace std;

const int N = 10;
int n, a[N], c[N], tempo[N];
int vis[8][8][8][8][8][8][8][8];

struct data {
	vector<int> per;
	int dep;

	void debug() {
		cerr << "PERMUTATION : ";
		for (int val : per) cerr << val << " "; cerr << "\n";
		cerr << "DEPTH : " << dep << "\n\n";
	}

	int get_ID() {
		for (int i = 0; i < (int) per.size(); ++i) c[i+1] = per[i]-1;
		return vis[ c[1] ][ c[2] ][ c[3] ][ c[4] ][ c[5] ][ c[6] ][ c[7] ][ c[8] ];
	}

	bool isArrange() {
		for (int i = 0; i < (int) per.size(); ++i) 
			if (per[i] != i+1) return false;
		return true; 
	}

	bool operator < (const data &a) const {
		for (int i = 0; i < (int) per.size(); ++i) 
			if (per[i] != a.per[i]) return per[i] < a.per[i];
		return dep < a.dep;
	}
};

long double dp[41000][304];
bool tham[41000][304];

long double calc(data ore, long double p) {
	int id = ore.get_ID();
	if ( ore.dep >= 200 ) return 0;
	if ( tham[id][ore.dep] ) return dp[id][ore.dep];
	if ( ore.isArrange() ) return p * ore.dep;
	tham[id][ore.dep] = true;

	if ( ore.dep % 2 == 0 ) { /// optimal
		long double res = 0; bool flag = false;
		for (int i = 0; i < (int) ore.per.size()-1; ++i) {
			if (ore.per[i] < ore.per[i+1]) continue;

			swap(ore.per[i], ore.per[i+1]); ore.dep++;
			long double tmp = calc(ore, p);
			if ( tmp != (long double) 0 ) { res = (!flag) ? tmp : min( res, tmp ); flag = true; }
			swap(ore.per[i], ore.per[i+1]); ore.dep--;
		}
		return dp[id][ore.dep] = res;
	}
	else {
		long double res = 0, nP = p / (long double) (n-1);
		for (int i = 0; i < (int) ore.per.size()-1; ++i) {	
			swap(ore.per[i], ore.per[i+1]); ore.dep++;
			res += calc(ore, nP);
			swap(ore.per[i], ore.per[i+1]); ore.dep--;
		}
		return dp[id][ore.dep] = res;
	}
} 

void sol() {
	data Start;
	for (int i = 1; i <= n; ++i) Start.per.push_back(a[i]);
	Start.dep = 0; 

	long double res = calc(Start, 1);
	cout << setprecision(5) << fixed << res << '\n';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	else if (fopen("p12n.inp", "r")) {
		freopen("p12n.inp", "r", stdin);
		freopen("p12n.out", "w", stdout);
	}

	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];

	int num = 0;
	for (int i = 1; i <= n; ++i) c[i] = i-1;

	do {

		vis[ c[1] ][ c[2] ][ c[3] ][ c[4] ][ c[5] ][ c[6] ][ c[7] ][ c[8] ] = ++num;

	} while ( next_permutation(c+1, c+n+1) );
	assert(num < 41000);

	sol();

	return 0;
}