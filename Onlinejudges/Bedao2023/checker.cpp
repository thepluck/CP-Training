#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

int f(const vector <int>& A){
	if ((int)A.size() == 0){
		return 0;
	}
	int ans = 1, mx = A[0];
	for (int i = 1; i < (int)A.size(); i++){
		if (mx < A[i]){
			mx = A[i];
			ans++;
		}
	}
	return ans;
}

bool readAns(InStream& stream, int N, const vector <int>& A){
	string yn = stream.readToken("YES|NO", "has-answer?");
	if (yn == "YES"){
		string S = stream.readToken("[DM]+", "trace");
		if ((int)S.length() != N){
			stream.quitf(_wa, "length of S is %d, expected %d", (int)S.length(), N);
		}
		vector <int> D, M;
		for (int i = 0; i < N; i++){
			if (S[i] == 'D'){
				D.emplace_back(A[i]);
			}
			else if (S[i] == 'M'){
				M.emplace_back(A[i]);
			}
			else{
			    stream.quitf(_wa, "unrecognized character %c", S[i]);
			}
		}
		int fD = f(D), fM = f(M);
		if (fD != fM){
			stream.quitf(_wa, "f(D) = %d is different from f(M) = %d", fD, fM);
		}
		return true;
	}
	else if (yn == "NO"){
		return false;
	}
	else{
		stream.quitf(_wa, "unrecognized token %s", yn.c_str());
	}
}

signed main(int argc, char *argv[]){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	registerTestlibCmd(argc, argv);

	int watest = 0;

	int T = inf.readInt(1, 1000000, "T");
	for (int t = 1; t <= T; t++){
	    setTestCase(t);
		int N = inf.readInt();
		vector <int> A = inf.readInts(N);

		bool jans = readAns(ans, N, A);
		bool pans = readAns(ouf, N, A);
		if (pans and not jans){
			quitf(_fail, "failed on test %d", t);
		}
		else if (jans and not pans){
			
			vector<int> val;
			for (int i = 0; i < N; i++)
				val.push_back(A[i]);
			sort(val.begin(), val.end());
			for (int i = 0; i < N; i++)
				cout << upper_bound(val.begin(), val.end(), A[i]) - val.begin() << " \n"[i == N - 1];
			if (watest == 0){
				watest = t;
			}
		}
	}
	if (watest != 0){
		quitf(_wa, "wa first on test %d", watest);
	}
	else{
		quitf(_ok, "ok");
	}
}