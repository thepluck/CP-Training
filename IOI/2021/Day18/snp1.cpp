#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;
const int SQRT = 350;
const int MOD = 1000000007;

void add(int &x, int y) {
    if ((x += y) >= MOD) x -= MOD;
}

void sub(int &x, int y) {
    if ((x -= y) < 0) x += MOD;
}

int DP[SQRT][MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, res = 0; cin >> N;
    DP[0][0] = 1;
    for (int i = 1; i < SQRT; i++) {
        for (int j = i; j <= N; j++) {
            add(DP[i][j], DP[i - 1][j - i]);
            add(DP[i][j], DP[i][j - i]);
        }
        add(res, DP[i][N]);
        for (int j = i; j <= N; j++)
            sub(DP[i][j], DP[i - 1][j - i]);
    }
    cout << res << '\n';
}