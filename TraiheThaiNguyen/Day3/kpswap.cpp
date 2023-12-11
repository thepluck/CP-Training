#include <bits/stdc++.h>
using namespace std;

const int C = 8e6 + 5;;
const int N = 7e5 + 5;
int pr[N], lp[C];

void sieve(){
    int cnt = 0;
    for (int i = 2; i < C; i++){
        if (lp[i] == 0){
            lp[i] = i; pr[++cnt] = i;
        }
        for (int j = 1; j <= cnt &&
        pr[j] <= lp[i] && i * pr[j] < C; j++)
            lp[i * pr[j]] = pr[j];
    }
}

mt19937 rng(chrono::steady_clock::now().
time_since_epoch().count());
const int ninf = 0xc0c0c0c0;

int rng_range(int l, int r){
    return uniform_int_distribution <int> (l, r)(rng);
}

class implicit_array{
private:
    class node{
    public:
        int pr, sz = 1, val;
        node *l = NULL, *r = NULL;
        bool rev = 0;

        node(): pr(rng()){}
        
        node(int val): val(val), pr(rng_range(1, 1e9)){}

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
            pt->rev = false;
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

    void rotate(int key){
        node *l, *r;
        split(root, key, l, r);
        root = merge(r, l);
    }
} a;

int main(){
    //freopen("kpswap.inp", "r", stdin);
    //freopen("kpswap.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    sieve(); int n, k, t;
    cin >> n >> k >> t;
    for (int i = 1; i <= n; i++)
        a.push_back(i);
    for (int i = 1; i <= k; i++){
        int x = a[0], y = pr[i] % (n - 1);
        a.pop_front(); a.insert(y, x);
        int z = pr[i] / (n - 1) % n;
        a.rotate(z);
    }
    int pos;
    for (int i = 0; i < n; i++)
        if (a[i] == t) pos = i;
    cout << a[(pos + 1) % n] << ' ';
    cout << a[(pos - 1 + n) % n] << '\n';
}