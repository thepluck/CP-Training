#include <bits/stdc++.h>
using namespace std;

#define clz __builtin_clz

struct sparse_table{
    static const int N = 1e5 + 5;
    int spt[18][N];
    function <int(int, int)> opt;

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
        int k = 31 - clz(j - i + 1);
        return opt(spt[k][i],
        spt[k][j + 1 - (1 << k)]);
    }
};

int a[100005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, q; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sparse_table rmq(a, n,
    [](int x, int y){
        return min(x, y);
    });
    cin >> q; int l, r;
    while (q--){
        cin >> l >> r;
        cout << rmq.query(l, r) << '\n';
    }
}