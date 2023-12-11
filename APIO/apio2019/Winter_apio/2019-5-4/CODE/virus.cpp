#include<bits/stdc++.h>
// #define int 				long long
#define BIG 				vector<int>
#define FOR(i, a, b)		for (int i = a; i <= (int) b; ++i)
#define REP(i, a, b) 		for (int i = a; i <  (int) b; ++i)
using namespace std;

typedef unsigned long long ULL;
int n, k, orgN;
string S;

namespace Sub1 {
	const int BASE = 10, LEN = 1e5 + 4, N = 2004;

	void fix(BIG &a){
	    a.push_back(0);
	    REP(i, 0, a.size()-1) { 
	        a[i+1]+=a[i]/BASE; a[i]%=BASE; 
	        if (a[i]<0) { a[i]+=BASE; a[i+1]--; }
	    }
	    while (a.size()>=2 && a.back()==0) a.pop_back();
	}

	void operator += (BIG &a, const BIG &b) { 
	    a.resize(max(a.size(), b.size()));
	    REP(i, 0, b.size()) a[i]+=b[i];
	    fix(a);
	}
	BIG operator + (BIG a, const BIG &b) { a+=b; return a; }

	BIG to_BIG(int x) { 
		BIG tmp = BIG(1, x); fix(tmp);
		return tmp; 
	}

	void Optimize(BIG a) {
		reverse(a.begin(), a.end());
		while (a.size() > k) a.pop_back();
		reverse(a.begin(), a.end()); 
	}

	void Print(BIG a) {
		cout << a.back();
		for (int i = (int) a.size()-2; i >= 0; --i) cout << setfill('0') << setw(1) << a[i];
		cout << '\n'; 
	}

	ULL HashA, HashB[LEN], Pow[LEN];

	ULL getHashB(int l, int r) { return (l == 0) ? HashB[r] : HashB[r] - HashB[l-1] * Pow[r-l+1]; }
	int Count_appear(string A, string B) {
		HashA = 0;
		for (int i = 0; i < (int) A.length(); ++i) HashA = HashA * 31 + A[i] - '0' + 1;
		for (int i = 0; i < (int) B.length(); ++i) HashB[i] = HashB[i-1] * 31 + B[i] - '0' + 1;
		for (int i = 0; i <= (int) B.length(); ++i) Pow[i] = (i == 0) ? 1 : Pow[i-1] * 31;

		int res = 0;
		for (int i = 0; i < (int) B.length(); ++i) {
			int nx = i + A.length() - 1;
			if (nx >= (int) B.length()) break;
			if ( getHashB(i, nx) == HashA ) res++;
		}
		return res;
	}

	BIG F[N], Add[3][3], ore_Bonus[2][2];
	string str[N], Bonus[2];
	int Minus[2];

	BIG process(int type) {
		n = orgN;
		if (type == 0) str[0] = "0", str[1] = "01";
		else str[0] = "1", str[1] = "0";

		int Start = -1;
		for (int Time = 2; Time <= n+4; ++Time) {
			str[Time] = str[Time-1] + str[Time-2];
			if (str[Time-2].length() >= S.length()) { Start = Time-2; break; }
		}
		if (Start == -1 || n < Start) {
			Bonus[type] = str[n];
			return to_BIG(0);
		}
		int cc1 = Count_appear(S, str[Start]);
		int cc2 = Count_appear(S, str[Start+1]);
		F[1] = to_BIG( cc1 );
		F[2] = to_BIG( cc2 );
		F[3] = to_BIG( Count_appear(S, str[Start+2]) );

		int tt12 = Count_appear(S, str[Start]+str[Start+1]) - cc1 - cc2;
		int tt22 = Count_appear(S, str[Start+1]+str[Start+1]) - cc2 - cc2;
		
		Add[1][2] = to_BIG(tt12);
		Add[2][2] = to_BIG(tt22);

		for (int i = 4; i <= n-Start+1; ++i) {
			if (i % 2 == 0) F[i] = F[i-1] + F[i-2] + Add[1][2];
			else F[i] = F[i-1] + F[i-2] + Add[2][2];
			Optimize(F[i]);
		} 
		Bonus[type] = ( (n-Start+1) % 2 == 1 ) ? str[Start] : str[Start+1]; 
		Minus[type] = ( (n-Start+1) % 2 == 1 ) ? cc1 : cc2; 
		return F[n-Start+1];
	}

	void sol() {
		/// n > Start
		BIG tmp_0 = process(0); //Print(tmp_0); 
		BIG tmp_1 = process(1); //Print(tmp_1); 

			// Print(tmp_1);

		FOR(i, 0, 1) FOR(j, 0, 1) {
			int tmp = Count_appear(S, Bonus[i]+Bonus[j]) - Minus[i] - Minus[j]; 
			ore_Bonus[i][j] = to_BIG(tmp);
		}

		BIG res; 
		for (int i = 0; i < (int) S.length(); ++i) {
			res += (S[i] == '0') ? tmp_0 : tmp_1;
			if ( i < (int) S.length()-1 ) {
				res += ore_Bonus[ S[i]-'0' ][ S[i+1]-'0' ];
				Optimize(res);
			}
		}
		Print(res);
	}
}

main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	else if (fopen("virus.inp", "r")) {
		freopen("virus.inp", "r", stdin);
		freopen("virus.out", "w", stdout);
	}

	while (cin >> n >> k >> S) {
		--n; 
		orgN = n; 
		if (n <= 2000) Sub1::sol();
		else assert(1 == 0);
	}

	return 0;
}