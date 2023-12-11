#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmax(X &a, const Y &b) {
    return a < b ? a = b, 1 : 0;
}

const int MAXN = 5005;
const int MAXV = 1000005;

int F[MAXN][MAXN][2];
int T[MAXN][MAXN][2];
int G[MAXN][2], last[MAXV];
int A[MAXN], B[MAXN];


int main() {
    cin.tie(0)->sync_with_stdio(0);
    int M, N; cin >> M >> N;
    for (int i = 1; i <= M; i++)
        cin >> A[i];
    for (int i = 1; i <= N; i++)
        cin >> B[i];
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++)
            last[B[j]] = N + 1;
        for (int j = N; j > 0; j--) {
            last[B[j]] = j;
            if (A[i] < B[j]) {
                if (cmax(F[i][last[A[i]]][0], G[j][1] + 1))
                    T[i][last[A[i]]][0] = j;
            } else if (A[i] > B[j]) {
                if (cmax(F[i][last[A[i]]][1], G[j][0] + 1))
                    T[i][last[A[i]]][1] = j;
            }
        }
        cmax(F[i][last[A[i]]][0], 1);
        cmax(F[i][last[A[i]]][1], 1);
        for (int j = 1; j <= N; j++) {
            cmax(G[j][0], F[i][j][0]);
            cmax(G[j][1], F[i][j][1]);
        }
    }
    vector <int> ans;
    int res = 0, ia = 0, ja = 0, ta = 0;
    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= N; j++) {
            if (cmax(res, F[i][j][0])) {
                ia = i; ja = j; ta = 0;
            }
            if (cmax(res, F[i][j][1])) {
                ia = i; ja = j; ta = 1;
            }
        }
    cout << res << '\n';
    while (res) {
        ans.push_back(A[ia]); res--;
        ja = T[ia][ja][ta]; ta = 1 - ta;
        while (ia && (A[ia] != B[ja]
        || F[ia][ja][ta] != res)) ia--;
    }
    reverse(ans.begin(), ans.end());
    for (int x : ans) cout << x << ' ';
}