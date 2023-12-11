#include<bits/stdc++.h>
#define FOR(i, a, b)			for (int i = a; i <= (int) b; ++i)
using namespace std;

struct data {
	int ore, i, j, flag;
	data() {}; data(int ore, int i, int j, int flag) : ore(ore), i(i), j(j), flag(flag) {};
};

const int N = 2004, oo = 1e8 + 4;
string X, S, tmpX, tmpS;

bool canErase(char a, char b) {
	if (a == '1' && b == '2') return true;
	if (a == '2' && b == '1') return true;
	if (a == '3' && b == '4') return true;
	if (a == '4' && b == '3') return true;
	return false;
}

void compress_X() {
	while (true) {
		bool isEnd = true;
		for (int i = 0; i < (int) X.length()-1; ++i) 
			if (canErase(X[i], X[i+1])) { X.erase(i, 2); isEnd = false; break; }
		if (isEnd) break;
	}
	X = " " + X;
}

int KMP[N], Next[N][5];

int Jump(int pos, int c) {
	while (pos > 0 && S[pos+1] - '0' != c) pos = KMP[pos];
	if (S[pos+1] - '0' == c) ++pos;
	return pos;
}

void Build_KMP_S() {
	int len = S.length(); S = " " + S; 
	int j = 0; KMP[1] = 0;
	for (int i = 2; i <= len; ++i) {
		while (j > 0 && S[j+1] != S[i]) j = KMP[j];
		if (S[i] == S[j+1]) ++j; 
		KMP[i] = j;
	}

	for (int i = 0; i <= len; ++i) {
		for (int c = 1; c <= 4; ++c) Next[i][c] = Jump(i, c);
	}	
}

vector<string> V;
int dp[N][N][2];
data Trace[N][N][2];

int calc(int i, int j, int flag) {
	if (i > (int) X.length()-1) return (flag) ? 0 : oo;
	
	int &foo = dp[i][j][flag];
	if (foo != -1) return foo; foo = oo;
	
	for (int ore = 0; ore < (int) V.size(); ++ore) {
		string Add = V[ore];

		int nJ = Next[ j ][ Add[0]-'0' ], nFlag = flag; 
		nFlag |= (nJ == (int) S.length()-1);
		nJ = Next[ nJ ][ Add[1]-'0' ];
		nFlag |= (nJ == (int) S.length()-1);

		int val = calc(i, nJ, nFlag) + 2;
		if (foo > val) { foo = val; Trace[i][j][flag] = data(ore, i, nJ, nFlag); }
	}	

	int nJ = Next[j][X[i+1]-'0'], nFlag = flag | (nJ == (int) S.length()-1); 

	int val = calc(i+1, nJ, nFlag);
	if (foo > val) { foo = val; Trace[i][j][flag] = data(-1, i+1, nJ, nFlag); }

	return foo;
}

string ans;

void get_Dp() {
	int n = (int) X.length()-1, m = (int) S.length()-1;

	V.push_back("12"); V.push_back("21");
	V.push_back("34"); V.push_back("43");

	memset(dp, -1, sizeof(dp)); 
	int res = calc(0, 0, 0);

	int i = 0, j = 0, flag = 0;
	while (i <= n) {
		data Prev = Trace[i][j][flag];
		if (Prev.ore == -1) {
			if (i+1 <= n) ans += X[i+1];
		}
		else ans += V[Prev.ore];
		i = Prev.i; j = Prev.j; flag = Prev.flag;
	}

	for (int i = 0; i < (int) ans.size(); ++i) {
		if (ans[i] == '1') putchar('a');
		else if (ans[i] == '2') putchar('A');
		else if (ans[i] == '3') putchar('b');
		else putchar('B');
	}
}

void sol() {
	compress_X();
	Build_KMP_S();	
	get_Dp();
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	else if (fopen("subword.inp", "r")) {
		freopen("subword.inp", "r", stdin);
		freopen("subword.out", "w", stdout);
	}

	cin >> tmpX >> tmpS;
	for (int i = 0; i < (int) tmpX.length(); ++i) {
		if (tmpX[i] == 'a') X += "1";
		else if (tmpX[i] == 'A') X += "2";
		else if (tmpX[i] == 'b') X += "3";
		else X += "4";
	}
	for (int i = 0; i < (int) tmpS.length(); ++i) {
		if (tmpS[i] == 'a') S += "1";
		else if (tmpS[i] == 'A') S += "2";
		else if (tmpS[i] == 'b') S += "3";
		else S += "4";
	}

	sol();

	return 0;
}