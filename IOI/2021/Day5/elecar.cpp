#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

using ll = long long;

const int MAXN = 1005;
const ll INF = 0x3f3f3f3f3f3f3f3f;

ll DP[2][MAXN][MAXN * 2];
int A[MAXN], B[MAXN], C[MAXN];
int nxt[MAXN][MAXN * 2];
vector <pair <int, int>> S[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    memset(DP[0], 0x3f, sizeof DP[0]);
    DP[0][1][0] = 0;
    for (int i = 1; i <= N; i++)
        cin >> A[i] >> B[i] >> C[i];
    int W, P; cin >> W >> P;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int D = abs(A[i] - A[j]) + abs(B[i] - B[j]);
            if (D <= W) {
                S[i].emplace_back(D, j);
                S[i].emplace_back(W - D, j + N);
            }
        }
        sort(S[i].begin(), S[i].end());
        for (int j = 0; j < S[i].size(); j++)
            if (S[i][j].se > N)
                nxt[S[i][j].se - N][i] = j;
    }
    for (int i = 1; i <= P; i++) {
        memset(DP[i & 1], 0x3f, sizeof DP[i & 1]);
        for (int u = 1; u <= N; u++) {
            for (int j = 0; j + 1 < S[u].size(); j++) {
                cmin(DP[~i & 1][u][j + 1], DP[~i & 1][u][j] +
                ll(S[u][j + 1].fi - S[u][j].fi) * C[u]);
                if (S[u][j].se <= N)
                    cmin(DP[i & 1][S[u][j].se][0], DP[~i & 1][u][j]);
            }
            for (int v = 1; v <= N; v++)
                if (abs(A[u] - A[v]) + abs(B[u] - B[v]) <= W)
                    cmin(DP[i & 1][v][nxt[u][v]],
                    DP[~i & 1][u][S[u].size() - 1]);
        }
    }
    cout << (DP[P & 1][2][0] == INF ? -1 : DP[P & 1][2][0]);
}