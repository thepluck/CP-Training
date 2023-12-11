/* 
 * Author :  shora
 * Date   :  2021 Jul 01 09:38:06 PM
 */
#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cout << _ << ' ';} cout << endl;
#define pii pair<int, int>
#define X first
#define Y second
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const string FILE_NAME = "minesweeper";
mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
void file() {
  	cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  	freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  	freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
string s; int n, mod = 1e9 + 7;
void solve() {
  	cin >> s; n = s.size(); ll dp[n][6];
  	memset(dp, 0, sizeof(dp));
  	if (s[0] == '2' || s[n-1] == '2') {
  		cout << 0; return;
	}
  	/*
  	 b2b
  	 
  	b11b <-> b10..01b
 	  bb
    
	j	0	1	2	3	4
	<>	0	1	*	?-0	?-1
  	dp[i][j] = so cach dat den i ma s{i] <=> j
  	*/
  	
  	if (s[0] == '0') dp[0][0] = 1;
  	else if (s[0] == '1') dp[0][1] = 1;
  	else if (s[0] == '*') dp[0][2] = 1;
  	else if (s[0] == '?') dp[0][2] = dp[0][3] = 1;
  	
  	if (s[1] == '0') dp[1][0] = dp[0][0] + dp[0][3];
  	else if (s[1] == '1') dp[1][1] = dp[0][2];
  	else if (s[1] == '*') dp[1][2] = dp[0][1] + dp[0][3] + dp[0][2];
  	else if (s[1] == '?') {
  		dp[1][2] = dp[0][1] + dp[0][3] + dp[0][2];
  		dp[1][3] = dp[0][0] + dp[0][3];
  		dp[1][4] = dp[0][2];
	}
  	
   	for (int i = 2; i < n; ++i) {
  		if (s[i] == '2') continue; 
  		if (s[i-1] == '2') {
  			if (s[i] == '*' || s[i] == '?')
  				dp[i][2] = dp[i-2][2];
  			continue;
		}
  		if (s[i] == '0') 
		  	dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][3] + dp[i-1][4]) % mod;
  		else if (s[i] == '1') 
  			dp[i][1] = dp[i-1][2];
  		else if (s[i] == '*' || s[i] == '?') {
  			dp[i][2] = (dp[i-1][2] + dp[i-1][3] + dp[i-1][4]) % mod;
  			if (s[i-1] == '1') 
			  	dp[i][2] += (dp[i-2][0] + dp[i-2][1] + dp[i-2][3] + dp[i-2][4]) % mod;
  			if (s[i] == '?') {
  				dp[i][3] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][3] + dp[i-1][4]) % mod;
  				dp[i][4] = dp[i-1][2];
			}
  		}
	}
	
//	for (int j = 0; j < 6; ++j) {
//		for (int i = 0; i < n; ++i) cout << dp[i][j] << ' ';
//		cout << '\n';
//	}
	
	cout << (dp[n-1][0] + dp[n-1][1] + dp[n-1][2] + dp[n-1][3] + dp[n-1][4]) % mod;
}

int main() {
  	solve(); // NHO TINH DO PHUC TAP KHONG DE TRAN SO
  	return 0;
}

