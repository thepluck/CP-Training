#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5 + 5;
const int C = 1e6 + 5;
const ll ninf = 0xc0c0c0c0c0c0c0c0;

class lichao_tree{
private:
    class line{
    public:
        ll a, b;

        line(): a(0), b(ninf){}

        line(ll a, ll b): a(a), b(b){}

        ll operator () (int x){
            return a * x + b;
        }
    } s[C * 8];

    void insert(int i, int l, int r, line d){
        if (l + 1 == r){
            if (s[i](l) < d(l)) s[i] = d; return;
        }
        int m = (l + r) / 2;
        if (s[i].a > d.a) swap(s[i], d);
        if (s[i](m) < d(m)){
            swap(s[i], d); insert(i * 2, l, m, d);
        }
        else insert(i * 2 + 1, m, r, d);
    }

    ll query(int i, int l, int r, int x){
        if (l + 1 == r) return s[i](x);
        int m = (l + r) / 2;
        if (x < m) return max(s[i](x),
                    query(i * 2, l, m, x));
        return max(s[i](x),
            query(i * 2 + 1, m, r, x));
    }

public:
    void insert(ll a, ll b){
        insert(1, -C, C, line(a, b));
    }

    ll query(int x){
        return query(1, -C, C, x);
    }
} pre, suf;

int a[N]; ll s[N], tot[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i]; s[i] = s[i - 1] + a[i];
        tot[i] = tot[i - 1] + 1ll * a[i] * i;
    }
    ll ans = tot[n];
    for (int i = 1; i <= n; i++){
        pre.insert(i, -s[i - 1]);
        ans = max(ans, tot[n] - 1ll * a[i] * i
                + s[i - 1] + pre.query(a[i]));
    }
    for (int i = n; i >= 1; i--){
        suf.insert(i, -s[i]);
        ans = max(ans, tot[n] - 1ll * a[i] * i
                + s[i] + suf.query(a[i]));
    }
    cout << ans << '\n';
}