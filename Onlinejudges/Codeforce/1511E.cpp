#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int N = 300005;

int add(int x, int y) {
    if ((x += y) >= MOD) x -= MOD;
    return x;
}

int mul(int x, int y) {
    return (long long)x * y % MOD;
}

int cnt[N][2], way[N][2], pw2[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int M, N; cin >> M >> N;
    pw2[0] = 1;
    for (int i = 0; i < M * N; i++)
        pw2[i + 1] = add(pw2[i], pw2[i]);
    vector <string> A(M);
    for (string &s : A) cin >> s;
    int res = 0, tot = 0;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            tot += A[i][j] == 'o';
    for (int i = 0; i < M; i++) {
        for (int j = 1; j <= N; j++) {
            cnt[j][0] = cnt[j][1] = 0;
            way[j][0] = way[j][1] = 0;
        }
        way[0][0] = 1; int cur = 0;
        for (int j = 0; j < N; j++) {
            if (A[i][j] == '*') {
                cnt[j + 1][0] = add(cnt[j][0], cnt[j][1]);
                way[j + 1][0] = add(way[j][0], way[j][1]);
            } else {
                cnt[j + 1][1] = cnt[j][0]; way[j + 1][1] = way[j][0]; cur++;
                cnt[j + 1][0] = add(add(cnt[j][1], way[j][1]), add(cnt[j][1], cnt[j][0]));
                way[j + 1][0] = add(add(way[j][1], way[j][0]), way[j][1]);
            }
        }
        res = add(res, mul(add(cnt[N][0], cnt[N][1]), pw2[tot - cur]));
    }
    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= M; j++) {
            cnt[j][0] = cnt[j][1] = 0;
            way[j][0] = way[j][1] = 0;
        }
        way[0][0] = 1; int cur = 0;
        for (int j = 0; j < M; j++)
            if (A[j][i] == '*') {
                cnt[j + 1][0] = add(cnt[j][0], cnt[j][1]);
                way[j + 1][0] = add(way[j][0], way[j][1]);
            } else {
                cnt[j + 1][1] = cnt[j][0]; way[j + 1][1] = way[j][0]; cur++;
                cnt[j + 1][0] = add(add(cnt[j][1], way[j][1]), add(cnt[j][1], cnt[j][0]));
                way[j + 1][0] = add(add(way[j][1], way[j][0]), way[j][1]);
            }
        res = add(res, mul(add(cnt[M][0], cnt[M][1]), pw2[tot - cur]));
    }
    cout << res;
}