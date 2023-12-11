
#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()
#define lb lower_bound
#define ub upper_bound
const int N = 3e4 + 5;
vector <int> seg[N << 2];
int lo[N << 2], hi[N << 2], a[N];

void build(int i, int l, int r){
    lo[i] = l; hi[i] = r;
    if (l == r){
        seg[i].push_back(a[l]); return;
    }
    int m = (l + r) >> 1; 
    build(i << 1, l, m); build(i << 1 | 1, m + 1, r);
    merge(all(seg[i << 1]), all(seg[i << 1 | 1]), back_inserter(seg[i]));
}

int query(int i, int l, int r, int k){
    if (lo[i] > r || hi[i] < l) return 0;
    if (lo[i] >= l && hi[i] <= r)
        return seg[i].size() - (ub(all(seg[i]), k) - seg[i].begin());
    else return query(i << 1, l, r, k) + query(i << 1 | 1, l, r, k);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, q; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n); cin >> q; int l, r, k;
    while (q--){
        cin >> l >> r >> k;
        cout << query(1, l, r, k) << '\n';
    }
}