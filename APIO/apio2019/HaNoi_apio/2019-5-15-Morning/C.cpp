#include<bits/stdc++.h>
#define int 			long long
using namespace std;

typedef pair<int, int> ii;

string Sub_1(string a) {
	assert(a != "0" && a != "");

	int save = 1; string ans = "";
	for (int i = (int) a.length()-1; i >= 0; --i) {
		int c = a[i] - '0';
		c -= save; save = 0;
		if (c < 0) { assert(c == -1); ans += "9"; save = 1; } 
		else ans += (char) ('0' + c);
	}

	reverse(ans.begin(), ans.end());
	while ((int) ans.length() > 0 && ans[0] == '0') ans.erase(0, 1);
	if (ans == "") ans = "0";
	return ans;
}
string Mul_10(string a) { a += "0"; return a; }

const int N = 1e5 + 4;
int n, org[N];
ii a[N];

string str;

void Print(int num) {
	str = "0.";
	for (int i = 1; i < num; ++i) str += "0";
	str += "1";	
	cout << str << '\n';
}

void sol() {
	sort(a+1, a+n+1);

	string val = "1";
	int cur = 0;
	for (int i = 1; i < n; ++i) {
		while (cur < a[i].first) { val = Mul_10(val); ++cur; }
		if (val == "0" || val == "") { cout << "NO\n"; exit(0); } 
		val = Sub_1(val);
	}

	if (cur != a[n].first) { cout << "NO\n"; exit(0); }	
	if (val == "0" || val == "") { cout << "NO\n"; exit(0); }

	string cc = val;

	bool foo = false;
	if (cc[cc.length()-1] == '0') { val = Sub_1(val); foo = true; }

	cout << "YES\n";
	for (int i = 1; i <= n; ++i) {
		if (foo && i == a[n-1].second) {
			str = "0.";
			for (int i = 1; i < a[n-1].first; ++i) str += "0";
			str += "2"; 
			cout << str << '\n';
			continue;
		}

		if (i == a[n].second) {
			string cc = val;
			reverse(cc.begin(), cc.end());
			while ((int) cc.length() < cur) cc += "0";
			reverse(cc.begin(), cc.end());

			cout << "0."; 
			cout << cc << '\n';
		}
		else Print(org[i]);
	}
}

main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].first; a[i].second = i;
		org[i] = a[i].first;
		assert(org[i] > 0);
	}

	sol();

	return 0;
}