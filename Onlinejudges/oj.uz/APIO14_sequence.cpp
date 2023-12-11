#include <bits/stdc++.h>
 
template <class X, class Y>
bool cmax(X &a, const Y &b) {
    return a < b ? a = b, 1 : 0;
}
 
using namespace std;
 
using ll = long long;
 
const int N = 100005, K = 205;
 
ll S[N], Dp[2][N]; int Opt[K][N];
 
void Dnc(int k, int l, int r, int optl, int optr) {
    int m = (l + r) / 2;
    for (int i = optl; i <= min(m, optr); i++)
        if (cmax(Dp[k & 1][m], Dp[~k & 1][i - 1] +
        S[i - 1] * (S[m] - S[i - 1]))) Opt[k][m] = i;
    if (l < m) Dnc(k, l, m - 1, optl, Opt[k][m]);
    if (m < r) Dnc(k, m + 1, r, Opt[k][m], optr);
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> S[i]; S[i] += S[i - 1];
    }
    for (int i = 1; i <= k; i++) {
        memset(Dp[i & 1], 0xc0, sizeof Dp[i & 1]);
        Dnc(i, i + 1, n, i + 1, n);
    }
    cout << Dp[k & 1][n] << '\n';
    stack <int> st;
    while (k)
        cout << (n = Opt[k--][n] - 1) << ' ';
}