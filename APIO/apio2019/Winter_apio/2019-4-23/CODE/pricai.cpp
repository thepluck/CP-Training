#include<bits/stdc++.h>
#define int 			long long
using namespace std;

void Read(int &val) {
	val = 0; char c;
	do { c = getchar(); } while (!isdigit(c) && c != '-');
	bool Minus = false; if (c == '-') { Minus = true; c = getchar(); }
	while (isdigit(c)) { val = val * 10 + c - '0'; c = getchar(); }
	if (Minus) val = -val;
}
void Write(int val) {
	if (val < 0) putchar('-'), Write(-val);
	else if (val < 10) putchar('0' + val);
	else Write(val/10), putchar('0' + val%10);
}

struct data {
	int A, B, Time, type;
	data() {}; data(int A, int B, int Time, int type) : A(A), B(B), Time(Time), type(type) {};
};

const int N = 3e5 + 4;
int n, m;
vector<data> ques;

vector<int> rar;
int maxVal;

void compress() {
	for (data foo : ques) {
		int A = foo.A, B = foo.B;
		if (B >= A) continue;
		rar.push_back(A-B);
	}

	sort(rar.begin(), rar.end());
	rar.resize(unique(rar.begin(), rar.end()) - rar.begin());
	maxVal = (int) rar.size() + 2;
}

int Find(int val) {
	return lower_bound(rar.begin(), rar.end(), val) - rar.begin() + 1;
}

struct Interval_Tree {
	int node_cnt[4*N], node_val[4*N];

	void update(int i, int l, int r, int x, int y, int type, int val) {
		if (l > y || x > r) return;
		if (x <= l && r <= y) {
			node_cnt[i] += type;
			node_val[i] += type * val;
			return;
		}
		int mid = (l + r) / 2;
		update(2*i, l, mid, x, y, type, val);
		update(2*i+1, mid+1, r, x, y, type, val);
		node_cnt[i] = node_cnt[2*i] + node_cnt[2*i+1];
		node_val[i] = node_val[2*i] + node_val[2*i+1];
	}

	int get(int i, int l, int r, int rank) {
		if (l == r) return min(node_cnt[i], rank) * rar[l-1];
		int mid = (l + r) / 2;
		if (rank <= node_cnt[2*i+1]) return get(2*i+1, mid+1, r, rank);
		return get(2*i, l, mid, rank - node_cnt[2*i+1]) + node_val[2*i+1];
	}
} IT;

void sol() {
	sort(ques.begin(), ques.end(), [] (data a, data b) {
		return a.Time < b.Time;
	});

	compress();

	int curTime = 0, val = 0, Bonus = 0, sz = 0, res = 0;
	for (data foo : ques) {
		int A = foo.A, B = foo.B, Time = foo.Time, type = foo.type;
		
		res += (Time - curTime) * (val+Bonus);
		curTime = Time; sz += type;

		if (B >= A) Bonus += type * B;
		else {
			int pos = Find(A-B);
			assert( rar[pos-1] == A-B );
			IT.update(1, 1, maxVal, pos, pos, type, A-B);
			Bonus += type * B; 
			val = IT.get( 1, 1, maxVal, m );
		}
	}
	Write(res); putchar('\n');
}

main() {
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	else if (fopen("pricai.inp", "r")) {
		freopen("pricai.inp", "r", stdin);
		freopen("pricai.out", "w", stdout);
	} 

	Read(n); Read(m);
	int A, B, S, F;
	for (int i = 1; i <= n; ++i) {
		Read(A); Read(B); Read(S); Read(F);
		ques.push_back( data(A, B, S,  1) );
		ques.push_back( data(A, B, F, -1) );
	}

	sol();

	return 0;
}