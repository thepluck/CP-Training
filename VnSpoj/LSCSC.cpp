#include <bits/stdc++.h>
using namespace std;

using ll = long long;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int rand(int l, int r) {
    return uniform_int_distribution <int> (l, r)(rng);
}

mt19937_64 rngll(chrono::high_resolution_clock::now().time_since_epoch().count());

ll rand(ll l, ll r) {
    return uniform_int_distribution <ll> (l, r)(rngll);
}

const int N = 2e5 + 5;
int a[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n; n *= 2;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int t = 0; t < 100; t++) {
        int x = rand(1, n - 1), d, fi;
        if (x < n) {
            d = 0;
            int y = x + 1, cnt = 0;
            for (int i = x; i > 0; i--)
                if (a[i] == a[x] - d) {
                    d += a[y] - a[x];
                    cnt++; fi = a[i];
                }
            d = 0;
            for (int i = y; i <= n; i++)
                if (a[i] == a[y] + d) {
                    d += a[y] - a[x];
                    cnt++;
                }
            if (cnt >= n / 2) {
                cout << fi << ' ';
                cout << a[y] - a[x] << '\n';
                return 0;
            }
        }
        if (x + 1 < n) {
            d = 0;
            int y = x + 2, cnt = 0;
            for (int i = x; i > 0; i--)
                if (a[i] == a[x] - d) {
                    d += a[y] - a[x];
                    cnt++; fi = a[i];
                }
            d = 0;
            for (int i = y; i <= n; i++)
                if (a[i] == a[y] + d) {
                    d += a[y] - a[x];
                    cnt++;
                }
            if (cnt >= n / 2) {
                cout << fi << ' ';
                cout << a[y] - a[x] << '\n';
                return 0;
            }
        }
        if (x + 2 < n) {
            d = 0;
            int y = x + 3, cnt = 0;
            for (int i = x; i > 0; i--)
                if (a[i] == a[x] - d) {
                    d += a[y] - a[x];
                    cnt++; fi = a[i];
                }
            d = 0;
            for (int i = y; i <= n; i++)
                if (a[i] == a[y] + d) {
                    d += a[y] - a[x];
                    cnt++;
                }
            if (cnt >= n / 2) {
                cout << fi << ' ';
                cout << a[y] - a[x] << '\n';
                return 0;
            }
        }
    }
}