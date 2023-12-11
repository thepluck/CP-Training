#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int ninf = 0xc0c0c0c0;

class implicit_array{
private:
    class node{
    public:
        int pr, sz = 1, val;
        node *l = NULL, *r = NULL;
        bool rev = 0;

        node(): pr(rng()){}
        
        node(int val): val(val), pr(rng()){}

        ~node(){
            delete l; delete r;
        }
    } *root;

    int sz(node *pt){
        return pt ? pt-> sz : 0;
    }

    void update(node *pt){
        if (pt) pt->sz = sz(pt->l) + sz(pt->r) + 1;
    }

    void push(node *pt){
        if (pt && pt->rev){
            swap(pt->l, pt->r);
            if (pt->l) pt->l->rev ^= 1;
            if (pt->r) pt->r->rev ^= 1;
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

    int& operator [] (const int &key){
        assert(key < size());
        node *l, *m, *r;
        split(root, key + 1, m, r);
        split(m, key, l, m);
        int &res = m->val;
        root = merge(merge(l, m), r);
        return res;
    }

    void reverse(int a, int b){
        node *l, *m, *r;
        split(root, b, m, r);
        split(m, a, l, m);
        if (m) m->rev ^= 1;
        root = merge(merge(l, m), r);
    }

    void query1(int a, int b){
        node *l, *m, *r;
        split(root, b, m, r);
        split(m, a, l, m);
        root = merge(m, merge(l, r));
    }

    void query2(int a, int b){
        node *l, *m, *r;
        split(root, b, m, r);
        split(m, a, l, m);
        root = merge(merge(l, r), m);
    }
};

int main(){
    
}