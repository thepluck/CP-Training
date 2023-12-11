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

    node* merge(node *l, node *r){
        if (!l || !r) return l ? l : r;
        if (l->prior > r->prior)
            return l->r = merge(l->r, r), update(l), l;
        else return r->l = merge(l, r->l), update(r), r;
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

    bool insert(int key){
        node *l, *m, *r;
        split(root, key, l, m);
        split(m, key + 1, m, r);
        if (m){
            root = merge(merge(l, m), r);
            return false;
        }
        root = merge(merge(l, new node(key)), r);
        return true;
    }

    bool erase(int key){
        node *l, *m, *r;
        split(root, key, l, m);
        split(m, key + 1, m, r);
        root = merge(l, r);
        if (m){
            delete m; return true;
        }
        return false;
    }

    int find_by_order(int k){
        return find_by_order(root, k);
    }

    int order_of_key(int key){
        node *l, *r; 
        split(root, key, l, r);
        int res = size(l); 
        root = merge(l, r);
        return res;
    }

    int size() const {
        return root ? root->sz : 0;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    treap s; int q, val; char cmd; cin >> q;
    while (q--){
        cin >> cmd >> val;
        if (cmd == 'I') s.insert(val);
        if (cmd == 'D') s.erase(val);
        if (cmd == 'C') 
            cout << s.order_of_key(val) << '\n';
        if (cmd == 'K'){
            if (s.size() < val) cout << "invalid\n";
            else cout << s.find_by_order(val) << '\n';
        }
    }
}