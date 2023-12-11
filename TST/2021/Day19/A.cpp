#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

const int N = 2e5 + 5;

int nxt[N][26], dp[N];
char str[N];
pair <int, int> tr[N];

int main() {
    string str; cin >> str;
    int n = str.size();
    for (int c = 0; c < 26; c++)
        nxt[n][c] = n;
    dp[n] = 1; dp[n + 1] = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int c = 0; c < 26; c++)
            nxt[i][c] = nxt[i + 1][c];
        nxt[i][str[i] - 'a'] = i;
        dp[i] = n + 1;
        for (int c = 0; c < 26; c++)
            cmin(dp[i], dp[nxt[i][c] + 1] + 1);
    }
    int i = 0;
    while (i < n) {
        for (int c = 0; c < 26; c++)
            if (dp[i] == dp[nxt[i][c] + 1] + 1) {
                cout << char(c + 'a');
                i = nxt[i][c] + 1; break;
            }
    }
}