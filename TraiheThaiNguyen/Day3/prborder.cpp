#include <bits/stdc++.h>
using namespace std;

#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define eb emplace_back

using ii = pair <int, int>;

const int N = 1e6 + 5;
vector <int> x[N], y[N];
vector <array <ii, 2>> rec;
map <ii, int> mp;

int range(int i, int j, const vector <int> &v){
    return lb(v.begin(), v.end(), j) - ub(v.begin(), v.end(), i);
}

int main(){
    freopen("prborder.inp", "r", stdin);
    freopen("prborder.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m; cin >> n;
    vector <int> cmp;
    vector <ii> pt; pt.resize(n);
    for (int i = 0; i < n; i++){
        cin >> pt[i].fi >> pt[i].se;
        cmp.eb(pt[i].fi);
        cmp.eb(pt[i].se);
    }
    cin >> m; rec.resize(m);
    for (int i = 0; i < m; i++){
        cin >> rec[i][0].fi >> rec[i][0].se;
        cin >> rec[i][1].fi >> rec[i][1].se;
        cmp.eb(rec[i][0].fi);
        cmp.eb(rec[i][0].se);
        cmp.eb(rec[i][1].fi);
        cmp.eb(rec[i][1].se);
    }
    sort(cmp.begin(), cmp.end());
    cmp.resize(distance(cmp.begin(),
    unique(cmp.begin(), cmp.end())));
    for (int i = 0; i < n; i++){
        pt[i].fi = ub(cmp.begin(),
        cmp.end(), pt[i].fi) - cmp.begin();
        pt[i].se = ub(cmp.begin(),
        cmp.end(), pt[i].se) - cmp.begin();
        x[pt[i].fi].eb(pt[i].se);
        y[pt[i].se].eb(pt[i].fi);
        mp[pt[i]]++;
    }
    for (int i = 0; i < N; i++){
        sort(x[i].begin(), x[i].end());
        sort(y[i].begin(), y[i].end());
    }
    for (int i = 0; i < m; i++){
        for (int j = 0; j < 2; j++){
            rec[i][j].fi = ub(cmp.begin(),
            cmp.end(), rec[i][j].fi) - cmp.begin();
            rec[i][j].se = ub(cmp.begin(),
            cmp.end(), rec[i][j].se) - cmp.begin();
        }
        int res = 0;
        res += mp[rec[i][0]] + mp[rec[i][1]];
        res += mp[ii(rec[i][0].fi, rec[i][1].se)];
        res += mp[ii(rec[i][1].fi, rec[i][0].se)];
        res += range(rec[i][0].fi, rec[i][1].fi, x[rec[i][0].se]);
        res += range(rec[i][0].fi, rec[i][1].fi, x[rec[i][1].se]);
        res += range(rec[i][0].se, rec[i][1].se, y[rec[i][0].fi]);
        res += range(rec[i][0].se, rec[i][1].se, y[rec[i][1].fi]);
        cout << res << '\n';
    }
}