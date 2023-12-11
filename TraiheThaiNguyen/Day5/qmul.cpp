#include <bits/stdc++.h>
using namespace std;

#define clz __builtin_clz

const int MOD = 1e9 + 7;

struct sparse_table{
    static const int N = 1e5 + 5;
    int spt[18][N], lg[N], pw[N];
    function <int (int, int)> opt;

    sparse_table(){}

    sparse_table(int a[], int n,
    function <int (int, int)> opt){
        this->opt = opt;
        for (int i = 1; i <= n; i++)
            spt[0][i] = a[i];
        for (int k = 1, p = 1;
        k <= 17; k++, p <<= 1)
            for (int i = 1; i +
            (p << 1) <= n + 1; i++)
                spt[k][i] =
                opt(spt[k - 1][i],
                spt[k - 1][i + p]);
    }

    int query(int i, int j){
        long long res = 1;
        for (int k = 17; ~k; k--)
            if (i + (1 << k) <= j + 1){
                res = opt(res, spt[k][i]);
                i += 1 << k;
            }
        return res;
    }
};

int a[100005];

int main(){
    freopen("qmul.inp", "r", stdin);
    freopen("qmul.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, q; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sparse_table rmq(a, n,
    [](int x, int y){
        return 1ll * x * y % MOD;
    });
    cin >> q; int l, r;
    while (q--){
        cin >> l >> r;
        cout << rmq.query(l, r) << '\n';
    }
}