
// Problem : String Similarity
// Contest : HackerRank - Algorithms - Strings
// URL : https://www.hackerrank.com/challenges/string-similarity/problem
// Memory Limit : 512 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

long long solve() {
    string s; cin >> s;
    int n(s.size()), l(0), r(0);
    vector <int> z(n);
    z[0] = n;
    for (int i = 1; i < n; i++)
        if (z[i - l] < r - i + 1)
            z[i] = z[i - l];
        else {
            r = max(r, i);
            while (s[r - i] == s[r]) r++;
            z[i] = r - i; r--; l = i;
        }
    return accumulate(z.begin(), z.end(), 0ll);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) cout << solve() << '\n';
}