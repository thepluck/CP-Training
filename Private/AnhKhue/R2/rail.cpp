#include <bits/stdc++.h>

using namespace std;

int C2(int x) {
    return x * (x - 1) / 2;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    /// all
    long long sall = 0;
    for (int d = 0; d <= n; d++)
        for (int s = 3 * d; s <= n; s += 2)
            sall += C2((s - 3 * d) / 2 + 2);
    for (int d = 1; d <= n; d++)
        for (int s = 3 * d; s <= n; s += 2)
            sall += C2((s - 3 * d) / 2 + 2);
    /// 3-period
    long long s3 = 0;
    for (int s = 0; s <= n; s += 2)
        s3 += C2(s / 2 + 2);
    /// 2-period
    long long s2 = 0;
    for (int d = -n; d <= n; d++)
        if (n >= abs(3 * d))
            s2 += (n - abs(3 * d)) / 6 + 1;
    /// 1-period
    long long s1 = n / 6 + 1;
    cout << (sall - s2 - s3 + s1) +
    (s3 - s1) / 3 + (s2 - s1) / 2 + s1 << '\n';
}