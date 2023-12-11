#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[N];

struct fenwick_tree{
    int tree[N], n;

    fenwick_tree(int n = 0): n(n){}

    void update(int i, int val){
        for (; i <= n; i += i & -i)
            tree[i] += val;
    }

    void update(int l, int r, int val){
        update(l, val);
        update(r + 1, -val);
    }

    int query(int i){
        int res = 0;
        for (; i > 0; i -= i & -i)
            res += tree[i];
        return res;
    }
} bit;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n; bit.n = n;
    for (int i = 1; i <= n; cin >> a[i++]);
    sort(a + 1, a + n + 1, greater <int> ());
    cin >> m; int x, lo, hi, mi, res;
    for (int i = 1; i <= m; i++){
        cin >> x;
        lo = 1, hi = n, res = 0;
        while (lo <= hi){
            mi = (lo + hi) / 2;
            if (a[mi] - bit.query(mi) >= x)
                res = mi, lo = mi + 1;
            else hi = mi - 1;
        }
        cout << res << '\n';
        bit.update(1, res, 1);
    }
}