#include <bits/stdc++.h>
using namespace std;

const int V = 1e7 + 5;
const int N = 1e6 + 5;

int fi[V], se[V], a[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (fi[a[i]]) se[a[i]] = i;
        else fi[a[i]] = i;
    }
    int ai = 0, aj = 0;
    long long res = LLONG_MAX;
    for (int i = 1; i < V; i++) {
        int x = 0, y = 0;
        for (int j = i; j < V; j += i) {
            if (x && y) break;
            if (fi[j]) {
                if (x) y = fi[j];
                else {
                    x = fi[j];
                    if (se[j]) y = se[j];
                }
            }
        }
        if (!x || !y) continue;
        if (res > 1ll * a[x] * a[y] / i) {
            res = 1ll * a[x] * a[y] / i;
            ai = x; aj = y;
        }
    }
    if (ai > aj) swap(ai, aj);
    cout << ai << ' ' << aj << '\n';
}
