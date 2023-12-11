//https://codeforces.com/gym/102576/problem/G
#include <bits/stdc++.h>
using namespace std;

int sqr(int x) {
    return x * x;
}

double dis(const pair <int, int> &a,
const pair <int, int> &b) {
    return sqrt(sqr(a.first - b.first)
    + sqr(a.second - b.second));
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        double res = DBL_MAX;
        vector <int> p, x;
        vector <pair <int, int>> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first >> a[i].second;
            p.push_back(i);
        }
        for (int i = 0; i < n; i++)
            cin >> b[i].first >> b[i].second;
        do {
            double tot = 0;
            for (int i = 0; i < n; i++)
                tot += dis(a[i], b[p[i]]);
            if (tot < res) {
                res = tot; x = p;
            }
        }
        while (next_permutation(p.begin(), p.end()));
        for (int i = 0; i < n; i++) {
            cout << 2 << '\n';
            cout << a[i].first << ' ' << a[i].second << '\n';
            cout << b[x[i]].first << ' ' << b[x[i]].second << '\n';
        }
    }
}