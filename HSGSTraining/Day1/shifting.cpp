#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;
int a[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    iota(a, a + n + 1, 0);
    for (int k = 2; k <= n; k++) {
        int last = 0;
        for (int i = k - 1; i < k + n - 1; i += k)
            swap(a[i], last);
        swap(last, a[n + k - 1]);
    }
    for (int i = n; i < 2 * n; i++)
        cout << a[i] << " \n"[i == 2 * n - 1];
}