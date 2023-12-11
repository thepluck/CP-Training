#include <bits/stdc++.h>

using namespace std;

struct node {int x, y, p;};

const int N = 12;

int a[N + 5][N + 5], n;
int dp[1 << (N << 1)];
char s[N + 5][N + 5];

bool bit(int mask, int p) {
    return mask >> p & 1;
}

int rec(int mask) {
    int &res = dp[mask];
    if (res >= 0) return res;
    int x = 0, y = 0, cntbl = 0, cntwh = 0;
    node black[15], white[15]; res = 1e9;
    for (int p = 0; p < 2 * n - 1; p++) {
        if (!bit(mask, p) && bit(mask, p + 1)) {
            res = min(res, rec(mask ^ (3 << p)) + a[x][y]);
            if (s[x][y] == 'B') black[cntbl++] = {x, y, p};
            if (s[x][y] == 'W') white[cntwh++] = {x, y, p};
        }
        if (bit(mask, p)) y++; else x++;
    }
    for (int i = 0; i < cntbl; i++) {
        int nmask = mask ^ (3 << black[i].p);
        int bx = black[i].x, by = black[i].y;
        for (int j = 0; j < cntwh; j++) {
            int nmask2 = nmask ^ (3 << white[j].p);
            int wx = white[j].x, wy = white[j].y;
            res = min(res, rec(nmask2) +
            abs(a[bx][by] - a[wx][wy]));
        }
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    memset(dp, -1, sizeof dp);
    dp[(1 << n) - 1] = 0;
    cout << rec(((1 << n) - 1) << n) << '\n';
}