#include <bits/stdc++.h>
using namespace std;

#define pb push_back

template <class X, class Y>
bool chkmax(X &a, const Y &b){
    return a < b ? a = b, 1 : 0;
}

struct gauss{
    int basis[21];

    void insert(int x){
        for (int i = 20; ~i; i--){
            if (!(x >> i & 1)) continue;
            if (!basis[i]) basis[i] = x;
            x ^= basis[i];
        }
    }

    int get_max(){
        int x = 0;
        for (int i = 20; ~i; i--)
            chkmax(x, x ^ basis[i]);
        return x;
    }
    
    void clear(){
        memset(basis, 0, sizeof basis);
    }
};

gauss merge(const gauss &a,
            const gauss &b){
    gauss res = a;
    for (int i = 20; ~i; i--)
        res.insert(b.basis[i]);
    return res;
}

struct query{
    int l, r, id;
};

const int N = 5e5 + 5;
int a[N], ans[N]; gauss cur[N];

void solve(int l, int r,
        const vector <query> &que){
    int m = (l + r) / 2; cur[m].clear();
    for (int i = m - 1; i >= l; i--){
        cur[i] = cur[i + 1];
        cur[i].insert(a[i]);
    }
    for (int i = m; i <= r; i++){
        cur[i].insert(a[i]);
        cur[i + 1] = cur[i];
    }
    vector <query> lque, rque;
    for (const query &q : que)
        if (q.r < m) lque.pb(q);
        else if (q.l > m) rque.pb(q);
        else ans[q.id] = merge(cur[q.l],
                    cur[q.r]).get_max();
    if (l < m) solve(l, m - 1, lque);
    if (m < r) solve(m + 1, r, rque);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, q; cin >> n;
    for (int i = 1; i <= n; cin >> a[i++]);
    cin >> q; vector <query> que;
    for (int i = 1, l, r; i <= q; i++){
        cin >> l >> r; que.pb({l, r, i});
    }
    solve(1, n, que);
    for (int i = 1; i <= q; i++)
        cout << ans[i] << '\n';
    auto cmp = [](int x, int y){return true;};
    set <int, decltype(cmp)> s;
}