#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

long long dis(pair <int, int> a, pair <int, int> b) {
    return (long long)(a.first - b.first) * (a.first - b.first)
    + (long long)(a.second - b.second) * (a.second - b.second);
}

map <pair <int, int>, int> mp;
pair <int, int> a[N], p[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    long long d; int n, cnt = 0; cin >> n >> d;
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second; mp[a[i]]++;
    }
    if (n <= 1000) {
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)   
                if (dis(a[i], a[j]) == d * d)
                    res++;
        cout << res << '\n'; return 0; 
    }
    int lim = sqrt(1ll * d * d / 2);
    for (long long x = 0; x <= lim; x++) {
        long long y = sqrt(d * d - x * x);
        if (x * x + y * y == d * d) {
            p[cnt++] = {x, y}; p[cnt++] = {y, x};
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < cnt; j++) {
            if (p[j].first == 0) {
                res += mp[{a[i].first, a[i].second - p[j].second}];
                res += mp[{a[i].first, a[i].second + p[j].second}];
                continue;
            }
            if (p[j].second == 0) {
                res += mp[{a[i].first - p[j].first, a[i].second}];
                res += mp[{a[i].first + p[j].first, a[i].second}];
                continue;
            }
            res += mp[{a[i].first - p[j].first, a[i].second + p[j].second}];
            res += mp[{a[i].first + p[j].first, a[i].second + p[j].second}];
            res += mp[{a[i].first + p[j].first, a[i].second - p[j].second}];
            res += mp[{a[i].first - p[j].first, a[i].second - p[j].second}];
        }
    cout << res / 2 << '\n';
}