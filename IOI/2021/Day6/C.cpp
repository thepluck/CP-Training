#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1234567890;

long long DP[2][1500][2];
int U[1500][2], W[1500];
vector <int> adj[50];

void add(long long &x, long long y) {
    if ((x += y) >= MOD) x -= MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) {
        int N, M, K, D;
        cin >> N >> M >> K >> D; K--;
        for (int i = 0; i < M; i++) {
            cin >> U[0][i] >> U[1][i] >> W[i];
            DP[0][i][0] = DP[0][i][1] = 1;
            adj[U[i][0]].push_back(i);
            adj[U[i][1]].push_back(i);
        }
        for (int p = 1; p <= K; p++) {
            memset(DP[1], 0, sizeof DP[1]);
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < 2; j++)
                    for (int k : adj[U[i][j]])
                        if (abs(W[i] - W[k]) >= D)
                            add(DP[1][k][U[i][j] == U[k][0]], DP[0][i][j]);
            }
            swap(DP[0], DP[1]);
        }
        long long res = 0;
        for (int i = 0; i < M; i++) {
            add(res, DP[0][i][0]); add(res, DP[0][i][1]);
        }
        cout << res << '\n';
    }
}