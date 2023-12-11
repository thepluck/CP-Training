#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

class heap{
private:
    static const int N = 1e6 + 5;

    class node{
    public:
        int val, rnk, ls, rs;

        node(): val(0), rnk(0), ls(0), rs(0){}
    };

    node t[N]; int sz = 0, root = 0, _sz = 0;

    int merge(int x, int y){
        if (!x || !y) return x | y;
        if (t[x].val > t[y].val) swap(x, y);
        t[x].rs = merge(t[x].rs, y);
        if (t[t[x].ls].rnk < t[t[x].rs].rnk)
            swap(t[x].ls, t[x].rs);
        t[x].rnk = t[t[x].rs].rnk + 1;
        return x;
    }

public:
    void push(int val){
        t[++sz].val = val; _sz++;
        root = merge(root, sz);
    }

    void pop(){
        root = merge(t[root].ls, t[root].rs);
        _sz--;
    }

    int top() const {
        return t[root].val;
    }

    int size() const {
        return _sz;
    }

    bool empty() const {
        return _sz == 0;
    }
} h;

int main(){
    freopen("dynamic.inp", "r", stdin);
    freopen("dynamic.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int minv  = INT_MAX;
    for (int i = 1; i <= 100; i++){
        int x = rng() % 10000000;
        minv = min(minv, x); h.push(x);
        cout << h.top() << ' ' << minv << '\n';
    }
}