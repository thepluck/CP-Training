  
#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

class treap{
private:
    class node{
    public:
        int key, prior, sz = 1; 
        node *l = NULL, *r = NULL;
        
        ~node(){
            delete l; delete r;
        }

        node(int key): key(key), prior(rng()){}
    } *root;

    int size(node *pt){
        return pt ? pt->sz : 0;
    }

    void update(node *pt){
        if (pt) pt->sz = size(pt->l) + size(pt->r) + 1;
    }

    node* join(node *l, node *r){
        if (!l || !r) return l ? l : r;
        if (l->prior > r->prior)
            return l->r = join(l->r, r), update(l), l;
        else return r->l = join(l, r->l), update(r), r;
    }

    void split(node *pt, int key, node *&l, node *&r){
        if (!pt) l = r = NULL;
        else if (pt->key < key) 
            split(pt->r, key, pt->r, r), l = pt;
        else split(pt->l, key, l, pt->l), r = pt;
        update(pt);
    }

    int find_by_order(node *pt, int k){
        int l_sz = size(pt->l);
        if (k <= l_sz) 
            return find_by_order(pt->l, k);
        if (k == l_sz + 1) return pt->key;
        return find_by_order(pt->r, k - l_sz - 1);
    }

public:
    treap(): root(NULL){}
    
    ~treap(){
        delete root;
    }

    void insert(int key){
        node *l, *r;
        split(root, key, l, r);
        root = join(join(l, new node(key)), r);
    }

    void erase(int key){
        node *l, *m, *r;
        split(root, key, l, m);
        split(m, key + 1, m, r);
        m = join(m->l, m->r);
        root= join(join(l, m), r);
    }

    int find_by_order(int k){
        return find_by_order(root, k);
    }

    int order_of_key(int key){
        node *l, *r; 
        split(root, key, l, r);
        int res = size(l); 
        root = join(l, r);
        return res;
    }

    int rorder_of_key(int key){
        node *l, *m, *r;
        split(root, key, l, m);
        split(m, key + 1, m, r);
        int res = size(r);
        root= join(join(l, m), r);
        return res;
    }

    int size() const {
        return root ? root->sz : 0;
    }
};

const int N = 30005;
treap tree[4 * N];
int a[N], lo[4 * N], hi[4 * N];

void build(int i, int l, int r){
    lo[i] = l; hi[i] = r;
    for (int j = l; j <= r; j++)
        tree[i].insert(a[j]);
    if (l != r){
        int m =(l + r) / 2;
        build(i * 2, l, m);
        build(i * 2 + 1, m + 1, r);
    }
}

void update(int i, int p, int val){
    if (lo[i] > p || hi[i] < p) return;
    tree[i].erase(a[p]);
    tree[i].insert(val);
    if (lo[i] != hi[i]){
        update(i * 2, p, val);
        update(i * 2 + 1, p, val);
    }
}

int query(int i, int l, int r, int val){
    if (lo[i] > r || hi[i] < l) return 0;
    if (lo[i] >= l && hi[i] <= r)
        return tree[i].rorder_of_key(val);
    return query(i * 2, l, r, val)
            + query(i * 2 + 1, l, r, val);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n;
    for (int i = 1; i <= n; cin >> a[i++]);
    build(1, 1, n); cin >> q;
    int t, l, r, k;
    while (q--){
        cin >> t >> l >> r;
        if (t){
            cin >> k;
            cout << query(1, l, r, k) << '\n';
        }
        else {
            update(1, l, r); a[l] = r;
        }
    }
}