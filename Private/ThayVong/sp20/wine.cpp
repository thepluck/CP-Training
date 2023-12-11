#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair <int, int>;

int main() {
    freopen("wine.inp", "r", stdin);
    freopen("wine.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n, cnt = 0; cin >> n;
    long long s = 0;
    vector <ii> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        s += a[i].first;
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < n; i++) {
        if (a[i].first <= s)
            s -= a[i].first;
        else {
            a[i].first = s; s = 0;
        }
        if (!a[i].first) cnt++;
    }
    sort(a.begin(), a.end(),
    [](ii p, ii q) {
        return p.second < q.second;
    });
    cout << cnt << '\n';
    for (int i = 0; i < n; i++)
        cout << a[i].first << ' ';
}