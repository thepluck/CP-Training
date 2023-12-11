#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

using ll = long long;

const ll INF = 0x3f3f3f3f3f3f3f3f;

ll dp[2][17][17][17][2][2][3];
int nxt[3][17][10], kmp[17];

void buildKMP(string s, int nxt[17][10]) {
    int j = 0;
    for (int i = 0; i < s.size(); i++) {
        j = nxt[j][s[i] - '0'];
        nxt[i][s[i] - '0'] = i + 1;
        for (int c = 0; c < 10; c++)
            nxt[i + 1][c] = nxt[j][c];
    }
    for (int c = 0; c < 10; c++)
        nxt[s.size()][c] = s.size();
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n; string s[3];
    cin >> n >> s[0] >> s[1] >> s[2];
    reverse(s[0].begin(), s[0].end());
    reverse(s[1].begin(), s[1].end());
    reverse(s[2].begin(), s[2].end());
    sort(s, s + 3); ll res = INF;
    int sz[] = {s[0].size(), s[1].size(), s[2].size()};
    do {
        memset(nxt, 0, sizeof nxt);
        buildKMP(s[0], nxt[0]);
        buildKMP(s[1], nxt[1]);
        buildKMP(s[2], nxt[2]);
        memset(dp[0], 0x3f, sizeof dp[0]);
        ll pw = 1; bool cur = 0;
        dp[0][0][0][0][1][1][0] = 0;
        for (int i = 0; i < 16; i++) {
            cur ^= 1;
            memset(dp[cur], 0x3f, sizeof dp[cur]);
            for (int mat0 = 0; mat0 <= sz[0]; mat0++)
                for (int mat1 = 0; mat1 <= sz[1]; mat1++)
                    for (int mat2 = 0; mat2 <= sz[2]; mat2++)
                        for (int f01 = 0; f01 < 2; f01++)
                            for (int f12 = 0; f12 < 2; f12++)
                                for (int rem = 0; rem < 3; rem++)
                                    if (dp[cur ^ 1][mat0][mat1][mat2][f01][f12][rem] != INF)
                                        for (int c0 = 0; c0 < 10; c0++)
                                            for (int c1 = 0; c1 < 10; c1++) {
                                                int c2 = (n / pw % 10 - c0 - c1 - rem + 30) % 10;
                                                int newMat0 = nxt[0][mat0][c0];
                                                int newMat1 = nxt[1][mat1][c1];
                                                int newMat2 = nxt[2][mat2][c2];
                                                int newF01 = c0 != c1 ? c0 < c1 : f01;
                                                int newF12 = c1 != c2 ? c1 < c2 : f12;
                                                int newRem = (rem + c0 + c1 + c2) / 10;
                                                cmin(dp[cur][newMat0][newMat1][newMat2][newF01][newF12][newRem],
                                                dp[cur ^ 1][mat0][mat1][mat2][f01][f12][rem] + pw * (c2 - c0));
                                            }
            pw *= 10;
        }
        cmin(res, dp[0][sz[0]][sz[1]][sz[2]][1][1][0]);
    }
    while (next_permutation(s, s + 3));
    cout << (res > n ? -1 : res);
}