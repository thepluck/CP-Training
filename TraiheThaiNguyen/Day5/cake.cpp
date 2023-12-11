/*#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e5 + 5;
ll t[4][N * 4], a[4][N];
int lo[N * 4], hi[N * 4];
ll ans[4], tmp[4];

void build(int i, int l, int r){
    lo[i] = l; hi[i] = r;
    if (l == r){
        t[0][i] = a[0][l];
        t[1][i] = a[1][l];
        t[2][i] = a[2][l];
        t[3][i] = -1e9;
        return;
    }
    int m = (l + r) / 2;
    int ls = i * 2, rs = i * 2 + 1;
    build(ls, l, m);
    build(rs, m + 1, r);
    t[0][i] = max(t[0][ls] + t[0][rs],
                t[2][ls] + t[1][rs]);
    t[1][i] = max(t[1][ls] + t[0][rs],
                t[3][ls] + t[1][rs]);
    t[2][i] = max(t[0][ls] + t[2][rs],
                t[2][ls] + t[3][rs]);
    t[3][i] = max(t[1][ls] + t[2][rs],
                t[3][ls] + t[3][rs]);
}

void query(int i, int l, int r){
    if (lo[i] > r || hi[i] < l) return;
    if (lo[i] >= l && hi[i] <= r){
        tmp[0] = ans[0];
        tmp[1] = ans[1];
        tmp[2] = ans[2];
        tmp[3] = ans[3];
        ans[0] = max(tmp[0] + t[0][i],
                tmp[2] + t[1][i]);
        ans[1] = max(tmp[1] + t[0][i],
                tmp[3] + t[1][i]);
        ans[2] = max(tmp[0] + t[2][i],
                tmp[2] + t[3][i]);
        ans[3] = max(tmp[1] + t[2][i],
                tmp[3] + t[3][i]);
        return;
    }
    query(i * 2, l, r);
    query(i * 2 + 1, l, r);
}

int main(){
    //freopen("cake.inp", "r", stdin);
    //freopen("cake.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[1][i];
        cin >> a[0][i] >> a[2][i];
    }
    a[1][1] = -1e9; a[2][n] = -1e9;
    build(1, 1, n);
    int q, l, r; cin >> q;
    while (q--){
        cin >> l >> r;
        memset(ans, 0, sizeof ans);
        ans[3] = -1e9;
        query(1, l, r);
        cout << ans[0] << '\n';
    }
}*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct info{
    long long s[4];

    info(){
        memset(s, 0, sizeof s);
        s[3] = -1e9;
    }

    ll& operator [] (const int &x){
        return s[x];
    }
};

template <class T>
struct sparse_table{
    static const int N = 1e5 + 5;
    vector <T> spt[18];
    function <T (T, T)> opt;

    sparse_table(){}

    sparse_table(T a[], int n,
    function <T (T, T)> opt){
        this->opt = opt;
        for (int k = 0; k < 18; k++)
            spt[k].resize(n + 1);
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

    T query(int i, int j){
        T res;
        for (int k = 17; ~k; k--)
            if (i + (1 << k) <= j + 1){
                res = opt(res, spt[k][i]);
                i += 1 << k;
            }
        return res;
    }
};

info a[100005];

int main(){
    //freopen("cake.inp", "r", stdin);
    //freopen("cake.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i][1] >> a[i][0];
        cin >> a[i][2];
    }
    a[1][1] = -1e9; a[n][2] = -1e9;
    sparse_table <info> rmq(a, n,
    [](info l, info r){
        info res;
        res[0] = max(l[0] + r[0],
                    l[2] + r[1]);
        res[1] = max(l[1] + r[0],
                    l[3] + r[1]);
        res[2] = max(l[0] + r[2],
                    l[2] + r[3]);
        res[3] = max(l[1] + r[2],
                    l[3] + r[3]);
        return res;
    });
    int q, l, r; cin >> q;
    while (q--){
        cin >> l >> r;
        cout << rmq.query(l, r)[0] << '\n';
    }
}