#include <bits/stdc++.h>

using namespace std;

const int N = 1 << 20;

int a[N], b[N], BIT[N];
long long res;

void add(int i, int v) {
    for (; i > 0; i -= i & -i)
        BIT[i] += v;
}

int get(int i) {
    int v = 0;
    for (; i < N; i += i & -i)
        v += BIT[i];
    return v;
}

void DFS(int l, int r) {
    if (l + 1 == r) return;
    int m = (l + r) / 2;
    long long inv1 = 0, inv2 = 0;
    for (int i = l; i < m; i++)
        add(a[i], 1);
    for (int i = m; i < r; i++)
        inv1 += get(a[i]);
    for (int i = l; i < m; i++)
        add(a[i], -1);
    for (int i = m; i < r; i++)
        add(a[i], 1);
    for (int i = l; i < m; i++)
        inv2 += get(a[i]);
    for (int i = m; i < r; i++)
        add(a[i], -1);
    res += min(inv1, inv2);
    DFS(l, m); DFS(m, r);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n; n = 1 << n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    DFS(0, n); cout << res;
}