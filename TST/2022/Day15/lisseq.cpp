#include <bits/stdc++.h>

using namespace std;

void solve(int x) {
    if (x <= 7) {
        for (int i = 0; i < 100 - 2 * x; i++)
            cout << 100 << ' ';
        for (int i = x; i > 0; i--)
            cout << 2 * i - 1 << ' ' << 2 * i << ' ';
        cout << '\n';
    } else {
        int cur = 30, ptr = 0;
        vector<int> ans(1, cur);
        int i = 30;
        while (~x >> i & 1) i--;
        for (int j = i - 1; j >= 0; j--) {
            ans.push_back(cur + 1);
            ans.push_back(cur + 1);
            cur++;
            if (x >> j & 1) {
                while (ptr <= i - j)
                    ans.push_back(ptr++);
            }
        }
        for (int i = 0; i < 100 - ans.size(); i++)
            cout << 100 << ' ';
        for (int x : ans) cout << x << ' ';
        cout << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int l, r, n;
    while (cin >> l >> r >> n)
        for (int i = l; i <= r; i++) solve(i);
}