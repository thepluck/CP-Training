/// https://vjudge.net/contest/425052
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 100005;
const ll INF = 0xc0c0c0c0c0c0c0c0;

ll pos[N], str[N], BIT[2][N];

void upd0(int i, ll v) {
    for (; i < N; i += i & -i)
        BIT[0][i] = max(BIT[0][i], v);
}

void upd1(int i, ll v) {
    for (; i > 0; i -= i & -i)
        BIT[1][i] = max(BIT[1][i], v);
}

ll get0(int i) {
    ll res = INF;
    for (; i > 0; i -= i & -i)
        res = max(res, BIT[0][i]);
    return res;
}

ll get1(int i) {
    ll res = INF;
    for (; i < N; i += i & -i)
        res = max(res, BIT[1][i]);
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll k, m, d, a; int n;
    cin >> k >> m >> d >> a >> n;
    vector <int> mods(1, k % d);
    for (int i = 0; i < n; i++) {
        cin >> pos[i] >> str[i];
        mods.push_back(pos[i] % d);
    }
    sort(mods.begin(), mods.end());
    mods.erase(unique(mods.begin(),
    mods.end()), mods.end());
    int id = upper_bound(mods.begin(),
    mods.end(), k % d) - mods.begin();
    memset(BIT, 0xc0, sizeof BIT);
    upd0(id, k / d * a); upd1(id, k / d * a);
    for (int i = 0; i < n; i++) {
        id = upper_bound(mods.begin(),
        mods.end(), pos[i] % d) - mods.begin();
        ll cur = max(get1(id), get0(id) - a);
        cur -= pos[i] / d * a - str[i];
        upd0(id, cur + pos[i] / d * a);
        upd1(id, cur + pos[i] / d * a);
    }
    id = upper_bound(mods.begin(),
    mods.end(), m % d) - mods.begin();
    cout << max(get1(id),
    get0(id) - a) - m / d * a;
}