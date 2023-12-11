#include<bits/stdc++.h>
#define FOR(i, a, b)			for (int i = a; i <= (int) b; ++i)
#define REP(i, a, b)			for (int i = a; i <  (int) b; ++i)
using namespace std;

const int N = 104, oo = 1e9 + 7;
int n;
string S[N];

vector<int> adj[N];

void Build_graph() {
	FOR(i, 1, n) FOR(j, 1, n) {
		if (i == j) continue;

		bool ok = (S[i].length() == S[j].length()) ? true : false;
		REP(p, 0, S[i].length()) {
			if (S[i][p] == S[j][p]) continue;
			if (S[i][p] == '*' || S[j][p] == '*') continue;
			ok = false; break;
		}
		if (!ok) adj[i].push_back(j);
	}
}

vector<int> ls;
set<int> V[N];
int color[N], per[N];
bool vis[N];

void sol() {
	Build_graph();

	FOR(i, 1, n) FOR(col, 1, n) V[i].insert(col);

	int cc = 0;
	while (true) {
		int cnt = 0;
		for (int i = 1; i <= n; ++i) if (!color[i]) per[++cnt] = i;
		if  (cnt == 0) break;

		sort(per+1, per+cnt+1, [] (int a, int b) {
			return V[a].size() < V[b].size();
		});

		ls.clear();
		for (int i = 1; i <= cnt; ++i) if (V[per[i]].size() == V[per[1]].size()) ls.push_back(per[i]);
		random_shuffle(ls.begin(), ls.end());

		int u = ls[0], col = *(V[u].begin()); 
		color[u] = col;

		for (int v : adj[u]) V[v].erase( col );
	}
	
	int res = 0;
	for (int i = 1; i <= n; ++i) if (!vis[color[i]]) res++, vis[color[i]] = true;
	cout << res << '\n';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	else if (fopen("cword.inp", "r")) {
		freopen("cword.inp", "r", stdin);
		freopen("cword.out", "w", stdout);
	}

	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> S[i];

	sol();

	return 0;
}