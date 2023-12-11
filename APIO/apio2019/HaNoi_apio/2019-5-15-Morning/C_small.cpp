#include<bits/stdc++.h>
#define int 		long long
using namespace std;

typedef pair<int, int> ii;

const int N = 1e5 + 4;
int n, org[N];
ii a[N];

vector<int> ans;
string str;

void Print(int num) {
	str = "0.";
	for (int i = 1; i < num; ++i) str += "0";
	str += "1";	
	cout << str << '\n';
}

string to_String(int val) {
	string ans = "";
	while (val > 0) ans += (char) ('0' + val%10), val /= 10;
	return ans;
}

void sol() {
	sort(a+1, a+n+1);

	int val = 1, cur = 0;
	for (int i = 1; i < n; ++i) {
		while (cur < a[i].first) { val *= 10; ++cur; }
		if (val == 0) { cout << "NO\n"; exit(0); }
		val--;
	}
	if (cur != a[n].first) { cout << "NO\n"; exit(0); }	
	if (val == 0) { cout << "NO\n"; exit(0); }

	string cc = to_String(val);
	while ((int) cc.length() < cur) cc += "0";
	reverse(cc.begin(), cc.end());

	bool foo = false;
	if (cc[cc.length()-1] == '0') { 
		val--; foo = true;
	}

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
			string cc = to_String(val);
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
		freopen("answer.txt", "w", stdout);
	}

	// int cc;
	// cin >> cc;
	// cout << cc-1 << '\n';
	// exit(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].first; a[i].second = i;
		org[i] = a[i].first;
		assert(org[i] > 0);
	}

	sol();

	return 0;
}