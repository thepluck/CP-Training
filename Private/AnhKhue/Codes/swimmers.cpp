#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

const int N = 55;

int p[N], c[N];
deque <pair <int, int>> dq[2];

int main() {
    freopen("swimmers.in", "r", stdin);
    freopen("swimmers.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector <int> rev;
    auto cmp = [&](int i, int j) {
        return p[i] < p[j];
    };
    for (int i = 1; i <= n; i++) {
        cin >> p[i] >> c[i]; c[i] *= 2;
        rev.emplace_back(i);
    }
    sort(rev.begin(), rev.end(), cmp);
    for (int i : rev)
        dq[0].emplace_back(p[i], i);
    int res = 0;
    while (dq[0].size() || dq[1].size()) {
        int id;
        if (!dq[0].size()) id = 1;
        else if (!dq[1].size()) id = 0;
        else if (dq[0].front().fi < dq[1].front().fi) id = 0;
        else id = 1;
        int tim = dq[id].front().fi;
        rev.clear(); res += tim;
        while (dq[id].size() && dq[id].front().fi <= tim) {
            c[dq[id].front().se]--;
            if (c[dq[id].front().se])
                rev.emplace_back(dq[id].front().se);
            dq[id].pop_front();
        }
        sort(rev.begin(), rev.end(), cmp);
        for (auto &pp : dq[0]) pp.fi -= tim;
        for (auto &pp : dq[1]) pp.fi -= tim;
        for (int i : rev)
            dq[1 - id].emplace_back(p[i], i);
    }
    cout << res << '\n';
}
