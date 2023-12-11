#include <bits/stdc++.h>
using namespace std;

namespace fast_io{
    template <typename T>
    void read(T &x){
        char c; bool nega = 0; x = 0;
        while (!isdigit(c = getchar()) && c != '-');
        if (c == '-'){
            nega = 1; c = getchar();
        }
        for (; isdigit(c); c = getchar())
            x = (x << 1) + (x << 3) + c - 48;
        if (nega) x = -x;
    }

    template <typename T>
    void writep(T x){
        if (x > 9) writep(x / 10);
        putchar(x % 10 + 48);
    }

    template <typename T>
    void write(T x){
        if (x < 0){
            x = -x; putchar('-');
        }
        writep(x);
    }

    template <typename T>
    void writeln(T x){
        write(x); putchar('\n');
    }
}

#define debug(x) cout << #x << " = " << (x) << '\n'
const int mod = 1e9;
const int N = 5e5 + 5;

struct modular{
    int val;
    modular(): val(0){}
    template <class T>
    modular(T x): val(x % mod){
        if (val < 0) val += mod;
    }
    bool operator != (const modular &o){
        return val != o.val;
    }
    bool operator == (const modular &o){
        return val == o.val;
    }
};
 
modular operator + (const modular &a, const modular &b){
    return modular(a.val + b.val);
}
 
modular operator * (const modular &a, const modular &b){
    return modular(1ll * a.val * b.val);
}

modular operator - (const modular &a, const modular &b){
    return modular(a.val - b.val);
}
 
void operator *= (modular &a, const modular &b){
    a = a * b;
}
 
void operator += (modular &a, const modular &b){
    a = a + b;
}

void operator -= (modular &a, const modular &b){
    a = a - b;
}

ostream& operator << (ostream &os, const modular &a){
    return os << a.val;
}

struct node{
    int lo, hi;
    modular sm, sM, sl, smMl;
    modular smM, sml, sMl;
    modular m, M, l;

    void set_m(){
        if (m == 0) return;
        sm = m * (hi - lo + 1);
        smM = m * sM; sml = m * sl;
        smMl = m * sMl; m = 0;
    }

    void set_M(){
        if (M == 0) return;
        sM = M * (hi - lo + 1);
        smM = M * sm; sMl = M * sl;
        smMl = M * sml; M = 0;
    }

    void add_l(){
        if (l == 0) return;
        sl += l * (hi - lo + 1);
        sml += l * sm; sMl += l * sM;
        smMl += l * smM; l = 0;
    }

    void show(){
        debug(sm); debug(sM); debug(sl);
        debug(smM); debug(sml); debug(sMl);
        debug(smMl); cout << '\n';
    }
};

node s[N << 2];

void lazy_down(int i){
    if (s[i].m != 0){
        if (s[i].lo != s[i].hi){
            s[i * 2].m = s[i].m;
            s[i * 2 + 1].m = s[i].m;
        }
        s[i].set_m();
    }
    if (s[i].M != 0){
        if (s[i].lo != s[i].hi){
            s[i * 2].M = s[i].M;
            s[i * 2 + 1].M = s[i].M;
        }
        s[i].set_M();
    }
    if (s[i].l != 0){
        if (s[i].lo != s[i].hi){
            s[i * 2].l += s[i].l;
            s[i * 2 + 1].l += s[i].l;
        }
        s[i].add_l();
    }
}

void update(int i){
    s[i].sm = s[i * 2].sm + s[i * 2 + 1].sm;
    s[i].sM = s[i * 2].sM + s[i * 2 + 1].sM;
    s[i].sl = s[i * 2].sl + s[i * 2 + 1].sl;
    s[i].smM = s[i * 2].smM + s[i * 2 + 1].smM;
    s[i].sml = s[i * 2].sml + s[i * 2 + 1].sml;
    s[i].sMl = s[i * 2].sMl + s[i * 2 + 1].sMl;
    s[i].smMl = s[i * 2].smMl + s[i * 2 + 1].smMl;
}

void build(int i, int lo, int hi){
    s[i].lo = lo; s[i].hi = hi;
    if (lo != hi){
        int mi = (lo + hi) / 2;
        build(i * 2, lo, mi);
        build(i * 2 + 1, mi + 1, hi);
    }
}

void set_m(int i, int lo, int hi, int m){
    lazy_down(i);
    if (s[i].lo > hi || s[i].hi < lo) return;
    if (s[i].lo >= lo && s[i].hi <= hi){
        if (s[i].lo != s[i].hi)
            s[i * 2].m = s[i * 2 + 1].m = m;
        s[i].m = m; s[i].set_m(); return;
    }
    set_m(i * 2, lo, hi, m);
    set_m(i * 2 + 1, lo, hi, m);
    update(i);
}

void set_M(int i, int lo, int hi, int M){
    lazy_down(i);
    if (s[i].lo > hi || s[i].hi < lo) return;
    if (s[i].lo >= lo && s[i].hi <= hi){
        if (s[i].lo != s[i].hi)
            s[i * 2].M = s[i * 2 + 1].M = M;
        s[i].M = M; s[i].set_M(); return;
    }
    set_M(i * 2, lo, hi, M);
    set_M(i * 2 + 1, lo, hi, M);
    update(i);
}

void add_l(int i, int lo, int hi, int l){
    lazy_down(i);
    if (s[i].lo > hi || s[i].hi < lo) return;
    if (s[i].lo >= lo && s[i].hi <= hi){
        if (s[i].lo != s[i].hi){
            s[i * 2].l += l; s[i * 2 + 1].l += l;
        }
        s[i].l += l; s[i].add_l(); return;
    }
    add_l(i * 2, lo, hi, l);
    add_l(i * 2 + 1, lo, hi, l);
    update(i);
}

modular get_smMl(int i, int lo, int hi){
    lazy_down(i);
    if (s[i].lo > hi || s[i].hi < lo) return 0;
    if (s[i].lo >= lo && s[i].hi <= hi) return s[i].smMl;
    return get_smMl(i * 2, lo, hi) 
            + get_smMl(i * 2 + 1, lo, hi);
}

int main(){
    using namespace fast_io;
    int n; read(n); build(1, 1, n);
    array <int, N> a; modular ans = 0;
    stack <int> inc, dec; 
    inc.push(0); dec.push(0);
    for (int i = 1; i <= n; i++){
        read(a[i]);
        while (dec.top() && a[dec.top()] < a[i]) dec.pop();
        while (inc.top() && a[inc.top()] > a[i]) inc.pop();
        set_m(1, inc.top() + 1, i, a[i]);
        set_M(1, dec.top() + 1, i, a[i]);
        add_l(1, 1, i, 1); dec.push(i); inc.push(i);
        ans += get_smMl(1, 1, i);
    }
    writeln(ans);
}