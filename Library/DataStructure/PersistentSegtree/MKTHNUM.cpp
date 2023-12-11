#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define ub upper_bound
#define eb emplace_back

struct persistent_segtree{
    struct node{
        int cnt, l, r;

        node(): cnt(0){}

        node(int cnt, int l, int r){
            this->cnt = cnt;
            this->l = l; this->r = r;
        }

        void reset(){
            cnt = l = r = 0;
        }
    };

    static const int N = 1e5 + 5;
    node tree[20 * N];
    int sz = 0, root[N], n = 0, lim;

    persistent_segtree(int lim): lim(lim){
        sz = 0; n = 0;
    }

    persistent_segtree(){}

    void init(int lim){
        this->lim = lim; n = 0; sz = 0;
    }

    int update(int id, int l, int r, int p){
        int nid = ++sz, m = (l + r) / 2;
        tree[nid] = tree[id]; tree[nid].cnt++;
        if (l != r){
            if (p <= m)
                tree[nid].l = update(tree[id].l, l, m, p);
            else tree[nid].r = update(tree[id].r, m + 1, r, p);
        }
        return nid;
    }

    void extend(int val){
        root[n + 1] = update(root[n], 1, lim, val); n++;
    }

    int query(int idl, int idr, int l, int r, int k){
        if (l == r) return l; int m = (l + r) / 2;
        int cnt = tree[tree[idr].l].cnt - tree[tree[idl].l].cnt;
        if (cnt >= k)
            return query(tree[idl].l, tree[idr].l, l, m, k);
        return query(tree[idl].r, tree[idr].r, m + 1, r, k - cnt);
    }

    int query(int l, int r, int k){
        return query(root[l - 1], root[r], 1, lim, k);
    }
};

const int N = 1e5 + 5;
int a[N], val[N]; vector <int> cmp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> a[i]; cmp.eb(a[i]);
    }
    sort(all(cmp));
    cmp.resize(unique(all(cmp)) - cmp.begin());
    persistent_segtree st(n);
    for (int i = 1; i <= n; i++){
        int pre_val = a[i];
        a[i]= ub(all(cmp), a[i]) - cmp.begin();
        val[a[i]] = pre_val; st.extend(a[i]);
    }
    for (int i = 1, l, r, k; i <= q; i++){
        cin >> l >> r >> k;
        cout << val[st.query(l, r, k)] << '\n';
    }
}