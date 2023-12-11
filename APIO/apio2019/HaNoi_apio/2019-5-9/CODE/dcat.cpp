#include<bits/stdc++.h>
#define int 			long long
using namespace std;

void Read(int &val) {
	val = 0; char c;
	do { c = getchar(); } while (!isdigit(c));
	while (isdigit(c)) { val = val * 10 + c - '0'; c = getchar(); }
}

const int N = 3e5 + 4;
int n, m;
vector<int> adj[N];

int low[N], num[N], numComp[N], Time;
bool isCritical[N];

void Critical_DFS(int par, int u) {
	num[u] = low[u] = ++Time;

	int child = 0;
	for (int v : adj[u]) if (v != par) {
		if (num[v]) low[u] = min(low[u], num[v]);
		else {
			Critical_DFS(u, v); ++child;
			low[u] = min(low[u], low[v]);

			if (par == 0) {
				if (child > 1) isCritical[u] = true, numComp[u]++; 
			}
			else {
				if (low[v] >= num[u]) isCritical[u] = true, numComp[u]++;
			}
		}
 	}
}


void sol() {
	Critical_DFS(0, 1);

		// for (int i = 1; i <= n; ++i) cerr << "# " << i << " " << numComp[i] << '\n';
		// exit(0);
		// cerr << "# " << numComp[2] << '\n';
		// exit(0);

	int res = 0;
	for (int i = 1; i <= n; ++i) {
		// if ( !isCritical[i] ) continue;
			// cerr << "# dm \n";
		if ( numComp[i]+1 == (n-1) - (m - adj[i].size()) ) res += i;
		// cout << numComp[i]+1 << '\n';
	}
	cout << res << '\n';
}

main() {
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	else if (fopen("dcat.inp", "r")) {
		freopen("dcat.inp", "r", stdin);
		freopen("dcat.out", "w", stdout);
	}

	Read(n); Read(m);
	int u, v;
	for (int i = 1; i <= m; ++i) {
		Read(u); Read(v); 
		adj[u].push_back(v); adj[v].push_back(u);
	}

	sol();

	return 0;
}