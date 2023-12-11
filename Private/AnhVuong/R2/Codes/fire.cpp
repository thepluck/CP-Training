#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct query {int l, r, id;};

struct triangle {int x, l; ll v;};

const int N = 200005;

vector <triangle> tri[N];
ll BIT[6][N], ans[N]; vector <query> que[N];
int a[N], l[N], r[N], n, q; ll sum[N];

void updBIT(int id, int pos, ll val) {
    for (pos++; pos < N; pos += pos & -pos)
        BIT[id][pos] += val;
}

ll getBIT(int id, int pos) {
    if (pos < 0) return 0;
    ll res = 0;
    for (pos++; pos > 0; pos -= pos & -pos)
        res += BIT[id][pos];
    return res;
}

void updTri(int x, int l, ll v) {
    updBIT(0, x, v); updBIT(1, x, v * l);
    updBIT(2, x, v * (x - l));
    updBIT(3, x - l, v);
    updBIT(4, x - l, v * (x - l));
}

ll getTri(int x, int t) {
    if (x == 0) return 0;
    ll res = getBIT(1, x) - getBIT(0, x) * (t - 1);
    res -= getBIT(0, x) * (x - t + 1) - getBIT(2, x);
    res += getBIT(3, x - t) * (x - t + 1) - getBIT(4, x - t);
    return res;
}

void prepare() {
    vector <int> st; st.push_back(0); int mx = 0;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, a[i]); sum[i] = sum[i - 1] + mx;
        while (st.size() > 1 && a[st.back()] <= a[i])
            st.pop_back();
        l[i] = st.back() + 1; st.push_back(i);
    }
    st.clear(); st.push_back(n + 1);
    for (int i = n; i > 0; i--) {
        while (st.size() > 1 && a[st.back()] < a[i])
            st.pop_back();
        r[i] = st.back() - 1; st.push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        tri[r[i] - l[i] + 2].
        push_back({r[i], r[i] - l[i] + 1, -a[i]});
        updTri(r[i], r[i] - l[i] + 1, a[i]);
        if (r[i] > i) {
            tri[r[i] - i + 1].
            push_back({r[i], r[i] - i, a[i]});
            updTri(r[i], r[i] - i, -a[i]);
        }
        if (i > l[i]) {
            tri[i - l[i] + 1].
            push_back({i - 1, i - l[i], a[i]});
            updTri(i - 1, i - l[i], -a[i]);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    prepare();
    for (int i = 1; i <= q; i++) {
        int t, l, r; cin >> t >> l >> r;
        if (r <= t) {
            ans[i] = sum[r] - sum[l - 1]; continue;
        }
        que[t + 1].push_back({max(l, t + 1), r, i});
        if (l <= t) ans[i] = sum[t] - sum[l - 1];
    }
    for (int i = 1; i <= n + 1; i++) {
        for (auto tr : tri[i])
            updTri(tr.x, tr.l, tr.v);
        for (auto qq : que[i])
            ans[qq.id] += getTri(qq.r, i)
            - getTri(qq.l - 1, i);
    }
    for (int i = 1; i <= q; i++)
        cout << ans[i] << '\n';
}   