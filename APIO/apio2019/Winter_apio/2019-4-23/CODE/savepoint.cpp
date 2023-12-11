#include<bits/stdc++.h>
using namespace std;

struct data {
	vector<int> per;
	int dep;

	void debug() {
		cerr << "PERMUTATION : ";
		for (int val : per) cerr << val << " "; cerr << "\n";
		cerr << "DEPTH : " << dep << "\n\n";
	}

	// int getID() {
	// 	for (int i = 0; i < (int) per.size(); ++i) {

	// 	}
	// } 

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

const int N = 10;
int n, a[N];

map<data, long double> Map;

long double calc(data ore, long double p) {
	if ( Map.count(ore) ) return Map[ore];
	if ( ore.dep >= 150 ) return Map[ore] = 0;
	if ( ore.isArrange() ) return (long double) p * ore.dep;


	if ( ore.dep % 2 == 0 ) { /// optimal
		long double res = 0; bool flag = false;
		for (int i = 0; i < (int) ore.per.size()-1; ++i) {
			if (ore.per[i] < ore.per[i+1]) continue;

			swap(ore.per[i], ore.per[i+1]); ore.dep++;
			long double tmp = calc(ore, p);
			if ( tmp != (long double) 0 ) { res = (!flag) ? tmp : min( res, tmp ); flag = true; }
			swap(ore.per[i], ore.per[i+1]); ore.dep--;
		}
		return Map[ore] = res;
	}
	else {
		long double res = 0, nP = p / (long double) (n-1);
		for (int i = 0; i < (int) ore.per.size()-1; ++i) {	
			swap(ore.per[i], ore.per[i+1]); ore.dep++;
			res += calc(ore, nP);
			swap(ore.per[i], ore.per[i+1]); ore.dep--;
		}
		return Map[ore] = res;
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

	sol();

	return 0;
}