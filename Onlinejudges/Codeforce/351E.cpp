#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector <int> a(n);
    for (int &x : a) {
        cin >> x; if (x < 0) x = -x;
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        int x = 0, y = 0;
        for (int j = 0; j < n; j++)
            if (a[j] < a[i]) {
                if (j < i) x++;
                else y++;
            }
        res += min(x, y);
    }
    cout << res;
}