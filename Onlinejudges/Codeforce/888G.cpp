#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()
using ll = long long;
const ll inf = 1 << 30;
ll a[200005]; int nxt[31][200005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (ll &x : a) cin >> x; sort(a, a + n);
    n = unique(a, a + n) - a;
    for (int p = 0; p <= 30; p++)
        for (int i = 0, j = 0; i < n; i++){
            j = max(j, i);
            while (j < n && !(a[j] >> p & 1)) j++;
            nxt[p][i] = j;
        }
    function <ll(int, int, int, int, int)> f =
    [&](int p, int l1, int r1, int l2, int r2){
        if (l1 >= r1 || l2 >= r2) return inf;
        if (p < 0) return 0ll;
        int m1 = min(nxt[p][l1], r1);
        int m2 = min(nxt[p][l2], r2);
        if ((l1 < m1 && l2 < m2) || (m1 < r1 && m2 < r2))
            return min(f(p - 1, l1, m1, l2, m2),
                    f(p - 1, m1, r1, m2, r2));
        else return min(f(p - 1, l1, m1, m2, r2),
                    f(p - 1, m1, r1, l2, m2)) + (1 << p);
    };
    function <ll(int, int, int)> g =
    [&](int p, int l, int r){
        if (p < 0 || r - l <= 1) return 0ll;
        if (r - l == 2) return a[l] ^ a[l + 1];
        int m = min(nxt[p][l], r);
        ll res = g(p - 1, l, m) + g(p - 1, m, r);
        if (l < m && m < r)
            res += f(p - 1, l, m, m, r) + (1 << p);
        return res;
    };
    cout << g(30, 0, n) << '\n';
}