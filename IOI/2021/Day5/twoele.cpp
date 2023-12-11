#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmax(X &a, const Y &b) {
    return a < b ? a = b, 1 : 0;
}

const int MAXN = 1000005;

long long res = 0;
vector <int> lef, rig;
int A[MAXN];

long long cal(int i, int j) {
    return 1ll * (A[i] + A[j]) * (j - i);
}

void dnc(int l, int r, int optl, int optr) {
    int optm; long long best = -1;
    int m = (l + r) / 2;
    for (int i = optl; i <= optr; i++)
        if (cmax(best, cal(lef[m], rig[i])))
            optm = i;
    cmax(res, best);
    if (l < m) dnc(l, m - 1, optl, optm);
    if (m < r) dnc(m + 1, r, optm, optr);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        if (i == 1 || A[i] > A[lef.back()])
            lef.push_back(i);
    }
    for (int i = N; i > 0; i--)
        if (i == N || A[i] > A[rig.back()])
            rig.push_back(i);
    reverse(rig.begin(), rig.end());
    dnc(0, lef.size() - 1, 0, rig.size() - 1);
    cout << res;
}