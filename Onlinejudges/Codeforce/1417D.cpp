
// Problem : D. Make Them Equal
// Contest : Codeforces - Codeforces Round #673 (Div. 2)
// URL : https://codeforces.com/contest/1417/problem/D
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

struct ope {
    int i, j, x;
};

const int N = 1e4 + 5;

int a[N]; vector <ope> ans;

void op(int i, int j, int x) {
    a[i] -= x * i; a[j] += x * i;
    ans.push_back({i, j, x});
}

void solve() {
    int n, sum = 0;
    cin >> n; ans.clear();
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; sum += a[i];
    }
    if (sum % n) {
        cout << "-1\n"; return;
    }
    for (int i = 2; i <= n; i++) {
        if (a[i] % i)
            op(1, i, i - a[i] % i);
        op(i, 1, a[i] / i);
    }
    for (int i = 2; i <= n; i++)
        op(1, i, sum / n);
    cout << ans.size() << '\n';
    for (ope q : ans)
        cout << q.i << ' ' << q.j
        << ' ' << q.x << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
}