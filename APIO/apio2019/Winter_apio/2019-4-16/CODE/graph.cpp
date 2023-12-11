#include<bits/stdc++.h>
using namespace std;

void Read(int &val) {
	val = 0; char c;
	do { c = getchar(); } while (!isdigit(c));
	while (isdigit(c)) { val = val * 10 + c - '0'; c = getchar(); }
}

const int N = 1e5 + 4, oo = 1e9 + 7;
int T, n, a[N];

struct Interval_Tree {
	int node[2][4*N], lazy[4*N];

	void clear() { 
		for (int i = 0; i < 4*N; ++i) {
			node[0][i] = node[1][i] = lazy[i] = 0;
		}
	}

	void Down(int i) {
		for (int id = 0; id <= 1; ++id) {
			node[id][2*i] += lazy[i]; 
			node[id][2*i+1] += lazy[i];  
		}
		lazy[2*i] += lazy[i]; lazy[2*i+1] += lazy[i];  
		lazy[i] = 0;
	}

	void update(int i, int l, int r, int x, int y, int val) {
		if (l > y || x > r) return;
		if (x <= l && r <= y) {
			node[0][i] += val; node[1][i] += val; 
			lazy[i] += val;
			return;
		}
		Down(i);

		int mid = (l + r) / 2;
		update(2*i, l, mid, x, y, val);
		update(2*i+1, mid+1, r, x, y, val);

		node[0][i] = min(node[0][2*i], node[0][2*i+1]);
		node[1][i] = max(node[1][2*i], node[1][2*i+1]);
	}

	int get_val(int i, int l, int r, int x, int y, int type) {
		if (l > y || x > r) return (type == 0) ? oo : -oo;
		if (x <= l && r <= y) return node[type][i];
		Down(i);
		int mid = (l + r) / 2;
		int tmp1 = get_val(2*i, l, mid, x, y, type);
		int tmp2 = get_val(2*i+1, mid+1, r, x, y, type);
		return (type == 0) ? min(tmp1, tmp2) : max(tmp1, tmp2);
	}

	int get_pos(int i, int l, int r, int type, int val) {
		if (l == r) return l;
		Down(i);

		int mid = (l + r) / 2;
		if (type == 0) {
			if (node[0][2*i+1] <= val) return get_pos(2*i+1, mid+1, r, type, val);
			return get_pos(2*i, l, mid, type, val); 
		}
		else {
			if (node[1][2*i] >= val) return get_pos(2*i, l, mid, type, val);
			return get_pos(2*i+1, mid+1, r, type, val);
		}
	}	
} IT;

void sol() {
	for (int i = 1; i <= n; ++i) if (a[i] > n-1) { puts("NO"); return; }

	sort(a+1, a+n+1); IT.clear();
	for (int i = 1; i <= n; ++i) IT.update(1, 1, n, i, i, a[i]);

	for (int i = n; i >= 1; --i) {
		int val = IT.get_val(1, 1, n, i, i, 0);
		int point = i-val;

		if (point < 0) { puts("NO"); return; }
		if (val == 0) continue;

		int ore_val = IT.get_val(1, 1, n, point, point, 0);
		int r = IT.get_pos(1, 1, n, 0, ore_val); 
		int l = IT.get_pos(1, 1, n, 1, ore_val);
		if (r >= i) r = i-1; 

		if (ore_val <= 0 || l > r) { puts("NO"); return; }

		int num = r-point+1;
		IT.update(1, 1, n, r+1, i-1, -1);
		IT.update(1, 1, n, l, l+num-1, -1);

		if (IT.node[0][1] < 0) { puts("NO"); return; }
	}	
	puts("YES");
}

int main() {
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	else if (fopen("graph.inp", "r")) {
		freopen("graph.inp", "r", stdin);
		freopen("graph.out", "w", stdout);
	}

	Read(T);
	while (T--) {
		Read(n);
		for (int i = 1; i <= n; ++i) Read(a[i]);

		sol();
	}
 
	return 0;
}