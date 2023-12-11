#include <bits/stdc++.h>

using namespace std;

const int N = 200005;
const int M = 600005;

int a[N], b[N], x[M], y[M], n, m;

bool check(int k) {
    for (int i = 1; i <= n; i++)
        b[i] = a[i];
    for (int i = 1; i <= k; i++)
        swap(b[x[i]], b[y[i]]);
    for (int i = 1; i <= n; i++)
        while (b[i] != i) {
            int x = b[i]; k--;
            swap(b[i], b[x]);
        }
    return k >= 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (is_sorted(a + 1, a + n + 1)) 
        cerr << "bruh\n";
    else cerr << "yeah\n";
    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> x[i] >> y[i];
    int lo = 1, hi = m + 1;
    while (lo < hi) {
        int mi = (lo + hi) / 2;
        if (check(mi)) hi = mi;
        else lo = mi + 1;
    }
    if (hi == m + 1) cout << "-1\n";
    else cout << hi << '\n';
}
