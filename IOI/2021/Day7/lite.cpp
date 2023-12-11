#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

const int MAXN = 100005;
const int LOG = 17;
const int INF = 0x3f3f3f3f;

int F[MAXN], G[MAXN][LOG][LOG];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    memset(F, 0x3f, sizeof F);
    memset(G, 0x3f, sizeof G);
    F[0] = 0;
    for (int i = 1; i <= N; i++) {
        int x; cin >> x;
        if (x >= LOG) return cout << -1, 0;
        G[i][0][x] = 0;
        if (x > 0) G[i][0][x - 1] = 1;
        for (int j = 1; i >= (1 << j); j++) {
            for (int k = 0; k <= x; k++)
                cmin(G[i][j][k], G[i][j - 1][k] +
                G[i - (1 << (j - 1))][j - 1][k]);
            for (int k = 0; k < x; k++)
                cmin(G[i][j][k], G[i][j][k + 1] + 1);
        }
        for (int j = 0; i >= (1 << j); j++)
            cmin(F[i], G[i][j][0] + F[i - (1 << j)]);
    }
    cout << (F[N] == INF ? -1 : F[N]);
}