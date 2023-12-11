#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        for (int i = 0; i <= a - c; i++)
            cout << 1;
        for (int i = 1; i < c; i++)
            cout << 0;
        cout << " 1";
        for (int i = 1; i < b; i++)
            cout << 0;
        cout << '\n';
    }
}