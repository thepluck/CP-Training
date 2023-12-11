#include <bits/stdc++.h>
using namespace std;

using ll = long long;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int ninf = 0xc0c0c0c0;

class implicit_treap{
private:
    class node{
    public:
        int pr, sz = 1; ll val, sum, lz = 0;
        node *l = NULL, *r = NULL;

        node(): pr(rng()){}
        
        node(int val): val(val), pr(rng()), sum(val){}

        ~node(){
            delete l; delete r;
        }
    } *root;

    int sz(node *pt){
        return pt ? pt->sz : 0;
    }

    ll sum(node *pt){
        return pt ? pt->sum : 0;
    }

    void update(node *pt){
        if (pt){
            push(pt->l); push(pt->r);
            pt->sz = sz(pt->l) + sz(pt->r) + 1;
            pt->sum = sum(pt->l) + sum(pt->r) + pt->val;
        }
    }

    void push(node *pt){
        if (pt && pt->lz){
            pt->val += pt->lz;
            pt->sum += pt->lz * pt->sz;
            if (pt->l) pt->l->lz += pt->lz;
            if (pt->r) pt->r->lz += pt->lz;
            pt->lz = 0;
        }
    }

    node *merge(node *l, node *r){
        push(l); push(r);
        if (!l || !r) return l ? l : r;
        node *pt;
        if (l->pr > r->pr){
            l->r = merge(l->r, r); pt = l;
        }
        else {
            r->l = merge(l, r->l); pt = r; 
        }
        update(pt); return pt;
    }

    void split(node *pt, int key, node *&l, node *&r){
        push(pt);
        if (!pt) return void(l = r = NULL);
        if (sz(pt->l) < key){
            split(pt->r, key - sz(pt->l) - 1, pt->r, r);
            l = pt; update(l);
        }
        else {
            split(pt->l, key, l, pt->l);
            r = pt; update(r);
        }
    }

public:
    implicit_treap(): root(NULL){}

    ~implicit_treap(){
        delete root;
    }

    int size() const {
        return root ? root->sz : 0;
    }

    void push_back(int val){
        root = merge(root, new node(val));
    }

    void pop_back(){
        assert(size());
        node *m;
        split(root, size() - 1, root, m);
        delete m;
    }

    void push_front(int val){
        root = merge(new node(val), root);
    }

    void pop_front(){
        assert(size());
        node *m;
        split(root, 1, m, root);
        delete m;
    }

    void insert(int key, int val){
        node *l, *r;
        split(root, key, l, r);
        root = merge(merge(l, new node(val)), r);
    }

    void erase(int key){
        node *l, *m, *r;
        split(root, key + 1, m, r);
        split(m, key, l, m);
        root = merge(l, r); 
        delete m;
    }

    ll& operator [] (const int &key){
        assert(key < size());
        node *l, *m, *r;
        split(root, key + 1, m, r);
        split(m, key, l, m);
        ll &res = m->val;
        root = merge(merge(l, m), r);
        return res;
    }
    
    ll get_sum(int a, int b){
        node *l, *m, *r;
        split(root, b, m, r);
        split(m, a, l, m);
        ll res = sum(m);
        root = merge(merge(l, m), r);
        return res;
    }

    void update(int a, int b, ll val){
        node *l, *m, *r;
        split(root, b, m, r);
        split(m, a, l, m);
        if (m) m->lz += val;
        root = merge(merge(l, m), r);
    }
};

void solve(){
    int n, q, cmd, l, r; cin >> n >> q; 
    implicit_treap a;
    for (int i = 1; i <= n; i++) 
        a.push_back(0);
    while (q--){
        cin >> cmd >> l >> r;
        if (cmd) cout << a.get_sum(l - 1, r) << '\n';
        else {
            cin >> cmd; a.update(l - 1, r, cmd);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--) solve();
    
}