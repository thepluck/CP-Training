#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int a[N]; long long x[N], y[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n; bool flag = 1;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        x[1] = a[1]; y[1] = 0;
        for (int i = 2; i <= n; i++)
            if (a[i] > a[i - 1]) {
                y[i] = y[i - 1] + a[i] - a[i - 1];
                x[i] = x[i - 1];
            }
            else {
                x[i] = x[i - 1] + a[i] - a[i - 1];
                y[i] = y[i - 1];
            }
        x[n + 1] = 0; y[n + 1] = 1e18;
        for (int i = 1; i <= n; i++) {
            if (x[i] < x[i + 1] || x[i] < 0) flag = 0;
            if (y[i] > y[i + 1] || y[i] < 0) flag = 0;
        }
        cout << (flag ? "YES\n" : "NO\n");
    }
}