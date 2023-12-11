#include<bits/stdc++.h>
#define FOR(i, a, b)				for (int i = a; i <= (int) b; ++i)
#define REP(i, a, b)				for (int i = a; i <  (int) b; ++i)
using namespace std;

const int N = 54, MASK = 1e6 + 4;
int n, k;
long double p_0, p_1;
string S[12], str;

bool BIT(int n, int k) { return n & (1<<k); }

struct Aho_Corasick {
	int Next[MASK][2], numNode;
	bool isEnd[MASK];

	void Insert(string str) {
		int curNode = 0;
		for (int i = 0; i < (int) str.length(); ++i) {
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
	FOR(id, 1, k) {
		int len = S[id].length(), numQues = 0;
		REP(i, 0, len) numQues += (S[id][i] == '*');

		REP(mask, 0, (1<<numQues)) {
			str = ""; int curBit = 0;
			REP(i, 0, len) {
				if (S[id][i] != '*') { str += S[id][i]; continue; }
				if (BIT(mask, curBit)) str += '1'; else str += '0';
				curBit++;
	 		}
	 		trie.Insert(str);
		}
	}

	trie.BFS();
}

long double dp[N][MASK];

void Build_Dp() {
	dp[0][0] = (long double) 1;	
	REP(i, 0, n) REP(node, 0, trie.numNode) {
		if ( dp[i][node] == (long double) 0 ) continue;
		FOR(bit, 0, 1) {
			int nxNode = trie.Next[node][bit];
			if (trie.isEnd[nxNode]) continue;
			if (bit == 0) dp[i+1][nxNode] += p_0 * dp[i][node];
			else dp[i+1][nxNode] += p_1 * dp[i][node];
		}
	}
}

void get_Ans() {	
	long double ans = 0;
	FOR(i, 1, n) REP(node, 0, trie.numNode) {
		int nxNode_0 = trie.Next[node][0];
		if (trie.isEnd[nxNode_0]) ans += dp[i-1][node] * p_0;
		int nxNode_1 = trie.Next[node][1];
		if (trie.isEnd[nxNode_1]) ans += dp[i-1][node] * p_1;
	}
	cout << setprecision(5) << fixed << ans << '\n';
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
	else if (fopen("kphit.inp", "r")) {
		freopen("kphit.inp", "r", stdin);
		freopen("kphit.out", "w", stdout);
	}

	cin >> n >> k >> p_1; p_0 = (long double) 1 - p_1;
	FOR(i, 1, k) cin >> S[i];

	sol();

	return 0;
}