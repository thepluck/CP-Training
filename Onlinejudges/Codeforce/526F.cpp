
// Problem : F. Pudding Monsters
// Contest : Codeforces - ZeptoLab Code Rush 2015
// URL : https://codeforces.com/contest/526/problem/F
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

int tr[N * 4], cn[N * 4];
int tg[N * 4], lo, hi, a[N];

void init(int i, int l, int r) {
    cn[i] = r - l + 1;
    if (l != r) {
        int m = (l + r) / 2;
        init(i * 2, l, m);
        init(i * 2 + 1, m + 1, r);
    }
}

void push_tag(int i, int v) {
    tr[i] += v; tg[i] += v;
}

void push_down(int i) {
    push_tag(i * 2, tg[i]);
    push_tag(i * 2 + 1, tg[i]);
    tg[i] = 0;
}

void update(int i, int l, int r, int v) {
    if (l > hi || r < lo) return;
    if (l >= lo && r <= hi)
        return push_tag(i, v);
    push_down(i);
    int m = (l + r) / 2;
    int ls = i * 2, rs = ls + 1;
    update(ls, l, m, v);
    update(rs, m + 1, r, v);
    if (tr[ls] < tr[rs]) {
        tr[i] = tr[ls];
        cn[i] = cn[ls];
    }
    else if (tr[ls] > tr[rs]) {
        tr[i] = tr[rs];
        cn[i] = cn[rs];
    }
    else {
        tr[i] = tr[ls];
        cn[i] = cn[ls] + cn[rs];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int j; cin >> j >> a[j];
    }
    stack <int> inc, dec;
    inc.push(0); dec.push(0);
    init(1, 1, n);
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        while (inc.top() && a[inc.top()] < a[i]) {
            hi = inc.top(); inc.pop();
            lo = inc.top() + 1;
            update(1, 1, n, a[i] - a[hi]);
        }
        while (dec.top() && a[dec.top()] > a[i]) {
            hi = dec.top(); dec.pop();
            lo = dec.top() + 1;
            update(1, 1, n, a[hi] - a[i]);
        }
        inc.push(i); dec.push(i);
        res += cn[1] - n + i;
        lo = 1; hi = i;
        update(1, 1, n, -1);
    }
    cout << res << '\n';
}