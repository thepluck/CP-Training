#include<bits/stdc++.h>
using namespace std;

void Read(int &val) {
	val = 0; char c;
	do { c = getchar(); } while (!isdigit(c));
	while (isdigit(c)) { val = val * 10 + c - '0'; c = getchar(); }
}

const int N = 1e5 + 4, oo = 1e9 + 7;
int n;
vector<int> adj[N];

int Time, low[N], num[N], topo[N], numTopo;
stack<int> Stack;

void DFS(int u) {
	low[u] = num[u] = ++Time;
	Stack.push(u);
	for (int v : adj[u]) {
		if (num[v]) low[u] = min(low[u], num[v]);
		else {
			DFS(v);
			low[u] = min(low[u], low[v]);
		} 
	}

	if (low[u] == num[u]) {
		int v = -1; ++numTopo;
		while (v != u) {
			v = Stack.top(); Stack.pop();
			topo[v] = numTopo; 
			low[v] = num[v] = oo;
		} 
	}
} 

bool vis[N];
vector<int> dag[N];

void detect_comp(int u) {
	vis[u] = true;
	for (int v : dag[u]) if (!vis[v]) detect_comp(v);
}

void sol() {
	Time = numTopo = 0;
	for (int i = 1; i <= n; ++i) {
		low[i] = num[i] = topo[i] = vis[i] = 0;
		dag[i].clear();
	}
	
	for (int i = 1; i <= n; ++i) if (!num[i]) DFS(i);
	
	for (int u = 1; u <= n; ++u) 
		for (int v : adj[u]) if (topo[u] != topo[v]) {
			dag[topo[u]].push_back(topo[v]); 
			dag[topo[v]].push_back(topo[u]);
		}

	int res = 0;
	for (int i = 1; i <= numTopo; ++i) 
		if (!vis[i]) detect_comp(i), res++;
	cout << res << " ";
}

int main() {
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout); 
	}
	else if (fopen("boxes.inp", "r")) {
		freopen("boxes.inp", "r", stdin);
		freopen("boxes.out", "w", stdout);
	}

	for (int TTest = 1; TTest <= 2; ++TTest) {
		Read(n);
		for (int i = 1; i <= n; ++i) {
			int dad; Read(dad);
			adj[dad].push_back(i); 
		}

		sol();

		for (int i = 1; i <= n; ++i) adj[i].clear();
	}

	return 0;
}