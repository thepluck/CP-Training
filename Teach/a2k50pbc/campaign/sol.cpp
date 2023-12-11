#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<pair<int, int>> c(n), a, b;
    for (auto &p : c) cin >> p.first;
    for (auto &p : c) {
        cin >> p.second;
        if (p.first < p.second)
            a.push_back(p);
        else b.push_back(p);
    }
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    long long cur = 0, res = 0;
    for (auto p : a) {
        cur += p.first;
        cerr<<cur<<'\n';
        res = max(res, cur);
        cur -= p.second;
    }
    for (auto p : b) {
        cur += p.first;
        res = max(res, cur);
        cur -= p.second;
    }
    cout << res;
}
