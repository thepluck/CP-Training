#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, c, b; cin >> n >> c >> b;
    vector<int> a(n, -1);
    for (int i = 0; i < b; i++) {
        int p; cin >> p; a[p - 1] = 0;
    }
    a[0] = c & 1;
    for (int i = 1; i < n; i++) {
        if (a[i] < 0) {
            if (c == 1 || c == 0) a[i] = a[i - 1];
            else if (c > 0) a[i] = a[i - 1] ^ 1;
        }
        if (a[i] != a[i - 1]) c--;
    }
    for (int x : a) cout << x;
}