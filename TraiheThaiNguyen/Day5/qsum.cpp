#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e4 + 10;
const int inf = 0x3f3f3f3f;

struct info{
    int sum, pre, suf, ans;
    info(int sum, int pre, int suf, int ans) :
        sum(sum), pre(pre), suf(suf), ans(ans) {}
    info() {}
};
int a[maxn], lo[maxn << 2], hi[maxn << 2];
info node[maxn << 2];

info com(const info& u, const info& v){
    info w;
    w.sum = u.sum + v.sum;
    w.pre = max(u.pre, u.sum + v.pre);
    w.suf = max(v.suf, v.sum + u.suf);
    w.ans = max(u.suf + v.pre, max(u.ans, v.ans));
    return w;
}

void build(int i, int low, int high){
    lo[i] = low; hi[i] = high;
    if (low == high){
        node[i] = info(a[low], a[low], a[low], a[low]);
        return;
    }
    int med = (low + high) >> 1;
    build(i << 1, low, med);
    build(i << 1 | 1, med + 1, high);
    node[i] = com(node[i << 1], node[i << 1 | 1]);
}

info get(int i, int a, int b){
    if (b < lo[i] || a > hi[i] || lo[i] > hi[i])
        return info(0, -inf, -inf, -inf);
    if (a <= lo[i] && b >= hi[i])
        return node[i];
    return com(get(i << 1, a, b), get(i << 1 | 1, a, b));
}

int main(){
    freopen("qsum.inp", "r", stdin);
    freopen("qsum.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, q, u, v; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n); cin >> q;
    while (q--){
        cin >> u >> v;
        cout << get(1, u, v).ans << '\n';
    }
}
