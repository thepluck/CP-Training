#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define clz __builtin_clz

using ii = pair <int, int>;

const int N = 1e5 + 5;
int a[N]; ii spt[18][N];

template <class T>
struct sparse_table{
    function <T (T, T)> opt;
    function <T (int)> cre;

    sparse_table(){}

    sparse_table(int n,
    function <T (int)> cre,
    function <T (T, T)> opt):
    opt(opt), cre(cre){
        for (int i = 1; i <= n; i++)
            spt[0][i] = cre(a[i]);
        for (int k = 1, p = 1;
        k <= 17; k++, p <<= 1)
            for (int i = 1; i +
            (p << 1) <= n + 1; i++)
                spt[k][i] =
                opt(spt[k - 1][i],
                spt[k - 1][i + p]);
    }

    T query(int i, int j){
        int k = 31 - clz(j - i + 1);
        return opt(spt[k][i],
        spt[k][j + 1 - (1 << k)]);
    }
};

int main(){
    freopen("qmin2.inp", "r", stdin);
    freopen("qmin2.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sparse_table <ii> rmq(n,
    [](int x){return ii(x, INT_MAX);},
    [](ii x, ii y){
        if (x.fi == y.fi)
            return ii(x.fi, min(x.se, y.se));
        if (x.fi < y.fi)
            return ii(x.fi, min(x.se, y.fi));
        return ii(y.fi, min(y.se, x.fi));
    });
    int q, l, r; cin >> q;
    while (q--){
        cin >> l >> r;
        cout << rmq.query(l, r).se << '\n';
    }
}