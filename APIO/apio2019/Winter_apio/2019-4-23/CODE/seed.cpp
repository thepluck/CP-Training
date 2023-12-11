#include<bits/stdc++.h>
#define FOR(i, a, b)				for (int i = a; i <= (int) b; ++i)
#define REP(i, a, b)				for (int i = a; i <  (int) b; ++i)
using namespace std;

const int N = 54, MASK = 1e6 + 4;
int n, numQues, len;
string S, str;

bool BIT(int n, int k) { return n & (1<<k); }

struct Aho_Corasick {
	int Next[MASK][2], numNode;
	bool isEnd[MASK];

	void Insert(string str) {
		int curNode = 0;
		for (int i = 0; i < len; ++i) {
			int bit = str[i] - '0';
			if (Next[curNode][bit] == 0) Next[curNode][bit] = ++numNode;
			curNode = Next[curNode][bit];
		}
		isEnd[curNode] = true;
	}

	int KMP[MASK];
	queue<int> Q;

	void BFS() {
		Q.push(0); 
		while (Q.size()) {
			int u = Q.front(); Q.pop();
			for (int bit = 0; bit <= 1; ++bit) {
				int v = Next[u][bit];
				if (v != 0) {
					if (u != 0) KMP[v] = Next[KMP[u]][bit]; else KMP[v] = 0;
					Q.push(v);
				}
				if (v == 0) Next[u][bit] = Next[KMP[u]][bit];
			}
		}
	}
} trie;

void Build_Trie() {
	REP(i, 0, len) numQues += (S[i] == '*');

	REP(mask, 0, (1<<numQues)) {
		str = ""; int curBit = 0;
		REP(i, 0, len) {
			if (S[i] != '*') { str += S[i]; continue; }
			if (BIT(mask, curBit)) str += '1'; else str += '0';
			curBit++;
 		}
 		trie.Insert(str);
	}

	trie.BFS();
}

long long dp[N][MASK];

void Build_Dp() {
	dp[0][0] = 1;
	REP(i, 0, n) REP(node, 0, trie.numNode) {
		if (dp[i][node] == 0) continue;
		FOR(bit, 0, 1) {
			int nxNode = trie.Next[node][bit];
			if (trie.isEnd[nxNode]) continue;
			dp[i+1][nxNode] += dp[i][node];
		}
	}
}

long long Pow[MASK];

void get_Ans() {	
	for (int i = 0; i <= n; ++i) Pow[i] = (i == 0) ? 1 : Pow[i-1] * 2LL; 

	long long ans = 0;
	FOR(i, len, n) REP(node, 0, trie.numNode) {
		int nxNode_0 = trie.Next[node][0];
		if (trie.isEnd[nxNode_0]) ans += dp[i-1][node] * Pow[n-i];
		int nxNode_1 = trie.Next[node][1];
		if (trie.isEnd[nxNode_1]) ans += dp[i-1][node] * Pow[n-i];
	}
	cout << ans << '\n';
}

void sol() {
	Build_Trie();
	Build_Dp();
	get_Ans();
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	} 
	else if (fopen("seed.inp", "r")) {
		freopen("seed.inp", "r", stdin);
		freopen("seed.out", "w", stdout);
	}

	cin >> n >> S;
	len = (int) S.length();

	sol();

	return 0;
}