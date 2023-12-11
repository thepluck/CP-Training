#include <bits/stdc++.h>

using namespace std;

void read(char &c) {
    static char buf[1000000];
    static char *p = buf, *q = buf;
    c = p == q && (q = (p = buf) +
    fread(buf, 1, 1000000, stdin),
    p == q) ? EOF : *p++;
}

void read(int &x) {
    char c; read(c);
    while (c != '-' && !isdigit(c))
        read(c);
    bool y = 0;
    if (c == '-') {
        y = 1; read(c);
    }
    x = 0;
    while (isdigit(c)) {
        x = x * 10 + c - '0';
        read(c);
    }
    if (y) x = -x;
}

struct query {
    int l, r, id;
};

const int N = 2500005;

int a[N], nxt[N], mx[N], cmp[N];
query que[N]; map<int, int> last;
long long ans[N];
vector<int> ch[N];


namespace fenwick {
    long long bit[N];
    
    void reset() {
        memset(bit, 0, sizeof bit);
    }
    
    void add(int i, int v, int t) {
        if (t) {
            for (; i < N; i += i & -i)
                bit[i] += v;
        } else {
            for (; i > 0; i -= i & -i)
                bit[i] += v;
        }
    }
    
    long long get(int i, int t) {
        long long res = 0;
        if (t) {
            for (; i > 0; i -= i & -i)
                res += bit[i];
        } else {
            for (; i < N; i += i & -i)
                res += bit[i];
        }
        return res;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; read(n); read(q);
    for (int i = 1; i <= n; i++)
        read(a[i]);
    for (int i = 1; i <= q; i++) {
        read(que[i].l); read(que[i].r);
        que[i].id = i;
    }
    sort(que + 1, que + q + 1, [&](query x, query y) {
        return x.r < y.r;
    });
    int cnt = 0;
    vector<int> stk(1, 0); fenwick::reset();
    for (int i = 1, j = 1; i <= n; i++) {
        while (stk.back() && a[stk.back()] <= a[i])
            stk.pop_back();
        nxt[i] = stk.back(); stk.push_back(i);
        if (last[a[i]] > nxt[i])
            cmp[i] = cmp[last[a[i]]];
        else cmp[i] = ++cnt;
        ch[cmp[i]].push_back(i);
        last[a[i]] = i;
        while (j <= q && que[j].r == i) {
            mx[j] = *lower_bound(stk.begin(), stk.end(), que[j].l); j++;
        }
        
    }
    for (int i = 1, j = 1; i <= n; i++) {
        if (nxt[i]) fenwick::add(nxt[i], 1, 0);
        if (i == ch[cmp[i]].back()) {
            for (int k = 0; k < ch[cmp[i]].size(); k++)
                fenwick::add(ch[cmp[i]][k], ch[cmp[i]].size() - k, 0);
        }
        while (j <= q && que[j].r == i) {
            int k = cmp[mx[j]];
            auto l = lower_bound(ch[k].begin(), ch[k].end(), que[j].l);
            auto r = upper_bound(ch[k].begin(), ch[k].end(), que[j].r);
            if (l != ch[k].begin() && r != ch[k].end())
                ans[que[j].id] += 1ll * (r - l) * (r - l + 1) / 2;
            ans[que[j].id] += fenwick::get(que[j].l, 0); j++;
        }
    }
    sort(que + 1, que + q + 1, [&](query x, query y) {
        return x.l > y.l;
    });
    stk.assign(1, 0); fenwick::reset();
    for (int i = n, j = 1; i > 0; i--) {
        while (stk.back() && a[stk.back()] <= a[i])
            stk.pop_back();
        nxt[i] = stk.back(); stk.push_back(i);
        if (nxt[i]) fenwick::add(nxt[i], 1, 1);
        if (i == ch[cmp[i]][0]) {
            for (int k = 0; k + 1 < ch[cmp[i]].size(); k++) {
                fenwick::add(ch[cmp[i]][k], k + 1, 1);
                fenwick::add(ch[cmp[i]].back(), -1 - k, 1);
            }
        }
        while (j <= q && que[j].l == i) {
            ans[que[j].id] += fenwick::get(que[j].r, 1); j++;
        }
    }
    for (int i = 1; i <= q; i++)
        cout << ans[i] << '\n';
}