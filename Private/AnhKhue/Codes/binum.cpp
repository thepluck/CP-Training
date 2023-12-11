#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 1e5 + 5;

struct answer {
    int a, x, b, y;
};

int num[10][N];
int same[10];

bool compare(answer p, answer q) {
    if (p.a + p.b != q.a + q.b)
        return p.a + p.b < q.a + q.b;
    if (p.x != q.x) return p.x < q.x;
    if (p.a < q.a) return p.y < q.x;
    if (p.a > q.a) return p.x < q.y;
    return p.y < q.y;
}

int main() {
    freopen("binum.in", "r", stdin);
    freopen("binum.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        answer ans; ans.a = -1;
        for (int d = 1; d <= 9; d++) {
            same[d] = 0;
            for (int i = 0; i < n; i++)
                num[d][i] = -1;
        }
        for (int i = 1; i <= n; i++) {
            for (int d1 = 1; d1 <= 9; d1++) {
                same[d1] = (ll(same[d1]) * 10 + d1) % n;
                for (int d2 = 1; d2 <= d1; d2++)
                    if (num[d2][same[d1]] >= 0) {
                        answer cur;
                        cur.a = i - num[d2][same[d1]];
                        cur.x = d1; cur.y = d1 - d2;
                        cur.b = num[d2][same[d1]];
                        if (ans.a < 0) ans = cur;
                        else if (compare(cur, ans))
                            ans = cur;
                    }
                for (int d2 = 1; d2 <= 9 - d1; d2++)
                    if (num[d2][(n - same[d1]) % n] >= 0) {
                        answer cur;
                        cur.a = i - num[d2][(n - same[d1]) % n];
                        cur.x = d1; cur.y = d1 + d2;
                        cur.b = num[d2][(n - same[d1]) % n];
                        if (ans.a < 0) ans = cur;
                        else if (compare(cur, ans))
                            ans = cur;
                    }
            }
            for (int d = 1; d <= 9; d++)
                num[d][same[d]] = i;
        }
        cout << ans.a << ' ' << ans.x << ' ';
        cout << ans.b << ' ' << ans.y << '\n';
    }
}
