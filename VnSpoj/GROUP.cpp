#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
using ll = long long;
using ii = pair <int, int>;

const int C = 1e6 + 5;
const int N = 3e5 + 5;

class lichao_tree{
private:
    class line{
    public:
        ll a, b;

        line(): a(1e9), b(1e18){}

        line(ll a, ll b): a(a), b(b){}

        ll operator () (ll x){
            return a * x + b;
        }
    } s[C * 4];

    void insert(int i, int l, int r, line d){
        if (l + 1 == r){
            if (d(l) < s[i](l)) s[i] = d; return;
        }
        int m = (l + r) / 2;
        if (s[i].a > d.a) swap(s[i], d);
        if (s[i](m) > d(m)){
            swap(s[i], d);
            insert(i * 2 + 1, m, r, d);
        }
        else insert(i * 2, l, m, d);
    }

    ll query(int i, int l, int r, int x){
        if (l + 1 == r) return s[i](x);
        int m = (l + r) / 2;
        if (x < m) return min(s[i](x),
                        query(i * 2, l, m, x));
        else return min(s[i](x),
                query(i * 2 + 1, m, r, x));
    }
public:
    void insert(ll a, ll b){
        insert(1, 0, C, {a, b});
    }

    ll query(int x){
        return query(1, 0, C, x);
    }
} lct;

int main(){
    int n; cin >> n;
    vector <ii> a(n), b;
    for (auto &pp : a) cin >> pp.fi >> pp.se;
    sort(a.begin(), a.end());
    for (auto pp : a){
        while (!b.empty() && b.back().se < pp.se)
            b.pop_back();
        b.push_back(pp);
    }
    ll last = 0;
    for (auto pp : b){
        lct.insert(pp.se, last);
        last = lct.query(pp.fi);
    }
    cout << last << '\n';
}
