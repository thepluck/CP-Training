#include <bits/stdc++.h>
using namespace std;
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector <int> a(n + 1), b(n + 1), cnt(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; cnt[a[i]]++;
    }
    if (n == 2) {
        cout << "-1\n"; return 0;
    }
    if (n == 3) {
        vector <int> p({0, 1, 2, 3});
        do {
            if (a[p[1]] != p[2] && a[p[2]] != p[3]) {
                cout << p[1] << ' ' << p[2] << ' ' << p[3] << '\n';
                return 0;
            }
        }
        while (next_permutation(p.begin() + 1, p.end()));
    }
    set <int> v;
    for (int i = 1; i <= n; i++) v.insert(i);
    for (int i = 1; i <= n - 4; i++) {
        auto it = v.begin();
        if (i > 1 && *it == a[b[i - 1]]) it++;
        int x = *it;
        if (cnt[a[x]] == n - i && v.count(a[x])) x = a[x];
        b[i] = x; v.erase(x); cnt[a[x]]--;
    }
    vector <int> p(v.begin(), v.end());
    p.insert(p.begin(), 0);
    do {
        if ((n <= 4 || a[b[n - 4]] != p[1]) && a[p[1]] != p[2]
        && a[p[2]] != p[3] && a[p[3]] != p[4]) {
            for (int i = 1; i <= n - 4; i++) cout << b[i] << ' ';
            cout << p[1] << ' ' << p[2] << ' ' << p[3] << ' ' << p[4] << '\n';
            return 0;
        }
    }
    while (next_permutation(p.begin() + 1, p.end()));
}