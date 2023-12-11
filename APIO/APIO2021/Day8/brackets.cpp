#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

char s[N]; int d[N], n, p;

int main() {
    freopen("brackets.inp", "r", stdin);
    freopen("brackets.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> (s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; i++)
		d[i] = d[i - 1] +
		(s[i] == '(' ? 1 : -1);
	long long res = n + 1;
	for (int i = n; i > 0; i--) {
		if (!d[i]) p = i; res += p;
	}
	cout << res << '\n';
}