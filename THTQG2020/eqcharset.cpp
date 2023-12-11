#include <bits/stdc++.h>
using namespace std;

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

const int N = 50005;
const int AL = 26;

long long cnt[1 << AL];
char s[N], t[N];
int nxt[N][AL];

int main() {
#ifdef LightUpTheFire
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // LightUpTheFire
    cin >> s >> t;
    int n = strlen(s), m = strlen(t);
    for (int c = 0; c < 26; c++)
        nxt[n][c] = n;
    for (int i = n - 1; ~i; i--) {
        for (int c = 0; c < 26; c++)
            nxt[i][c] = nxt[i + 1][c];
        nxt[i][s[i] - 'A'] = i;
        int mask = 1 << (s[i] - 'A');
        int cur = i;
        while (true) {
            int pos = n;
            for (int c = 0; c < 26; c++)
                if (!(mask >> c & 1))
                    cmin(pos, nxt[cur][c]);
            cnt[mask] += pos - cur;
            if (pos == n) break;
            mask += 1 << (s[pos] - 'A');
            cur = pos;
        }
    }
    long long res = 0;
    for (int c = 0; c < 26; c++)
        nxt[m][c] = m;
    for (int i = m - 1; ~i; i--) {
        for (int c = 0; c < 26; c++)
            nxt[i][c] = nxt[i + 1][c];
        nxt[i][t[i] - 'A'] = i;
        int mask = 1 << (t[i] - 'A');
        int cur = i;
        while (true) {
            int pos = m;
            for (int c = 0; c < 26; c++)
                if (!(mask >> c & 1))
                    cmin(pos, nxt[cur][c]);
            res += cnt[mask] * (pos - cur);
            if (pos == m) break;
            mask += 1 << (t[pos] - 'A');
            cur = pos;
        }
    }
    cout << res << '\n';
}
