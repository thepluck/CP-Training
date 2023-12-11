#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s1, s2, s;
	cin >> s1 >> s2;
	s = s2 + '.' + s1;
	int n = s.size();
	vector <int> z(n);
	z[0] = n; int l(0), r(0);
	for (int i = 1; i < n; i++){
		if (z[i - l] < r - i + 1) z[i] = z[i - l];
		else {
			r = max(r, i);
			while (s[r - i] == s[r]) r++;
			z[i] = r - i; r--; l = i;
		}
	}
	for (int i = s2.size(); i < n; i++)
		if (z[i] == n - i){
			cout << s1.substr(0, s1.size() - z[i]) + s2;
			return 0;
		}
	cout << s1 << s2;
	return 0;
}