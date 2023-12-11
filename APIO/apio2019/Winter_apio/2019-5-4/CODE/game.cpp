#include<bits/stdc++.h>
using namespace std;

void Read(int &val) {
	val = 0; char c;
	do { c = getchar(); } while (!isdigit(c));
	while (isdigit(c)) { val = val * 10 + c - '0'; c = getchar(); }
}

const int N = 504;
int n1, n2, m;
vector<int> adj[N];

bool Disable[N][2];
int Match[N], Assign[N], vis[N], Time;

bool DFS(int u) {
	if (vis[u] == Time || Disable[u][0]) return false; vis[u] = Time;
	for (int v : adj[u]) { 
		if (Disable[v][1]) continue; 
		if (!Assign[v] || DFS(Assign[v])) {
			Assign[v] = u; Match[u] = v;
			return true;
		}
	}
	return false;
}

int Find_Maximum_Matching() {
	for (int u = 1; u <= max(n1, n2); ++u) Match[u] = Assign[u] = 0; Time = 0;

	int numPair = 0;
	while (true) {
		++Time; bool isEnd = true;
		for (int u = 1; u <= n1; ++u) {
			if (Match[u] || vis[u] == Time || !DFS(u) || Disable[u][0]) continue;
			isEnd = false; numPair++;
		}
		if (isEnd) break;
	}
	return numPair;
}

bool in_all[N][2];
int Count[N][2];

void sol() {
	int maxPair = Find_Maximum_Matching();

	for (int u = 1; u <= n1; ++u) {
		Disable[u][0] = true;
		int curPair = Find_Maximum_Matching();
		Disable[u][0] = false;

		if (curPair != maxPair) in_all[u][0] = true; 
		for (int v = 1; v <= n1; ++v) Count[v][0] += (Match[v] != 0);
		for (int v = 1; v <= n2; ++v) Count[v][1] += (Assign[v] != 0);
	}

	for (int u = 1; u <= n2; ++u) {
		Disable[u][1] = true;
		int curPair = Find_Maximum_Matching();
		Disable[u][1] = false;

		if (curPair != maxPair) in_all[u][1] = true; 
		for (int v = 1; v <= n1; ++v) Count[v][0] += (Match[v] != 0);
		for (int v = 1; v <= n2; ++v) Count[v][1] += (Assign[v] != 0);
	}

	for (int u = 1; u <= n1; ++u) {
		if (in_all[u][0]) putchar('N');
		else if (Count[u][0] == 0) putchar('P');
		else putchar('P'); 
	} 
	putchar('\n');
	
	for (int u = 1; u <= n2; ++u) {
		if (in_all[u][1]) putchar('N');
		else if (Count[u][1] == 0) putchar('P');
		else putchar('P');
	}
	putchar('\n');
}

int main() {
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}

	Read(n1); Read(n2); Read(m);
	int u, v;
	for (int i = 1; i <= m; ++i) {
		Read(u); Read(v);
		adj[u].push_back(v);
	}
	
	sol();

	return 0;
}