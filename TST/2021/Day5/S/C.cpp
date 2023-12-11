#include <bits/stdc++.h>

using namespace std;

short cnt[10];

bool isGood(long long x) {
    memset(cnt, 0, sizeof cnt);
    while (x > 0) {
        cnt[x % 10]++; x /= 10;
    }
    for (int d = 0; d < 10; d++)
        if (cnt[d] > 1) return 0;
    return 1;
}

int main() {
    freopen("squares.inp", "r", stdin);
    freopen("squares.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    vector <long long> goodSqr;
    for (int i = 1; i <= 100000; i++)
        if (isGood(1ll * i * i))
            goodSqr.push_back(1ll * i * i);
    long long k; cin >> k;
    if (k > goodSqr.size())
        cout << "-1";
    else cout << goodSqr[k - 1];
}