#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    int l = n / 2;
    string m, k;
    for (int i(0); i < n / 2; i++) {
        m += "C."; k += ".C";
    }
    if (n % 2 == 1) {
        m += "C"; k += ".";
        cout << pow(l, 2) + pow(l + 1, 2) << '\n';
        for (int j = 0; j < l; j++) {
            cout << m << '\n' << k << '\n';
        }
        cout << m << '\n';
    } else {
        cout << n * n / 2 << '\n';
        for (int j = 0; j < l; j++) {
            cout << m << '\n' << k << '\n';
        }
    }
    return 0;
}