#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1 << 20;

int BIT[MAXN], DP[MAXN];
set <int> pos[MAXN];
int P[MAXN], X[MAXN], A[MAXN];

int kth(int k) {
    int p = 0;
    for (int l = MAXN; l > 0; l >>= 1)
        if (p + l < MAXN && k > BIT[p + l])
            k -= BIT[p += l];
    return p + 1;
}

void add(int i, int v) {
    for (; i < MAXN; i += i & -i)
        BIT[i] += v;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 1; i < MAXN; i++) {
        BIT[i]++;
        if (i + (i & -i) < MAXN)
            BIT[i + (i & -i)] += BIT[i];
    }
    int N; cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> P[i] >> X[i];
    for (int i = N; i > 0; i--) {
        P[i] = kth(P[i]);
        A[P[i]] = X[i]; add(P[i], -1);
    }
    A[0] = -1e9; pos[0].insert(0);
    queue <int> que; int lis = 0;
    set <int>::iterator it;
    for (int i = 1; i <= N; i++) {
        int p = P[i]; DP[p] = X[i];
        while (DP[p]--) {
            it = pos[DP[p]].lower_bound(p);
            if (it != pos[DP[p]].begin()
            && A[*prev(it)] < A[p]) {
                pos[++DP[p]].insert(p);
                que.push(p); break;
            }
        }
        while (que.size()) {
            p = que.front(); que.pop();
            it = pos[DP[p]].upper_bound(p);
            lis = max(lis, DP[p]);
            while (it != pos[DP[p]].end()
            && A[*it] > A[p]) {
                pos[++DP[*it]].insert(*it);
                que.push(*it);
                it = pos[DP[p]].erase(it);
            }
        }
        cout << lis << '\n';
    }
}