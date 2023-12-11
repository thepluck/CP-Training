#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e5 + 5;
const int C = 1e5 + 5;

class lichao_tree{
private:
    class line{
    public:
        ll a, b;

        line() : a(0), b(0){}

        line(ll a, ll b): a(a), b(b){}

        ll operator () (int x){
            return a * x + b;
        }
    } s[C * 4];

    void insert(int i, int l, int r, line d){
        if (l + 1 == r){
            if (d(l) > s[i](l)) s[i] = d; return;
        }
        if (s[i].a > d.a) swap(s[i], d);
        int m = (l + r) >> 1;
        if (s[i](m) < d(m)){
            swap(s[i], d); insert(i << 1, l, m, d);
        }
        else insert(i << 1 | 1, m, r, d);
    }

    ll query(int i, int l, int r, int x){
        if (l + 1 == r) return s[i](x);
        int m = (l + r) >> 1;
        if (x < m) return max(s[i](x),
                        query(i << 1, l, m, x));
        return max(s[i](x),
            query(i << 1 | 1, m, r, x));
    }

public:
    void insert(ll a, ll b){
        insert(1, 0, C, line(a, b));
    }

    ll query(int x){
        return query(1, 0, C, x);
    }
} lct;

class pizza{
public:
    int t; ll a, b;
};

pizza pp[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; ll b; cin >> n >> b;
    for (int i = 1; i <= n; i++)
        cin >> pp[i].t >> pp[i].a >> pp[i].b;
    sort(pp + 1, pp + n + 1,
    [](const pizza &x, const pizza &y){
        return x.t < y.t;
    });
    ll suma = 0, sumb = 0, total = 0, last = 0;
    for (int i = 1; i <= n; i++){
        lct.insert(sumb, last - total - suma);
        suma += pp[i].a; sumb += pp[i].b;
        total += pp[i].b * pp[i].t;
        last = suma - sumb * pp[i].t - b
                + total + lct.query(pp[i].t);
    }
    cout << last << '\n';
}