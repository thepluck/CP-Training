#include <bits/stdc++.h>

using namespace std;

int p[10], res = 0, n;

void rec(int i, int j) {
    if (i == n) {
        if (p[i] == 0) res++; return;
    }
    if ((n - j + 1) * 3 < p[i]) return;
    if (j == n) {
        if (p[i] == 0 && p[j] >= 3) {
            p[j] -= 3; rec(i + 1, i + 2); p[j] += 3;
        }
        if (p[i] == 1 && p[j] > 0) {
            p[j]--; rec(i + 1, i + 2); p[j]++;
        }
        if (p[i] == 3) rec(i + 1, i + 2); return;
    }
    if (p[j] >= 3) {
        p[j] -= 3; rec(i, j + 1); p[j] += 3;
    }
    if (p[i] >= 3) {
        p[i] -= 3; rec(i, j + 1); p[i] += 3;
    }
    if (p[i] > 0 && p[j] > 0) {
        p[i]--; p[j]--; rec(i, j + 1); p[i]++; p[j]++;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int test = 0;
    while (cin >> n) {
        if (n == 0) break; res = 0;
        cout << "Case #" << ++test << ": ";
        for (int i = 1; i <= n; i++) cin >> p[i];
        rec(1, 2); cout << res << '\n';
    }
}
