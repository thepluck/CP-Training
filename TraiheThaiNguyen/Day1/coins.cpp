#include <bits/stdc++.h>
using namespace std;

/// maximize
template <class X, class Y>
bool chkmax(X &a, const Y &b) {
    return a < b ? a = b, 1 : 0;
}

/// gold - silver - bronze
struct item {
    int g, s, b;
};

/// comparators
/// gold - bronze
struct compgb {
    bool operator () (const item &a,
    const item &b) const {
        return a.g - a.b > b.g - b.b;
    }
};

/// silver - bronze
struct compsb {
    bool operator () (const item &a,
    const item &b) const {
        return a.s - a.b > b.s - b.b;
    }
};

/// gold - silver
struct compgs {
    bool operator () (const item &a,
    const item &b) const {
        return a.g - a.s > b.g - b.s;
    }
};

const int N = 1e5 + 5;
item a[N]; long long pre[N], suf[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    /// prefix
    priority_queue <item,
    vector <item>, compgb> gb;
    /// suffix
    priority_queue <item,
    vector <item>, compsb> sb;
    int x, y, z; cin >> x >> y >> z;
    int n = x + y + z;
    for (int i = 1; i <= n; i++)
        cin >> a[i].g >> a[i].s >> a[i].b;
    sort(a + 1, a + n + 1, compgs());
    for (int i = 1; i <= x; i++) {
        pre[i] = pre[i - 1] + a[i].g;
        gb.push(a[i]);
    }
    for (int i = x + 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i].g;
        gb.push(a[i]);
        auto rmv = gb.top(); gb.pop();
        pre[i] += rmv.b - rmv.g;
    }
    for (int i = n; i > n - y; i--) {
        suf[i] = suf[i + 1] + a[i].s;
        sb.push(a[i]);
    }
    for (int i = n - y; i > 0; i--) {
        suf[i] = suf[i + 1] + a[i].s;
        sb.push(a[i]);
        auto rmv = sb.top(); sb.pop();
        suf[i] += rmv.b - rmv.s;
    }
    long long res = 0;
    /// merge prefix and suffix
    for (int i = x; i <= n - y; i++)
        chkmax(res, pre[i] + suf[i + 1]);
    cout << res << '\n';
}
