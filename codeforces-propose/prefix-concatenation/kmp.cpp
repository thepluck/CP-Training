#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; string s;
        cin >> n >> s;
        reverse(s.begin(), s.end());
        vector<int> kmp(n), dep(n, 1);
        long long res = 0;
        for (int i = 1, j = 0; i < n; i++) {
            while (j > 0 && s[i] != s[j]) j = kmp[j - 1];
            if (s[i] == s[j]) j++; kmp[i] = j;
            if (j > 0) dep[i] += dep[j - 1];
        }
        cout << accumulate(dep.begin(), dep.end(), 0ll) << '\n';
    }
}