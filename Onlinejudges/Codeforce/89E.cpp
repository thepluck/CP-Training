#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int a[N], b[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    while (!a[n]) n--;
    int res = INT_MAX, pos = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            b[j] = a[j] - (j >= i && a[j]);
        int cost = -i;
        for (int j = 1; j <= n; j++)
            cost += 3 * b[j] + 2 * max(0, b[j] - b[j - 1]);
        if (res > cost) {
            res = cost; pos = i;
        }
    }
    for (int i = 1; i <= n; i++)
        b[i] = a[i] - (i >= pos && a[i]);
    for (int i = 1; i <= n; i++) {
        while (b[i]) {
            int j = i;
            for (; b[j]; j++) {
                cout << "AR"; b[j]--;
            }
            cout << 'A';
            for (int k = 1; k <= j - i; k++)
                cout << 'L';
            cout << 'A';
        }
        cout << "AR";
    }
    cout << 'A';
    for (int i = 0; i <= n - pos; i++)
        cout << 'L';
    cout << "A\n";
}