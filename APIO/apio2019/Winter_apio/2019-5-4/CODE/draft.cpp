#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("output.txt", "w", stdout);

	string X = "0";
	cout << X << '\n';

	int time_limit = 3;
	for (int Time = 1; Time <= time_limit; ++Time) {
		string ans = "";
		for (int i = 0; i < (int) X.length(); ++i) 
			if (X[i] == '0') ans += "01"; 
			else ans += "0";
		X = ans;
		cout << X << '\n';
	}

	return 0;
}