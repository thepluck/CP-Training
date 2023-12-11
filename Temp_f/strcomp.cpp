/**
 * 2 queries : 
 * (- k) : erase kth element in string
 * (? l r k) : check if [l, l + k) == [r, r + k)
 * */

/**
 * binary search on segment tree (walk on segment tree)
 * */

#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
using ll = long long;
const int mod = 1e9 + 7;
const int N = 1e6 + 5;

struct modular{
    int val; modular(): val(0){}
    template <typename T>
    modular(T x): val(x % mod){
        if (val < 0) val += mod;
    }
};

istream& operator >> (istream &is, modular &x){
    ll a; is >> a; x = modular(a); return is;
}

ostream& operator << (ostream &os, const modular &x){
    return os << x.val;
}

modular operator + (const modular &a, const modular &b){
    return modular(ll(a.val) + ll(b.val));
}

modular operator - (const modular &a, const modular &b){
    return modular(ll(a.val) - ll(b.val));
}

modular operator * (const modular &a, const modular &b){
    return modular(ll(a.val) * ll(b.val));
}

bool operator == (const modular &a, const modular &b){
    return a.val == b.val;
}

const modular base = modular(53);
modular Hash[N << 2], Pow[N];
int lo[N << 2], hi[N << 2], cnt[N << 2];
char s[N]; int n;

void build(int i, int l, int r){
    lo[i] = l; hi[i] = r;
    if (l == r){
        cnt[i] = 1; Hash[i] = s[l]; return;
    }
    int m = (l + r) >> 1;
    build(i << 1, l, m); build(i << 1 | 1, m + 1, r);
    cnt[i] = cnt[i << 1] + cnt[i << 1 | 1];
    Hash[i] = Hash[i << 1] * Pow[cnt[i << 1 | 1]] + Hash[i << 1 | 1];
}

int get_pos(int i, int k){
    if (lo[i] == hi[i]) return lo[i];
    if (cnt[i << 1] >= k) return get_pos(i << 1, k);
    return get_pos(i << 1 | 1, k - cnt[i << 1]);
}

void update(int i, int pos){
    if (lo[i] > pos || hi[i] < pos) return;
    if (lo[i] == hi[i]){
        cnt[i] = 0; Hash[i] = 0; return;
    }
    update(i << 1, pos); update(i << 1 | 1, pos);
    cnt[i] = cnt[i << 1] + cnt[i << 1 | 1];
    Hash[i] = Hash[i << 1] * Pow[cnt[i << 1 | 1]] + Hash[i << 1 | 1];
}

pair <int, modular> get_val(int i, int l, int r){
    if (lo[i] > r || hi[i] < l) return {0, modular()};
    if (lo[i] >= l && hi[i] <= r) return {cnt[i], Hash[i]};
    auto lval = get_val(i << 1, l, r);
    auto rval = get_val(i << 1 | 1, l, r);
    return {lval.fi + rval.fi, lval.se * Pow[rval.fi] + rval.se};
}

void process(){
    scanf("%s", s + 1); n = strlen(s + 1);
    Pow[0] = modular(1); char cmd; int l, r, k;
    for (int i = 1; i <= n; i++) Pow[i] = Pow[i - 1] * base;
    build(1, 1, n); int t; cin >> t;
    while (t--){
        cin >> cmd; 
        if (cmd == '?'){
            cin >> l >> r >> k;
            auto lval = get_val(1, get_pos(1, l), get_pos(1, l + k - 1));
            auto rval = get_val(1, get_pos(1, r), get_pos(1, r + k - 1));
            if (lval.se == rval.se) cout << "YES\n";
            else cout << "NO\n";
        }
        else {
            cin >> k; update(1, get_pos(1, k));
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); process();
}