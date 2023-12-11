#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x; res += x;
    }
    cout << -res;
}