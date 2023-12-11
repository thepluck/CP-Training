#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int p[N], a[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x; p[x] = i;
    }
    if (n % 4 == 0) {
        a[1] = 1; a[2] = 3; a[3] = 2;
        for (int i = 4; i + 4 <= n; i += 4) {
            a[i] = i; a[i + 1] = i + 1;
            a[i + 2] = i + 3; a[i + 3] = i + 2;
        }
        a[n] = n;
    }
    else if (n % 4 == 1) {
        for (int i = 1; i + 4 <= n; i += 4) {
            a[i] = i; a[i + 1] = i + 1;
            a[i + 2] = i + 3; a[i + 3] = i + 2;
        }
        a[n] = n;
    }
    else if (n % 4 == 2) {
        for (int i = 2; i + 4 <= n; i += 4) {
            a[i - 1] = i; a[i] = i + 1;
            a[i + 1] = i + 3; a[i + 2] = i + 2;
        }
        a[n - 1] = n; a[n] = 1;
    }
    else if (n % 4 == 3) {
        for (int i = 3; i + 4 <= n; i += 4) {
            a[i - 2] = i; a[i - 1] = i + 1;
            a[i] = i + 3; a[i + 1] = i + 2;
        }
        a[n - 2] = 1; a[n - 1] = 2; a[n] = n;
    }
    for (int i = 1; i <= n; i++)
        cout << p[a[i]] << ' ';
}