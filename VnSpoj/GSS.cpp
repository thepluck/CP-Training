#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e4 + 10;
const int inf = 0x3f3f3f3f;
typedef const int& ci;

template <typename T> inline void read(T &x){
    register char c;
    bool nega = 0;
    while((!isdigit(c = getchar())) && (c != '-'));
    if (c == '-'){
        nega = 1;
        c = getchar();
    }
    x = c - 48;
    while (isdigit(c = getchar()))
        x = x * 10 + c - 48;
    if (nega)
        x = -x;
}
template <typename T> inline void writep(T x){
    if(x > 9) writep(x / 10);
    putchar(x % 10 + 48);
}
template <typename T> inline void write(T x){
    if (x < 0){
        putchar('-');
        x = -x;
    }
    writep(x);
}
template <typename T> inline void writeln(T x){
    write(x);
    putchar('\n');
}

struct data{
    int sum, pre, suf, ans;
    data(int sum, int pre, int suf, int ans) :
        sum(sum), pre(pre), suf(suf), ans(ans) {}
    data() {}
};
int a[maxn], lo[maxn << 2], hi[maxn << 2];
data node[maxn << 2];

data combine(const data& u, const data& v){
    data w;
    w.sum = u.sum + v.sum;
    w.pre = max(u.pre, u.sum + v.pre);
    w.suf = max(v.suf, v.sum + u.suf);
    w.ans = max(u.suf + v.pre, max(u.ans, v.ans));
    return w;
}

void build(ci i, ci low, ci high){
    lo[i] = low; hi[i] = high;
    if (low == high){
        node[i] = data(a[low], a[low], a[low], a[low]);
        return;
    }
    int med = (low + high) >> 1;
    build(i << 1, low, med);
    build(i << 1 | 1, med + 1, high);
    node[i] = combine(node[i << 1], node[i << 1 | 1]);
}

data get(ci i, ci a, ci b){
    if (b < lo[i] || a > hi[i] || lo[i] > hi[i])
        return data(0, -inf, -inf, -inf);
    if (a <= lo[i] && b >= hi[i])
        return node[i];
    return combine(get(i << 1, a, b), get(i << 1 | 1, a, b));
}

int main(){
    int n, q, u, v; read(n);
    for (int i = 1; i <= n; i++) read(a[i]);
    build(1, 1, n); read(q);
    while (q--){
        read(u); read(v);
        writeln(get(1, u, v).ans);
    }
}
