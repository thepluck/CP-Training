#include <bits/stdc++.h>
using namespace std;

const int N = 20;

int a[1 << N], b[1 << N];
int x[1 << N], y[1 << N];
vector <int> ans; int n, k;

void rec(int l, int r, int h) {
    if (l >= r) return;
    if (h == 2 * n + 1) return;
    int cl = 0, cr = 0;
    int m = (l + r) / 2;
    for (int i = l; i < r; i++)
        if (a[i] < b[m]) {
            x[cl++] = a[i];
            cout << h << ' ';
            cout << h + 1 << ' ';
        }
    for (int i = l; i < r; i++)
        if (a[i] >= b[m]) {
            if (cl < m - l) {
                x[cl++] = a[i];
                cout << h << ' ';
                cout << h + 1 << ' ';
            }
            else {
                y[cr++] = a[i];
                cout << h << ' ';
            }
        }
    for (int i = 0; i < cl; i++)
        a[l + i] = x[i];
    reverse(y, y + cr);
    for (int i = 0; i < cr; i++)
        a[m + i] = y[i];
    rec(l, m, h + 2);
    for (int i = 0; i < cr; i++)
        cout << h + 1 << ' ';
    rec(m, r, h + 2);
}

int main() {
    //freopen("sqsort.inp", "r", stdin);
    //freopen("sqsort.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> a[i]; b[i] = a[i];
    }
    cout << k * 2 * n << '\n';
    sort(b, b + k); rec(0, k, 1);
    
}