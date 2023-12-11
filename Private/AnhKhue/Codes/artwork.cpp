#include <bits/stdc++.h>

using namespace std;

int cnt[25];

int main() {
    freopen("artwork.in", "r", stdin);
    freopen("artwork.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n, m, res = 0; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        cnt[x]++; res += x;
    }
    for (int i = 1; i <= m; i++) {
        int x; cin >> x;
        if (cnt[x]) cnt[x]--;
        else res += x;
    }
    cout << res << '\n';
}
