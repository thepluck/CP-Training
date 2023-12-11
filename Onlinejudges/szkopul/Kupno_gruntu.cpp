#include <bits/stdc++.h>

using namespace std;

const int N = 3005;
const int INF = 2e9 + 1;

int sum[N][N];
int up[N], lef[N], k, n;

int get(int x1, int y1, int x2, int y2) {
    return sum[x2][y2] - sum[x1 - 1][y2] -
    sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}

void check(int x1, int y1, int x2, int y2) {
    if (get(x1, y1, x2, y2) < k) return;
    if (get(x1, y1, x2, y2) > 2 * k) {
        if (x1 < x2) {
            check(x1, y1, x2 - 1, y2);
            check(x2, y1, x2, y2);
        } else {
            check(x1, y1, x2, y2 - 1);
            check(x1, y2, x2, y2);
        }
    }
    cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
    exit(0);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> k >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> sum[i][j];
            if (sum[i][j] >= k && sum[i][j] <= k * 2) {
                cout << i << ' ' << j << ' ' << i << ' ' << j << '\n';
                return 0;
            }
            if (sum[i][j] < k) up[j]++; else up[j] = 0;
            sum[i][j] += sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
        }
        vector<int> stk; stk.push_back(0);
        for (int j = 1; j <= n; j++) {
            while (stk.size() > 1 && up[j] <= up[stk.back()]) stk.pop_back();
            lef[j] = stk.back() + 1; stk.push_back(j);
        }
        stk.clear(); stk.push_back(n + 1);
        for (int j = n; j >= 1; j--) {
            while (stk.size() > 1 && up[j] <= up[stk.back()]) stk.pop_back();
            check(i - up[j] + 1, lef[j], i, stk.back() - 1); stk.push_back(j);
        }
    }
    cout << "NIE\n";
}