#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300005;
const int INF = 0xc0c0c0c0;

int A[MAXN], lim[MAXN], val[MAXN];
int DP[MAXN], BIT[MAXN];
int len;

void update(int i, int v) {
    for (; i <= len; i += i & -i)
        BIT[i] = max(BIT[i], v);
}

int query(int i) {
    int res = INF;
    for (; i > 0; i -= i & -i)
        res = max(res, BIT[i]);
    return res;
}

void solve(int l, int r) {
    if (l == r) return void(DP[l]++);
    int m = (l + r) / 2;
    solve(m + 1, r);
    vector <int> lef, rig;
    for (int i = l; i <= m; i++)
        lef.push_back(i);
    for (int i = m + 1; i <= r; i++)
        rig.push_back(i);
    sort(lef.begin(), lef.end(), [&](int i, int j) {
        return A[i] > A[j];
    });
    sort(rig.begin(), rig.end(), [&](int i, int j) {
        return A[i] > A[j];
    });
    len = r - l + 1;
    for (int i = 0, j = 0; i < lef.size(); i++) {
        while (j < rig.size() && A[rig[j]] > A[lef[i]]) {
            update(rig[j] - l + 1, DP[rig[j]]); j++;
        }
        DP[lef[i]] = max(DP[lef[i]],
        query(min(len, lim[lef[i]] - l + 1)));
    }
    for (int i = 1; i <= len; i++) BIT[i] = INF;
    solve(l, m);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, D; cin >> N >> D;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    deque <int> dq; vector <int> st;
    for (int i = N; i > 0; i--) {
        while (dq.size() && dq.front() >= i + D)
            dq.pop_front();
        while (dq.size() && A[dq.back()] >= A[i])
            dq.pop_back();
        dq.push_back(i); val[i] = A[i];
        auto it = upper_bound(st.rbegin(), st.rend(),
        i, [&](int x, int y) {return val[x] < val[y];});
        if (i <= N - D && it != st.rend())
            lim[i] = *it + D - 1;
        else lim[i] = N;
        val[i] = A[dq.front()];
        while (st.size() && val[st.back()] <= val[i])
            st.pop_back();
        st.push_back(i);
    }
    memset(BIT, 0xc0, sizeof BIT);
    solve(1, N);
    cout << *max_element(DP + 1, DP + N + 1);
}