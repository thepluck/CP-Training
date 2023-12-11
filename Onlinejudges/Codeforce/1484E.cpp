#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
const int N = 3e5 + 5;
const ll inf = -1e18;
 
int lo, hi, a[N], b[N];
ll tr[N * 4], tg[N * 4], dp[N];
 
void push_tag(int i, ll v) {
    tr[i] += v; tg[i] += v;
}
 
void push_down(int i) {
    push_tag(i * 2, tg[i]);
    push_tag(i * 2 + 1, tg[i]);
    tg[i] = 0;
}
 
void update(int i, int l, int r, ll v) {
    if (l > hi || r < lo) return;
    if (l >= lo && r <= hi)
        return push_tag(i, v);
    push_down(i);
    int m = (l + r) / 2;
    int ls = i * 2, rs = ls + 1;
    update(ls, l, m, v);
    update(rs, m + 1, r, v);
    tr[i] = max(tr[ls], tr[rs]);
}
 
ll query(int i, int l, int r) {
    if (l > hi || r < lo) return inf;
    if (l >= lo && r <= hi) return tr[i];
    push_down(i);
    int m = (l + r) / 2;
    int ls = i * 2, rs = ls + 1;
    return max(query(ls, l, m),
            query(rs, m + 1, r));
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    stack <int> st; st.push(0);
    for (int i = 1; i <= n; i++) {
        while (st.top() && a[st.top()] >= a[i]) {
            hi = st.top(); st.pop();
            lo = st.top() + 1;
            update(1, 1, n, b[i] - b[hi]);
        }
        st.push(i); lo = i; hi = i;
        update(1, 1, n, dp[i - 1] + b[i]);
        lo = 1; hi = i;
        dp[i] = query(1, 1, n);
    }
    cout << dp[n] << '\n';
} 