#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back

const int N = 100005;

int a[N], dp[N];
vector <int> r[N];

int reduce(int i, int v) {
    int d = v - a[i];
    if (d < 0 || d >= r[i].size()) return -1;
    return r[i][d];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; ++i <= n; ) {
        cin >> a[i]; int v = a[i];
        r[i].eb(i - 1); dp[i] = i;
        while (~reduce(r[i].back(), v))
            r[i].eb(reduce(r[i].back(), v++));
        for (int j : r[i])
        	dp[i] = min(dp[i], dp[j] + 1);
    }
    cout << dp[n] << '\n';
}