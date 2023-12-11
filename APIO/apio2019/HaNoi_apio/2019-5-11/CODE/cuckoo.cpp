#include<bits/stdc++.h>
using namespace std;

void Read(int &val) {
	val = 0; char c;
	do { c = getchar(); } while (!isdigit(c));
	while (isdigit(c)) { val = val * 10 + c - '0'; c = getchar(); }
}
void Write(long long val) {
	if (val < 0) putchar('-'), Write(-val);
	else if (val < 10) putchar('0' + val);
	else Write(val/10), putchar('0' + val%10);
}

const int N = 2e5 + 4;
int n, m, Q;

int par[N], numEdge[N], Full;
long long Sub, ore_Sub;

int getRoot(int u) { return (par[u] < 0) ? u : (par[u] = getRoot(par[u])); }
void Merge(int u, int v) {
	u = getRoot(u); v = getRoot(v);
	if (u == v) { 
		numEdge[u]++; 
		if ( numEdge[u] == abs(par[u]) ) {
			Sub += 1LL * numEdge[u] * (numEdge[u]-1) - 1LL * numEdge[u];
			ore_Sub += 1LL * numEdge[u] * Full;
			Full += numEdge[u];
		}
		return; 
	}
	if (par[u] > par[v]) swap(u, v);
	numEdge[u] += numEdge[v];
	par[u] += par[v]; par[v] = u;
} 

void sol() {
	while (Q--) {
		Read(type);
		if (type == 1) {
			Read(u); Read(v);
			int dad_u = getRoot(u), dad_v = getRoot(v);
			if ( dad_u == dad_v && numEdge[dad_u] >= abs(par[dad_u]) ) puts("No");
			else puts("Yes");
		}
		else if (type == 2) {
			Read(u); Read(v);
			int dad_u = getRoot(u), dad_v = getRoot(v);
			if ( dad_u == dad_v && numEdge[dad_u] >= abs(par[dad_u]) ) puts("No");
			else {
				puts("Yes");	
				Merge(u, v);
			}
		}
		else {
			long long res = 1LL * n*(n-1) - oreSub - Sub;
			Write(res*2); putchar('\n');
		}
	}
}

int main() {
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	else if (fopen("cuckoo.inp", "r")) {
		freopen("cuckoo.inp", "r", stdin);
		freopen("cuckoo.out", "w", stdout);
	}

	Read(n); Read(m); Read(Q);
	for (int i = 1; i <= n; ++i) par[i] = -1;

	for (int i = 1; i <= m; ++i) {
		Read(x); Read(y);
		Merge(x, y);
	}

	sol();

	return 0;
}