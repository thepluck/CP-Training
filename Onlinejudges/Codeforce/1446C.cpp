// Problem: C. Xor Tree
// Contest: Codeforces - Codeforces Round #683 (Div. 1, by Meet IT)
// URL: https://codeforces.com/problemset/problem/1446/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

int rec(const vector <int> &a, int k) {
    if (a.size() == 1) return 1;
    vector <int> l, r;
    for (int x : a)
        if (x >> k & 1)
            r.push_back(x);
        else l.push_back(x);
    if (l.empty())
        return rec(r, k - 1);
    else if (r.empty())
        return rec(l, k - 1);
    return max(rec(l, k - 1),
    rec(r, k - 1)) + 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector <int> a(n);
    for (int &x : a) cin >> x;
    cout << n - rec(a, 30) << '\n';
}