#include<bits/stdc++.h>
using namespace std;

void Read(int &val) {
	val = 0; char c;
	do { c = getchar(); } while (!isdigit(c));
	while (isdigit(c)) { val = val * 10 + c - '0'; c = getchar(); }
}

struct dataQues {
	int l, r, h;
	dataQues() {}; dataQues(int l, int r, int h) : l(l), r(r), h(h) {};
	bool operator < (const dataQues &a) const {
		if (h != a.h) return h < a.h;
		if (l != a.l) return l < a.l;
		return r < a.r;
	}
	bool operator == (const dataQues &a) const {
		return (h == a.h && l == a.l && r == a.r);
	}
};

const int N = 1e6 + 4, LOG = 21;
int n, k;
vector<int> adj[N];

int par[N][LOG+4], Next[N];
bool Spe_ver[N];

void Build_LCA() {
	for (int j = 1; j <= LOG; ++j) for (int i = 1; i <= n; ++i) 
		par[i][j] = par[par[i][j-1]][j-1];
}
int Jump(int u, int step) {
	for (int i = LOG; i >= 0; --i) 
		if (step >= (1<<i) && par[u][i] != 0) step -= (1<<i), u = par[u][i];
	return u;
}

int numET, L[N], R[N], hei[N];

struct Interval_Tree {
	int node[4*N], lazy[4*N];

	void clear() {
		memset(node, 0, sizeof(node));
		memset(lazy, 0, sizeof(lazy));
	}

	void Down(int i) {
		if (lazy[i] == 0) return;
		node[2*i] = node[2*i+1] = lazy[i]; 
		lazy[2*i] = lazy[2*i+1] = lazy[i]; 
		lazy[i] = 0;
	}

	void update(int i, int l, int r, int x, int y, int ver) {
		if (l > y || x > r) return;
		if (x <= l && r <= y) {
			node[i] = lazy[i] = ver;
			return;
		}
		Down(i);
		int mid = (l + r) / 2;
		update(2*i, l, mid, x, y, ver);
		update(2*i+1, mid+1, r, x, y, ver);
		node[i] = max(node[2*i], node[2*i+1]);
	}

	int get(int i, int l, int r, int x, int y) {
		if (l > y || x > r) return -10000;
		if (x <= l && r <= y) return node[i]; 
		Down(i);
		int mid = (l + r) / 2;
		int tmp1 = get(2*i, l, mid, x, y), tmp2 = get(2*i+1, mid+1, r, x, y);
		return max(tmp1, tmp2);
	}

	void add(int i, int l, int r, int x, int y, int val) {
		if (l > y || x > r) return;
		if (x <= l && r <= y) { node[i] += val; return; }
		int mid = (l + r) / 2;
		add(2*i, l, mid, x, y, val);
		add(2*i+1, mid+1, r, x, y, val);
		node[i] = max(node[2*i], node[2*i+1]);
	}
} IT, Bonus;
 
void DFS(int dad, int u) {
	L[u] = ++numET; hei[u] = hei[dad] + 1; 
	for (int v : adj[u]) DFS(u, v);
	R[u] = numET;
}

void DFS_getNext(int u) {
	if (Spe_ver[u]) IT.update(1, 1, n, L[u]+1, R[u], u);
	for (int v : adj[u]) DFS_getNext(v);
}

vector<dataQues> ques;

void get_Query() {
	for (int u = 1; u <= n; ++u) {
		if (!Spe_ver[u]) continue;
		ques.push_back( dataQues(L[u], R[u], hei[u]+k) );

		int dad = Next[u]; if (dad == 0) continue;
		ques.push_back( dataQues(L[u], R[u], hei[dad]+k) );
	}
}

vector<int> V[N];

struct Binary_Indexed_Tree {
	int node[N];	

	void update(int pos, int val) {
		for (int i = pos; i < N; i += i & (-i)) node[i] += val;
	}
	int get(int pos) {
		int ans = 0;
		for (int i = pos; i > 0; i -= i & (-i)) ans += node[i];
		return ans;
	}
} BIT;

int ansQ[2*N];
map<dataQues, int> Map;

void answer_Query() {
	for (int i = 1; i <= n; ++i) if (adj[i].empty()) V[hei[i]].push_back(i);
	sort(ques.begin(), ques.end());
	ques.resize(unique(ques.begin(), ques.end()) - ques.begin());

	int curHei = 1, Time = 0;
	for (dataQues foo : ques) {
		int l = foo.l, r = foo.r, h = foo.h; ++Time;
		Map[dataQues(l, r, h)] = Time;

		while (curHei <= h) {
			for (int u : V[curHei]) BIT.update(L[u], 1); 
			++curHei;
		}
		ansQ[Time] = BIT.get(r) - BIT.get(l-1);
	}
}

int best, CC[N];

void dp_on_tree(int u) {
	for (int v : adj[u]) dp_on_tree(v);

	if (adj[u].empty()) {
		int dad = CC[u];
		Bonus.add(1, 1, n, L[dad], L[dad], 1);
		return;
	}

	if (Spe_ver[u]) {
		int dad = Next[u];
		int id1 = Map[dataQues(L[u], R[u], hei[u]+k)];
		int id2 = Map[dataQues(L[u], R[u], hei[dad]+k)];

		int Add = Bonus.get(1, 1, n, L[u], L[u]);
		int res = IT.get(1, 1, n, L[u], R[u]) + Add;
		best = max(best, res);

		if (dad != 0 && ansQ[id2] >= 1) Bonus.add(1, 1, n, L[dad], L[dad], Add);
		else if (dad != 0) IT.update(1, 1, n, L[u], L[u], res); 
	}
}

void sol() {
	Build_LCA();

	for (int v = 1; v <= n; ++v) 
		if (adj[v].empty()) {
			Next[v] = Jump(v, k); 
			Spe_ver[ Next[v] ] = true;
		}	

	DFS(0, 1);
	DFS_getNext(1);

	for (int v = 1; v <= n; ++v) {
		if (Spe_ver[v]) {
			int u = IT.get(1, 1, n, L[v], L[v]);
			Next[v] = u;
		}
		else if (adj[v].empty()) {
			int u = IT.get(1, 1, n, L[v], L[v]);
			CC[v] = u;
		}
	}

	get_Query();
	answer_Query();

	IT.clear();
	dp_on_tree(1);

	cout << best << '\n';
} 

int main() {
	if (fopen("input.txt", "r")) {	
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}

	Read(n); Read(k);
	for (int v = 2; v <= n; ++v) {
		int u; Read(u);
		adj[u].push_back(v); par[v][0] = u;
	}

	sol();

	return 0;
}