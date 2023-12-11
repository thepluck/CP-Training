#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n; cin >> n;
	set <string> s;
	string x; char a[20];
	memset(a, 0, sizeof a);
	for (int i = 0; i < n; i++){
		cin >> x; s.insert(x);
		for (int j = 0; x[j]; j++) a[j] ^= x[j];
	}
	string ans; int i = 0;
	while (a[i] != 0){
		ans += a[i]; i++;
	}
	if (s.find(ans) != s.end()) cout << ans;
	else cout << -1;
	return 0;
}