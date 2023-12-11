#include<bits/stdc++.h>
using namespace std;

typedef pair<int, string> is;

const int N = 2e6 + 4;
string S;
int TTest;
vector<is> ques;

namespace Sub1 {
	int Map[20004];

	void sol() {
		for (int T = 0; T < TTest; ++T) {
			int type = ques[T].first; S = ques[T].second;
			if (type == 0) {
				int code = 1;
				for (int i = 0; i < (int) S.length(); ++i) code = code * 2 + S[i] - '0';
				Map[code]++;
			}
			else {
				long long res = 0;	
				for (int l = 0; l < (int) S.length(); ++l) {
					int r = l; int code = 1;
					while (r < (int) S.length() && r-l+1 <= 10) {
						code = code * 2 + S[r] - '0'; ++r;
						res += Map[code];
					} 
				}
				cout << res << '\n';
			}
		}
	}
}

namespace Sub2 {
	struct Trie_Tree {
		int Next[N][2], numEnd[N], numNode;

		void Insert(string str) {
			int curNode = 0;
			for (int i = 0; i < (int) str.length(); ++i) {
				int c = str[i] - '0';
				if (Next[curNode][c] == 0) Next[curNode][c] = ++numNode;
				curNode = Next[curNode][c]; 
			}
			numEnd[curNode]++;
		}

		queue<int> Q;

		void BFS() {
			Q.push(0); Next[0] = -1;
			while (Q.size()) {
				int u = Q.front(); Q.pop();
				for (int bit = 0; bit < 2; ++bit) {
					int v = Next[u][bit];
					if (u != 0) { KMP[v] = Next[KMP[u]][bit]; numEnd[v] += numEnd[KMP[v]]; Q.push(v); } 
					if (v == 0) Next[u][bit] = Next[KMP[u]][bit]; 
				}
			}
		}
	} trie;

	void sol() {
		for (int T = 0; T < TTest; ++T) {
			int type = ques[T].first; S = ques[T].second;
			if (type == 0) trie.Insert(S);
			else {
				trie.BFS();
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}

	cin >> TTest; 
	int type, isSub2;
	for (int T = 1; T <= TTest; ++T) {
		cin >> type >> S;
		ques.push_back( is(type, S) );
		if ( (int) S.length() > 10 ) isSub2 = true;
	}

	Sub1::sol();
	// if (!isSub2) Sub1::sol();
	// else Sub2::sol();

	return 0;
}