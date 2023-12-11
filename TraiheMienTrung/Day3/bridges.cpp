#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define ub upper_bound

using ll = long long;

struct point{
    int x, y;

    point(int x = 0, int y = 0)
    : x(x), y(y){}
};

const int N = 2e5 + 5;
vector <point> pt;
ll sum[N], pre[N], suf[N];
int cnt[N], val[N];

void update(int i, int val){
    for (; i < N; i += i & -i){
        cnt[i]++; sum[i] += val;
    }
}

ll get_sum(int i){
    ll res = 0;
    for (; i > 0; i -= i & -i)
        res += sum[i];
    return res;
}

int get_cnt(int i){
    int res = 0;
    for (; i > 0; i -= i & -i)
        res += cnt[i];
    return res;
}

int kth(int k){
    int pos = 0, p = 1 << 17;
    for (; p; p >>= 1){
        pos += p;
        if (pos < N && k > cnt[pos])
            k -= cnt[pos];
        else pos -= p;
    }
    return pos + 1;
}

int main(){
    freopen("bridges.inp", "r", stdin);
    freopen("bridges.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, k; cin >> k >> n; ll res = 0;
    for (int i = 1; i <= n; i++){
        char p, q; int x, y;
        cin >> p >> x >> q >> y;
        if (p != q) pt.eb(x, y);
        else res += abs(x - y);
    }
    vector <int> pos; ll tmp = res;
    for (auto p : pt){
        pos.eb(p.x); pos.eb(p.y);
    }
    if (pos.empty()){
        cout << res << '\n'; return 0;
    }
    sort(pos.begin(), pos.end());
    int pp = pos[pos.size() / 2];
    for (int x : pos) res += abs(x - pp);
    if (k == 1){
        cout << res + pos.size() / 2 << '\n';
        return 0;
    }
    sort(pt.begin(), pt.end(),
    [](point a, point b){
        return a.x + a.y < b.x + b.y;
    });
    pos.resize(distance(pos.begin(),
    unique(pos.begin(), pos.end())));
    ll tot = 0;
    for (int i = 0; i < pt.size(); i++){
        int x = ub(pos.begin(), pos.end(),
                pt[i].x) - pos.begin();
        int y = ub(pos.begin(), pos.end(),
                pt[i].y) - pos.begin();
        update(x, pt[i].x);
        update(y, pt[i].y);
        val[x] = pt[i].x;
        val[y] = pt[i].y;
        tot += val[x] + val[y];
        int cur = kth(i + 1);
        int sma = get_cnt(cur - 1);
        ll ssma = get_sum(cur - 1);
        pre[i] = 1ll * sma * val[cur] - ssma * 2
        + tot - 1ll * (2 * (i + 1) - sma) * val[cur];
    }
    memset(sum, 0, sizeof sum);
    memset(cnt, 0, sizeof cnt);
    tot = 0;
    for (int i = pt.size() - 1; ~i; i--){
        int x = ub(pos.begin(), pos.end(),
                pt[i].x) - pos.begin();
        int y = ub(pos.begin(), pos.end(),
                pt[i].y) - pos.begin();
        update(x, pt[i].x);
        update(y, pt[i].y);
        tot += val[x] + val[y];
        int cur = kth(pt.size() - i);
        int sma = get_cnt(cur - 1);
        ll ssma = get_sum(cur - 1);
        suf[i] = 1ll * sma * val[cur] - ssma * 2
        + tot - 1ll * (2 * (pt.size() - i)
        - sma) * val[cur];
    }
    for (int i = 0; i < pt.size(); i++)
        res = min(res, pre[i] + suf[i + 1] + tmp);
    cout << res + pt.size() << '\n';
}