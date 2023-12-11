#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2000005;

int L[MAXN], R[MAXN];
int A[MAXN], P[MAXN];
int takeL[MAXN], takeR[MAXN];
int res = 0;

void remove(int u, int &cnt) {
    cnt--;
    if (L[u]) remove(L[u], cnt);
    if (R[u]) remove(R[u], cnt);
    if (u == L[P[u]]) L[P[u]] = 0;
    else R[P[u]] = 0;
}

int compute(int u) {
    int cnt = 1;
    takeL[u] = takeR[u] = u;
    if (L[u]) {
        P[L[u]] = u;
        cnt += compute(L[u]);
        takeL[u] = takeL[L[u]];
        int v = takeR[L[u]];
        while (v != u && A[v] >= A[u]) {
            remove(v, cnt); v = P[v];
        }
        if (!L[u]) takeL[u] = u;
    }
    if (R[u]) {
        P[R[u]] = u;
        cnt += compute(R[u]);
        takeR[u] = takeR[R[u]];
        int v = takeL[R[u]];
        while (v != u && A[v] <= A[u]) {
            remove(v, cnt); v = P[v];
        }
        if (!R[u]) takeR[u] = u;
    }
    res = max(res, cnt);
    return cnt;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N >> N;
    for (int i = 1; i <= N; i++)
        cin >> L[i] >> R[i] >> A[i];
    compute(1); cout << res << '\n';
}