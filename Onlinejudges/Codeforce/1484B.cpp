#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector <long long> a(n);
        long long m = 0;
        for (long long &x : a) cin >> x;
        for (long long i = 1; i + 1 < n; i++)
            m = __gcd(m, abs(a[i + 1] + a[i - 1] - 2 * a[i]));
        if (m == 0) cout << "0\n";
        else if (m <= *max_element(a.begin(), a.end())) cout << "-1\n";
        else cout << m << ' ' << (a[1] - a[0] + m) % m << '\n';
    }
}