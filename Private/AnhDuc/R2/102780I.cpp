#include <bits/stdc++.h>

using namespace std;

bool ask(int x1, int y1, int x2, int y2, int x3, int y3) {
    cout << "? 3 " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ' << x3 << ' ' << y3 << endl;
    string ans; cin >> ans; return ans[0] == 'Y';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    int lo = 1, hi = n;
    while (lo < hi) {
        int mi = (lo + hi + 1) / 2;
        if (ask(mi, 1, mi, 2 * n - 1, 2 * n - 1, 1)) lo = mi;
        else hi = mi - 1;
    }
    int x = lo;
    lo = 1; hi = n;
    while (lo < hi) {
        int mi = (lo + hi + 1) / 2;
        if (ask(1, mi, 2 * n - 1, mi, 1, 2 * n - 1)) lo = mi;
        else hi = mi - 1;
    }
    int y = lo;
    cout << "! " << x << ' ' << y << endl;
}