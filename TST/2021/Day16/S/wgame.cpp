#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 32;
const int L = 11;

ll dp[N][N][N][N][L][4];
int nxt[L][26], chr[N][N], k;

void kmp(const string &s) {
    k = s.size();
    for (int i = 0, j = 0; i < k; i++) {
        j = nxt[j][s[i] - 'A'];
        nxt[i][s[i] - 'A'] = i + 1;
        for (int c = 0; c < 26; c++)
            nxt[i + 1][c] = nxt[j][c];
    }
    for (int c = 0; c < 26; c++)
        nxt[k][c] = k;
}

ll calc(int x, int y, int z, int t, int l, int d) {
    ll &res = dp[x][y][z][t][l][d];
    if (res >= 0) return res;
    if (d == 0) {
        int p = y;
        if (x == z) {
            while (p <= t)
                l = nxt[l][chr[x][p++]];
            return res = l == k;
        }
        while (p <= t) {
            l = nxt[l][chr[x][p]];
            res += calc(x + 1, p, z, y, l, 1);
            p++;
        }
        return ++res;
    }
    else if (d == 1) {
        int p = x;
        if (y == t) {
            while (p <= z)
                l = nxt[l][chr[p++][y]];
            return res = l == k;
        }
        while (p <= z) {
            l = nxt[l][chr[p][y]];
            res += calc(p, y - 1, x, t, l, 2);
            p++;
        }
        return ++res;
    }
    else if (d == 2) {
        int p = y;
        if (x == z) {
            while (p >= t)
                l = nxt[l][chr[x][p--]];
            return res = l == k;
        }
        while (p >= t) {
            l = nxt[l][chr[x][p]];
            res += calc(x - 1, p, z, y, l, 3);
            p--;
        }
        return ++res;
    }
    else {
        int p = x;
        if (y == t) {
            while (p >= z)
                l = nxt[l][chr[p--][y]];
            return res = l == k;
        }
        while (p >= z) {
            l = nxt[l][chr[p][y]];
            res += calc(p, y + 1, x, t, l, 0);
            p--;
        }
        return ++res;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    string s; cin >> s; kmp(s);
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++)
            chr[i][j] = s[j] - 'A';
    }
    memset(dp, -1, sizeof dp);
    cout << calc(0, 0, n - 1, m - 1, 0, 0);
}