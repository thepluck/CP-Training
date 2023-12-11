#include <bits/stdc++.h>
#include "peru.h"

using namespace std;

const int MOD = 1000000007;

using ll = long long;
 
const int MAXN = 4e5 + 5;
const ll INF = 1e18;
 
int lo, hi; stack <int> st;
ll tr[MAXN * 4], tg[MAXN * 4];
 
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
    tr[i] = min(tr[ls], tr[rs]);
}
 
ll query(int i, int l, int r) {
    if (l > hi || r < lo) return INF;
    if (l >= lo && r <= hi) return tr[i];
    push_down(i);
    int m = (l + r) / 2;
    int ls = i * 2, rs = ls + 1;
    return min(query(ls, l, m),
            query(rs, m + 1, r));
}

int solve(int N, int K, int* V){
    vector <int> A(N + 1);
    vector <long long> DP(N + 1);
    for (int i = 1; i <= N; i++)
        A[i] = V[i - 1];
    st.push(0);
    for (int i = 1; i <= N; i++) {
        while (st.top() && A[st.top()] <= A[i]) {
            hi = st.top(); st.pop();
            lo = st.top() + 1;
            update(1, 0, N, A[i] - A[hi]);
        }
        st.push(i); lo = i; hi = i;
        update(1, 0, N, DP[i - 1] + A[i]);
        lo = max(i - K + 1, 1); hi = i;
        DP[i] = query(1, 0, N);
    }
    long long res = 0, pw = 1;
    for (int i = 0; i < N; i++) {
        DP[N - i] %= MOD;
        (res += DP[N - i] * pw % MOD) %= MOD;
        pw = pw * 23 % MOD;
    }
    return res;
}
