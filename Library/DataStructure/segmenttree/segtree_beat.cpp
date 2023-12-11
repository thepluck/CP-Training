#include <algorithm>
#include <iostream>
using namespace std;

char nc(){
    static char buf[1000000], *p = buf, *q = buf;
    return p == q && (q = (p = buf) +
            fread(buf, 1, 1000000, stdin),
            p == q) ? EOF : *p++;
}
int rd(){
    int res = 0; char c = nc();
    while (!isdigit(c)) c = nc();
    while (isdigit(c)){
        res = res * 10 + c - '0'; c = nc();
    }
    return res;
}

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

using ll = long long;
using fast_io::read;
using fast_io::writeln;
const int N = 1e6 + 5;

ll sum[N * 4];
int fi[N * 4], se[N * 4], cn[N * 4], tag[N * 4], a[N];

void push_up(int u){
    int ls = u * 2, rs = u * 2 + 1;
    sum[u] = sum[ls] + sum[rs];
    if (fi[ls] == fi[rs]){
        fi[u] = fi[ls];
        cn[u] = cn[ls] + cn[rs];
        se[u] = max(se[ls], se[rs]);
    }
    else if (fi[ls] > fi[rs]){
        fi[u] = fi[ls]; cn[u] = cn[ls];
        se[u] = max(se[ls], fi[rs]);
    }
    else {
        fi[u] = fi[rs]; cn[u] = cn[rs];
        se[u] = max(fi[ls], se[rs]);
    }
}

void push_tag(int u, int tg){
    if (fi[u] <= tg) return;
    sum[u] += 1ll * (tg - fi[u]) * cn[u];
    fi[u] = tag[u] = tg;
}

void push_down(int u){
    if (tag[u] == -1) return;
    push_tag(u * 2, tag[u]);
    push_tag(u * 2 + 1, tag[u]);
    tag[u] = -1;
}

void build(int u, int l, int r){
    tag[u] = -1;
    if (l == r){
        sum[u] = fi[u] = a[l];
        se[u] = -1; cn[u] = 1;
    }
    else {
        int m = (l + r) / 2;
        build(u * 2, l, m);
        build(u * 2 + 1, m + 1, r);
        push_up(u);
    }
}

void set_min(int u, int l, int r, int lo, int hi, int v){
    if (fi[u] <= v) return;
    if (l >= lo && r <= hi && se[u] < v)
        return push_tag(u, v);
    int m = (l + r) / 2; push_down(u);
    if (m >= lo) set_min(u * 2, l, m, lo, hi, v);
    if (m < hi) set_min(u * 2 + 1, m + 1, r, lo, hi, v);
    push_up(u);
}

int get_max(int u, int l, int r, int lo, int hi){
    if (l >= lo && r <= hi) return fi[u];
    int m = (l + r) / 2, lf = -1, rf = -1;
    push_down(u);
    if (m >= lo) lf = get_max(u * 2, l, m, lo, hi);
    if (m < hi) rf = get_max(u * 2 + 1, m + 1, r, lo, hi);
    return max(lf, rf);
}

ll get_sum(int u, int l, int r, int lo, int hi){
    if (l >= lo && r <= hi) return sum[u];
    int m = (l + r) / 2; ll lf = 0, rf = 0;
    push_down(u);
    if (m >= lo) lf = get_sum(u * 2, l, m, lo, hi);
    if (m < hi) rf = get_sum(u * 2 + 1, m + 1, r, lo, hi);
    return lf + rf;
}

void solve(){
    int n, q; n = rd(); q = rd();
    for (int i = 1; i <= n; i++) a[i] = rd();
    build(1, 1, n);
    while (q--){
        int cmd, l, r;
        cmd = rd(); l = rd(); r = rd();
        if (cmd == 0){
            int v; v = rd(); set_min(1, 1, n, l, r, v);
        }
        else if (cmd == 1)
            writeln(get_max(1, 1, n, l, r));
        else writeln(get_sum(1, 1, n, l, r));
    }
}

int main(){
    freopen("HDU5306.inp", "r", stdin);
    freopen("HDU5306.out", "w", stdout);
    int t; t = rd(); while (t--) solve();
}
