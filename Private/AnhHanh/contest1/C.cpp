#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define ub upper_bound
#define lb lower_bound

using ll = long long;

const int N = 2e5 + 5;
const int L = 55;

struct student {
    int x, r, t;
};

ll ans[N][55]; int BIT[N];
vector <student> grp[N];
student lst[N]; int siz;

void update(int i) {
    for (; i <= siz; i += i & -i) BIT[i]++;
}

int query(int i) {
    int res = 0;
    for (; i > 0; i -= i & -i) res += BIT[i];
    return res;
}

ll count1(const vector <student> &grp) {
    vector <int> val; ll res = 0;
    for (auto st : grp) val.push_back(st.x);
    sort(all(val));
    val.erase(unique(all(val)), val.end());
    for (int i = 1; i <= val.size(); i++) BIT[i] = 0;
    siz = val.size();
    for (auto st : grp) {
        res += query(ub(all(val), st.x + st.r) - val.begin());
        res -= query(lb(all(val), st.x - st.r) - val.begin());
        update(ub(all(val), st.x) - val.begin());
    }
    return res;
}

ll count2(const vector <student> &grpa,
const vector <student> &grpb, bool needEq) {
    vector <int> val; ll res = 0;
    for (auto st : grpa) val.push_back(st.x);
    sort(all(val));
    val.erase(unique(all(val)), val.end());
    for (int i = 1; i <= val.size(); i++) BIT[i] = 0;
    siz = val.size(); int ptr = 0;
    for (auto st : grpb) {
        while (ptr < grpa.size() && (grpa[ptr].r > st.r
        || (needEq && grpa[ptr].r == st.r)))
            update(ub(all(val), grpa[ptr++].x) - val.begin());
        res += query(ub(all(val), st.x + st.r) - val.begin());
        res -= query(lb(all(val), st.x - st.r) - val.begin());
    }
    return res;
}

int main() {
    freopen("lovesharing.inp", "r", stdin);
    freopen("lovesharing.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> n >> q;
    vector <int> val;
    for (int i = 1; i <= n; i++) {
        cin >> lst[i].x >> lst[i].r >> lst[i].t;
        val.push_back(lst[i].t);
    }
    sort(all(val));
    val.erase(unique(all(val)), val.end());
    for (int i = 1; i <= n; i++)
        grp[lb(all(val),
        lst[i].t) - val.begin()].push_back(lst[i]);
    for (int i = 0; i < val.size(); i++)
        sort(grp[i].begin(), grp[i].end(),
        [](const student &a, const student &b) {
            return a.r > b.r;
        });
    for (int i = 0; i < val.size(); i++) {
        ans[i][0] = count1(grp[i]);
        for (int j = i + 1; j < val.size(); j++)
            if (val[j] - val[i] <= 50)
                ans[i][j - i] = count2(grp[i], grp[j], 1)
                + count2(grp[j], grp[i], 0);
            else break;
        for (int j = 1; j <= 50; j++)
            ans[i][j] += ans[i][j - 1];
    }
    while (q--) {
        int l, r; cin >> l >> r;
        l = lb(all(val), l) - val.begin();
        r = ub(all(val), r) - val.begin();
        ll res = 0;
        for (int i = l; i < r; i++)
            res += ans[i][r - i - 1];
        cout << res << ' ';
    }
}