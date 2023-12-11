#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int LG = 20;

int lg[N], sp[LG][N], to[N];

int que(int i, int j) {
    int k = lg[j - i + 1];
    return sp[k][i] | sp[k][j + 1 - (1 << k)];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> sp[0][i];
        sp[0][i + n] = sp[0][i];
    }
    for (int i = 2; i <= 2 * n; i++)
        lg[i] = lg[i / 2] + 1;
    for (int k = 1; k < LG; k++)
        for (int i = 0; i + (1 << k) <= 2 * n; i++)
            sp[k][i] = sp[k - 1][i] | sp[k - 1][i + (1 << k - 1)];
    int res = 0;
    for (int b = 30; ~b; b--) {
        res ^= 1 << b; bool ok = 0;
        for (int i = 0, j = 0; i < n * 2; i++) {
            j = max(i, j);
            while (j < 2 * n && (que(i, j) & res) != res) j++;
            to[i] = j;
        }
        for (int i = 0; i < n; i++)
            if (to[i] - i < n / m && to[i] < 2 * n) {
                for (int j = i; j <= to[i]; j++) {
                    int cnt = 0;
                    for (int k = j; k < 2 * n; k++) {
                        if (cnt == m) break;
                        if ((k = to[k]) - j < n) cnt++;
                        else break;
                    }
                    if (cnt == m) ok = 1;
                }
                break;
            }
        if (!ok) res ^= 1 << b;
    }
    cout << res << '\n';
}