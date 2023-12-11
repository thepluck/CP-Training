#include <bits/stdc++.h>
 
using namespace std;
 
struct edge {
	int v, w;
};
 
const int MAXN = 200005;
 
int N, par[MAXN], dep[MAXN];
vector <edge> adj[MAXN]; bool vis[MAXN];
int wpar[MAXN], heavy[MAXN], head[MAXN];
int timer, ver[MAXN], tin[MAXN];
 
struct segTree {
	int l, r, m;
	long long sumA, tagA, maxA;
	long long sumB, sumAB;
	segTree *lef, *rig;
	
	void addA(long long A) {
		sumA += A * (r - l + 1); maxA += A;
		sumAB += A * sumB; tagA += A;
	}
	
	void push() {
		lef->addA(tagA); rig->addA(tagA);
		tagA = 0;
	}
	
	void pull() {
		sumA = lef->sumA + rig->sumA;
		sumB = lef->sumB + rig->sumB;
		sumAB = lef->sumAB + rig->sumAB;
		maxA = max(lef->maxA, rig->maxA);
	}
	
	segTree(int l, int r): l(l), r(r) {
		sumA = tagA = sumB = sumAB = maxA = 0;
		if (l == r) return;
		m = (l + r) / 2;
		lef = new segTree(l, m);
		rig = new segTree(m + 1, r);
	}
	
	void addA(int x, int y, long long A) {
		if (l >= x && r <= y) return addA(A);
		push();
		if (m >= x) lef->addA(x, y, A);
		if (m < y) rig->addA(x, y, A);
		pull();
	}
	
	void active(int p, long long B) {
		if (l == r) return void(sumB = B);
		push();
		if (m >= p) lef->active(p, B);
		else rig->active(p, B);
		pull();
	}
	
	int find(int A) {
		if (l == r) return l;
		push();
		if (rig->maxA >= A)
			return rig->find(A);
		return lef->find(A);
	}
	
	long long SumAB(int x, int y) {
		if (l >= x && r <= y) return sumAB;
		push(); long long res = 0;
		if (m >= x) res += lef->SumAB(x, y);
		if (m < y) res += rig->SumAB(x, y);
		return res;
	}
 
	long long SumB(int x, int y) {
		if (l >= x && r <= y) return sumB;
		push(); long long res = 0;
		if (m >= x) res += lef->SumB(x, y);
		if (m < y) res += rig->SumB(x, y);
		return res;
	}
};
 
int DFSpre(int u) {
    int big = 0, siz = 1, tmp;
    for (edge e : adj[u]) {
        if (e.v == par[u]) continue;
        par[e.v] = u; wpar[e.v] = e.w;
		dep[e.v] = dep[u] + 1;
        siz += tmp = DFSpre(e.v);
        if (tmp > big) {
            big = tmp; heavy[u] = e.v;
        }   
    }
    return siz;
}
 
void DFSsplit(int u) {
    ver[tin[u] = ++timer] = u;
    if (par[u] && u == heavy[par[u]])
        head[u] = head[par[u]];
    else head[u] = u;
    if (heavy[u]) DFSsplit(heavy[u]);
    for (edge e : adj[u])
        if (e.v != par[u] && e.v != heavy[u])
            DFSsplit(e.v);
}
 
int main() {
	freopen("tree.inp", "r", stdin);
	freopen("tree.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> N;
	for (int i = 1; i < N; i++) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	dep[0] = -1; DFSpre(1); DFSsplit(1);
	segTree ST(1, N);
	for (int u = 1; u <= N; u++) {
		if (u == 1) {
			ST.addA(1, 1, 1); vis[1] = 1;
			cout << "0 "; continue;
		}
		int v = u;
		while (!vis[v]) {
			ST.active(tin[v], wpar[v]);
			vis[v] = 1; v = par[v];
		}
		v = u;
		while (v) {
			ST.addA(tin[head[v]], tin[v], 1);
			v = par[head[v]];
		}
		v = ver[ST.find((u + 1) / 2)];
		long long res = ST.sumAB;
		while (v) {
			res += ST.SumB(tin[head[v]], tin[v]) * u
			- ST.SumAB(tin[head[v]], tin[v]) * 2;
			v = par[head[v]];
		}
		cout << res << ' ';
	}
}
