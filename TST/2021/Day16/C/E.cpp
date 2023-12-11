#include <bits/stdc++.h>

using namespace std;

const int N = 105;

string s, t;
int a[N], b[N], cnt[4];

int decode(char c) {
    if (c == 'A') return 0;
    if (c == 'C') return 1;
    if (c == 'G') return 2;
    if (c == 'T') return 3;
}

void solve() {
    int n = s.size();
    for (int i = 0; i < n; i++) {
        a[i + 1] = (decode(s[i])
        - decode(t[i]) + 4) % 4;
        b[i] = (a[i + 1] - a[i] + 4) % 4;
    }
    b[n] = (4 - a[n]) % 4;
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i <= n; i++) cnt[b[i]]++;
    int res = cnt[0] + cnt[2] / 2;
    int cur = min(cnt[1], cnt[3]);
    res += cur; cnt[1] -= cur; cnt[3] -= cur;
    cur = max(cnt[1], cnt[3]);
    res += cur / 4; if (cur % 4) res++;
    cout << n + 1 - res << '\n';
}

int main() {
    while (cin >> s >> t) solve();
}