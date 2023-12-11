#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector <int> a(n), s;
        for (int &x : a) cin >> x;
        vector <char> v(n);
        int u = 0;
        while (!v[u]) {
            v[u] = 1; u -= a[u];
        }
        fill(v.begin(), v.end(), 0);
        while (!v[u]) {
            s.push_back(u);
            v[u] = 1; u -= a[u];
        }
        cout << s.size() << '\n';
        for (int x : s)
            cout << x + 1 << ' ';
        cout << '\n';
    }
}