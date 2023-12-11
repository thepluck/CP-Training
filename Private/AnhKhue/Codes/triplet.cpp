#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("triplet.in", "r", stdin);
    freopen("triplet.out", "w", stdout);
    int mina, maxa, minb, maxb, minc, maxc;
    cin >> mina >> maxa >> minb >> maxb >> minc >> maxc;
    int lim = sqrt(maxc); long long cnt = 0;
    for (int a = mina; a <= min(maxa, lim); a++) {
        int lowb = max(minb, (minc + a - 1) / a);
        int highb = min(maxb, maxc / a);
        if (lowb <= highb) cnt += highb - lowb + 1;
    }
    mina = max(mina, lim + 1);
    for (int b = minb; b <= min(maxb, lim); b++) {
        int lowa = max(mina, (minc + b - 1) / b);
        int higha = min(maxa, maxc / b);
        if (lowa <= higha) cnt += higha - lowa + 1;
    }
    cout << cnt << '\n';
}
