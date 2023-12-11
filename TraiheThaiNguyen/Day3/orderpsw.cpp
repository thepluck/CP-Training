#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define ub upper_bound
#define lb lower_bound
#define eb emplace_back

using ll = long long;

const int N = 3e5 + 5;
const int mod = 1e9 + 7;
int perm[N], lo[4 * N], hi[4 * N];
vector <int> st[4 * N]; ll fac[N];

void build(int i, int l, int r){
    lo[i] = l; hi[i] = r;
    if (l == r){
        st[i].push_back(perm[l]); return;
    }
    int m = (l + r) / 2;
    build(i * 2, l, m);
    build(i * 2 + 1, m + 1, r);
    merge(st[i * 2].begin(), st[i * 2].end(),
    st[i * 2 + 1].begin(), st[i * 2 + 1].end(),
    back_inserter(st[i]));
}

int query(int i, int l, int r, int v){
    if (lo[i] > r || hi[i] < l || l > r) return 0;
    if (lo[i] >= l && hi[i] <= r)
        return lb(st[i].begin(), st[i].end(), v)
        - st[i].begin();
    return query(i * 2, l, r, v) +
            query(i * 2 + 1, l, r, v);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("orderpsw.inp", "r", stdin);
    freopen("orderpsw.out", "w", stdout);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> perm[i];
    ll tot = 0; build(1, 1, n);
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % mod;
    for (int i = 1; i <= n; i++){
        tot += fac[n - i] *
        query(1, i + 1, n, perm[i]) % mod;
        tot %= mod;
    }
    cout << tot << '\n';
    while (q--){
        int i, j; cin >> i >> j;
        ll res = tot;
        //cout << (res + 1 + mod) % mod << '\n';
    }
}