#include <bits/stdc++.h>
using namespace std;

string s; int n;
vector <int> p;

void rec(int l, int r) {
	if (l > r) return;
	if (s[l] == s[r]) {
		cout << '(';
		rec(l + 1, r - 1);
		cout << ')';
		return;
	}
	int m = p[r];
	while (s[m - 1] != s[l])
		m =	p[m - 1];
	cout << '(';
	rec(l + 1, m - 2);
	cout << ')';
	rec(m, r);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> s; n = s.size();
	for (int i = 0; i < n; i++) {
		if (!p.empty() && s[p.back()] == s[i])
			p.pop_back();
		else p.push_back(i);
	}
	if (p.size()) {
		cout << "-1\n"; return 0;
	}
	p.assign(n, -1);
	for (int i = 1; i < n; i++) {
		p[i] = i - 1;
		while (p[i] >= 0 && s[p[i]] != s[i])
			p[i] = p[p[i]] - 1;
	}
	rec(0, n - 1);
}