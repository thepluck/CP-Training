#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int ninf = 0xc0c0c0c0;

struct lichao_tree{
    static const int C = 5e4 + 5;

    struct line{
        ll a, b;

        line(): a(ninf), b(ninf){}

        line(ll a, ll b): a(a), b(b){}

        ll operator () (ll x){
            return a * x + b;
        }
    } s[C * 4];

    void insert(int i, int l, int r, line d){
        if (l + 1 == r){
            if (d(l) > s[i](l)) s[i] = d; return;
        }
        int m = (l + r) / 2;
        if (s[i].a > d.a) swap(s[i], d);
        if (s[i](m) < d(m)){
            swap(s[i], d); insert(i * 2, l, m, d);
        }
        else insert(i * 2 + 1, m, r, d);
    }

    ll query(int i, int l, int r, ll x){
        if (l + 1 == r) return s[i](x);
        int m = (l + r) / 2;
        if (x < m) return max(s[i](x), query(i * 2, l, m, x));
        else return max(s[i](x), query(i * 2 + 1, m, r, x));
    }
    
    void insert(ll a, ll b){
        insert(1, 0, C, {a, b});
    }

    ll query(ll x){
        return query(1, 0, C, x);
    }
} lct;

int main(){
    lct.insert(2, -1); lct.insert(4, 2);
    cout << lct.query(9) << '\n';
}