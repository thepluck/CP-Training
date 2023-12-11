#include <bits/stdc++.h>

using namespace std;

#define il i * 2
#define ir i * 2 + 1

using ll = long long;

const int N = 5005;
const int M = 205;

ll val[N * 4], tag[N * 4], res;
int x, y, a[N][M], d[N];
stack<int> stk[M];

void apply(int i, ll v) {
    val[i] += v; tag[i] += v;
}

void push(int i) {
    apply(il, tag[i]);
    apply(ir, tag[i]);
    tag[i] = 0;
}

void add(int i, int l, int r, ll v) {
    if (l >= x && r <= y)
        return apply(i, v);
    int m = (l + r) / 2; push(i);
    if (m >= x) add(il, l, m, v);
    if (m < y) add(ir, m + 1, r, v);
    val[i] = max(val[il], val[ir]);
}

void get(int i, int l, int r) {
    if (l >= x && r <= y) {
        res = max(res, val[i]); return;
    }
    int m = (l + r) / 2; push(i);
    if (m >= x) get(il, l, m);
    if (m < y) get(ir, m + 1, r);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i = 2; i <= n; i++)
        cin >> d[i];
    for (int i = 1; i <= m; i++)
        stk[i].push(0);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            while (stk[j].top() &&
            a[stk[j].top()][j] < a[i][j]) {
                y = stk[j].top(); stk[j].pop();
                x = stk[j].top() + 1;
                add(1, 1, n, a[i][j] - a[y][j]);
            }
            stk[j].push(i);
            x = i; y = i;
            add(1, 1, n, a[i][j]);
        }
        if (i > 1) {
            x = 1; y = i - 1;
            add(1, 1, n, -d[i]);
        }
        x = 1; y = i; res = 0;
        get(1, 1, n);
        ans = max(ans, res);
    }
    cout << ans;
}