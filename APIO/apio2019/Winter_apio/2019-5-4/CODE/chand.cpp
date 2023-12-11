#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 4, oo = 1e9 + 7;
string S;

vector<int> adj[N];
stack<int> Stack;

void Build_Tree() {
	int len = S.length(); S = " " + S;
	for (int i = 1; i <= len; ++i) {
		if (S[i] == 'a') Stack.push(i);
		else {
			int num = S[i] - '0';
			while (num > 0) {
				int top = Stack.top(); Stack.pop();
				adj[i].push_back(top);
				--num;
			}
			Stack.push(i);
		}
	}
	assert( Stack.size() == 1 );
}

int dp[N];

void DFS(int u) {
	bool isLeaf = true;
	for (int v : adj[u]) { DFS(v); isLeaf = false; }

	if (isLeaf) { dp[u] = 1; return; }
	
	dp[u] = oo;
	for (int Time = 0; Time < (int) adj[u].size(); ++Time) {
		int remain = 0, cost = 0;
		for (int i = Time; i < (int) adj[u].size(); ++i) {
			int v = adj[u][i];
			cost = max(cost, remain + dp[v]);
			remain++;
		}	
		for (int i = 0; i < Time; ++i) {
			int v = adj[u][i];
			cost = max(cost, remain + dp[v]);
			remain++;
		}
		dp[u] = min(dp[u], cost);
	}
	for (int v : adj[u]) dp[u] = max(dp[u], dp[v]);
}

void sol() {
	Build_Tree();

	for (int i = 1; i <= (int) S.length(); ++i) reverse(adj[i].begin(), adj[i].end());

	int root = Stack.top();
	DFS(root);

	int res = 0;
	for (int i = 1; i <= (int) S.length(); ++i) res = max(res, dp[i]);
	cout << res << '\n';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	else if (fopen("chand.inp", "r")) {
		freopen("chand.inp", "r", stdin);
		freopen("chand.out", "w", stdout);
	}

	cin >> S;

	sol();

	return 0;
}