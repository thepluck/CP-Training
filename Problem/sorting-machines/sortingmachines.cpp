#include <bits/stdc++.h>

using namespace std;

const int N = 200005;
const int LOG = 18;

int a[N], r[N], rmq[LOG][N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> s;
    a[0] = a[n + 1] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; rmq[0][i] = a[i];
    }
    s.push_back(n + 1);
    long long res = 1ll * n * (n + 1) / 2;
    for (int i = n; i > 0; i--) {
        while (a[s.back()] > a[i]) s.pop_back();
        r[i] = s.back(); s.push_back(i);
    }
    for (int k = 1; k < LOG; k++)
        for (int i = (1 << k); i <= n; i++)
            rmq[k][i] = max(rmq[k - 1][i],
            rmq[k - 1][i - (1 << (k - 1))]);
    s.clear(); s.push_back(0);
    for (int i = 1; i <= n; i++) {
        while (a[s.back()] > a[i]) s.pop_back();
        int j = s.back();
        for (int k = LOG - 1; k >= 0; k--)
            if (j >= (1 << k) && rmq[k][j] < a[i])
                j -= 1 << k;
        res += 1ll * (r[i] - i) * (s.back() - j);
        s.push_back(i);
    }
    cout << res;
}