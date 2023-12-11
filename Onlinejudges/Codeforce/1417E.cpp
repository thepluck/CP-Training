
// Problem : E. XOR Inverse
// Contest : Codeforces - Codeforces Round #673 (Div. 2)
// URL : https://codeforces.com/contest/1417/problem/E
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

int a[N]; long long ans[2][31];

void rec(int b, const vector <int> &id) {
    if (id.size() <= 1 || b == -1) return;
    int cnt = 0;
    vector <int> le, ri;
    for (int i : id)
        if (a[i] >> b & 1) cnt++;
        else ans[0][b] += cnt;
    cnt = 0;
    for (int i : id)
        if (a[i] >> b & 1) {
            ans[1][b] += cnt;
            le.push_back(i);
        }
        else {
            cnt++;
            ri.push_back(i);
        }
    rec(b - 1, le); rec(b - 1, ri);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector <int> id;
    for (int i = 1; i <= n; i++)
        id.push_back(i);
    rec(30, id);
    int x = 0; long long res = 0;
    for (int i = 30; ~i; i--)
        if (ans[0][i] <= ans[1][i])
            res += ans[0][i];
        else {
            x += 1 << i;
            res += ans[1][i];
        }
    cout << res << ' ' << x << '\n';
}