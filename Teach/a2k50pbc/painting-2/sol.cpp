#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int a, b; cin >> a >> b;
    vector<pair<int, int>> v(a + b);
    for (int i = 0; i < a + b; i++)
        cin >> v[i].first;
    for (int i = 0; i < a + b; i++)
        cin >> v[i].second;
    sort(v.begin(), v.end(),
    [&](pair<int, int> x, pair<int, int> y) {
        return x.first - x.second > y.first - y.second;        
    });
    long long res = 0;
    for (int i = 0; i < a; i++)
        res += v[i].first;
    for (int i = b; i < a + b; i++)
        res += v[i].second;
    cout << res;
}
