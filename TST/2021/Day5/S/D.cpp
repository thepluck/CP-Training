#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmax(X &a, const Y &b) {
    return a < b ? a = b, 1 : 0;
}

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

const int N = 505;

int main() {
    freopen("bet.inp", "r", stdin);
    freopen("bet.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n >> n;
    vector <pair <int, int>> bet[3];
    int sumab[] = {0, 0, 0};
    for (int i = 0; i < n; i++) {
        char r; int a, b;
        cin >> r >> a >> b;
        if (r == 'W') {
            bet[0].emplace_back(a, b);
            sumab[0] += a + b;
        }
        else if (r == 'L') {
            bet[1].emplace_back(a, b);
            sumab[1] += a + b;
        }
        else {
            bet[2].emplace_back(a, b);
            sumab[2] += a + b;
        }
    }
    /// Fix the minimum -> Formular
    vector <int> Max[3], Min[3];
    for (int id = 0; id < 3; id++) {
        Max[id].resize(sumab[id] + 1, -1e9);
        Min[id].resize(sumab[id] + 1, 1e9);
        Max[id][0] = Min[id][0] = 0;
        int curab = 0;
        for (auto pp : bet[id]) {
            int a, b; tie(a, b) = pp;
            for (int sum = curab; sum >= 0; sum--) {
                cmax(Max[id][sum + a + b], Max[id][sum] + b);
                cmin(Min[id][sum + a + b], Min[id][sum] + a);
            }
            curab += a + b;
        }
    }
    int res = 0;
    for (int id = 0; id < 3; id++) {
        int lid = (id + 1) % 3;
        int rid = (id + 2) % 3;
        int maxl = 0, maxr = 0;
        for (int sum = 0; sum <= sumab[id]; sum++) {
            if (sum <= sumab[lid])
                maxl = max(maxl, Max[lid][sum]);
            if (sum <= sumab[rid])
                maxr = max(maxr, Max[rid][sum]);
            res = max(res, maxl + maxr - Min[id][sum]);
        }
    }
    cout << res << '\n';
}