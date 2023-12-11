#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; string s;
        cin >> n >> s;
        reverse(s.begin(), s.end());
        vector<int> z(n);
    	for (int i = 1, x = 0, y = 0; i < n; i++) {
    		z[i] = max(0, min(z[i - x], y - i + 1));
    		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
    			x = i; y = i + z[i]; z[i]++;
    	    }
    	}
    	cout << accumulate(z.begin(), z.end(), 1ll * n) << '\n';
    }
}