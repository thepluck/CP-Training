#include <bits/stdc++.h>

using namespace std;

int a[100005];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    int cnt[] = {0, 0};
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; cnt[a[i]]++;
    }
    while (q--) {
        int t, k; cin >> t >> k;
        if (t == 1) {
            cnt[a[k]]--; cnt[a[k] ^= 1]++;
        }
        else {
            if (cnt[1] >= k) cout << "1\n";
            else cout << "0\n";
        }
    }
}