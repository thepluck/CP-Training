#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, x, res = 0;
        cin >> n;
        while (n--) {
            cin >> x;
            if (x == 1 || x == 3) res++;
        }
        cout << res << '\n';
    }
}