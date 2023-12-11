#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int ninf = 0xc0c0c0c0;

class implicit_array{
private:
    class node{
    public:
        int pr, sz = 1, ma, val;
        node *l = NULL, *r = NULL;

        node(): pr(rng()){}
        
        node(int val): val(val), pr(rng()), ma(val){}

        ~node(){
            delete l; delete r;
        }
    } *root;

    int sz(node *pt){
        return pt ? pt-> sz : 0;
    }

    int ma(node *pt){
        return pt ? pt->ma : ninf;
    }

    void update(node *pt){
        if (pt){
            pt->sz = sz(pt->l) + sz(pt->r) + 1;
            pt->ma = max({pt->val, ma(pt->l), ma(pt->r)});
        }
    }

    node *merge(node *l, node *r){
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
    implicit_array(): root(NULL){}

    ~implicit_array(){
        delete root;
    }

    int size() const {
        return root ? root->sz : 0;
    }

    void push_back(int val){
        root = merge(root, new node(val));
    }

    void pop_back(){
        node *l, *r;
        split(root, size() - 1, l, r);
        root = l; delete r;
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

    int& operator [] (const int &key){
        assert(key < size());
        node *l, *m, *r;
        split(root, key + 1, m, r);
        split(m, key, l, m);
        int &res = m->val;
        root = merge(merge(l, m), r);
        return res;
    }

    int get_max(int a, int b){
        node *l, *m, *r;
        split(root, b, m, r);
        split(m, a, l, m);
        int res = ma(m);
        root = merge(merge(l, m), r);
        return res;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    implicit_array a; 
    int q, u, v; char cmd; cin >> q;
    while (q--){
        cin >> cmd >> u >> v;
        if (cmd == 'A') a.insert(v - 1, u);
        else cout << a.get_max(u - 1, v) << '\n';
    }
}