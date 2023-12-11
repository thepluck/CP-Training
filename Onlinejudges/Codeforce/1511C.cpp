#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    vector <int> idx(100);
    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        if (!idx[t]) idx[t] = i;
    }
    while (q--) {
        int t; cin >> t;
        cout << idx[t] << ' ';
        for (int c = 1; c <= 50; c++)
            if (idx[c] < idx[t]) idx[c]++;
        idx[t] = 1;
    }
}