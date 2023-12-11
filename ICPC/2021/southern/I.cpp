#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int bit[N], p[N], q[N], a[N];

void add(int i) {
    for (; i > 0; i -= i & -i)
        bit[i]++;
}

int get(int i) {
    int res = 0;
    for (; i < N; i += i & -i)
        res += bit[i];
    return res;
}

void add2(int i) {
    for (; i < N; i += i & -i)
        bit[i]++;
}

int get2(int i) {
    int res = 0;
    for (; i > 0; i -= i & -i)
        res += bit[i];
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    long long res = 0, cur = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[a[i]] = get(a[i]);
        add(a[i]); cur += p[a[i]];
    }
    memset(bit, 0, sizeof bit);
    res = cur;
    for (int i = n; i > 0; i--) {
        q[a[i]] = get2(a[i]);
        add2(a[i]);
    }
    for (int i = 1; i <= n; i++) {
        cur -= p[i];
        res = min(res, cur);
        cur += q[i];
    }
    cout << res;
}