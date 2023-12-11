#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;
const int BASE = 337;
const int MOD = 1000003057;


int Add(int x, int y) {
    if ((x += y) >= MOD) x -= MOD;
    return x;
}

int Sub(int x, int y) {
    if ((x -= y) < 0) x += MOD;
    return x;
}

int Mul(int x, int y) {
    return (long long)x * y % MOD;
}

int A[3][MAXN], B[MAXN], lo, hi;
int has[MAXN * 4]; char tag[MAXN * 4];
set <int> poss;
int idx[256], N, Q; string T;
const string chr = "JOI";
int sum[MAXN], pw[MAXN];

void build(int i, int l, int r) {
    if (l == r) has[i] = Mul(pw[l + 1], T[l]);
    else {
        int m = (l + r) / 2;
        build(i * 2, l, m);
        build(i * 2 + 1, m + 1, r);
        has[i] = Add(has[i * 2], has[i * 2 + 1]);
    }
}

void apply(int i, int l, int r, char c) {
    if (c) {
        has[i] = Mul(Sub(sum[r + 1], sum[l]), c);
        tag[i] = c;
    }
}

void push(int i, int l, int r) {
    int m = (l + r) / 2;
    apply(i * 2, l, m, tag[i]);
    apply(i * 2 + 1, m + 1, r, tag[i]);
    tag[i] = 0;
}

void update(int i, int l, int r, char c) {
    if (l >= lo && r <= hi)
        return apply(i, l, r, c);
    push(i, l, r); int m = (l + r) / 2;
    if (m >= lo) update(i * 2, l, m, c);
    if (m < hi) update(i * 2 + 1, m + 1, r, c);
    has[i] = Add(has[i * 2], has[i * 2 + 1]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);  
    cin >> N;
    idx['J'] = 0; idx['O'] = 1; idx['I'] = 2;
    pw[0] = sum[0] = 1;
    for (int i = 1; i <= N; i++) {
        pw[i] = Mul(pw[i - 1], BASE);
        sum[i] = Add(sum[i - 1], pw[i]);
    }
    for (int i = 0; i < 3; i++) {
        string S; cin >> S;
        for (int j = 0; j < N; j++)
            A[i][j] = idx[S[j]];
    }
    for (int r = 0; r < 3; r++)
        for (int i = -2; i <= 2; i++)
            for (int j = -2; j <= 2; j++)
                for (int k = -2; k <= 2; k++) {
                    if (i + j + k < 0 || i + j + k > 1) continue;
                    for (int x = 0; x < N; x++) {
                        B[x] = A[r][x] + A[0][x] * i + A[1][x] * j + A[2][x] * k;
                        if (i + j + k == 1) B[x] = -B[x];
                        B[x] = (B[x] % 3 + 3) % 3;
                    }
                    long long val = 0;
                    for (int x = 0; x < N; x++)
                        val = Add(val, Mul(pw[x + 1], chr[B[x]]));
                    poss.insert(val);
                }
    cin >> Q >> T; build(1, 0, N - 1);
    if (poss.count(has[1]))
        cout << "Yes\n";
    else cout << "No\n";
    while (Q--) {
        char c; cin >> lo >> hi >> c;
        lo--; hi--; update(1, 0, N - 1, c);
        if (poss.count(has[1]))
            cout << "Yes\n";
        else cout << "No\n";
    }
}