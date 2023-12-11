#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000000;

int add(int x, int y) {
    if ((x += y) >= MOD) x -= MOD;
    return x;
}

int mul(int x, int y) {
    return (long long)x * y % MOD;
}

int sub(int x, int y) {
    if ((x -= y) < 0) x += MOD;
    return x;
}

using mat = array <array <int, 15>, 15>;

mat C;

void init(mat &x) {
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            x[i][j] = 0;
}

mat mul(const mat &x, const mat &y) {
    mat z; init(z);
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            for (int k = 0; k < 15; k++)
                z[i][j] = add(z[i][j],
                mul(x[i][k], y[k][j]));
    return z;
}

mat pow(mat x, long long k) {
    mat y; init(y);
    for (int i = 0; i < 15; i++)
        y[i][i] = 1;
    for (; k; k >>= 1, x = mul(x, x))
        if (k & 1) y = mul(y, x);
    return y;
}

int calc(long long n, int k) {
    mat x, y; init(x); init(y);
    for (int i = 0; i <= k; i++)
        for (int j = i; j <= k; j++)
            y[i][j] = C[i][j];
    for (int i = 0; i <= k; i++)
        y[i][k + 1] = C[i][k];
    y[k + 1][k + 1] = 1;
    for (int i = 0; i <= k + 1; i++)
        for (int j = 0; j <= k + 1; j++)
            cerr << y[i][j] << " \n"[j == k + 1];
    for (int i = 0; i <= k; i++)
        for (int j = 0; j <= i; j++)
            x[i][j] = 1 << i;
    x[k][k + 1] = 1 << (k + 1);
    for (int i = 0; i <= k + 1; i++)
        for (int j = 0; j <= k + 1; j++)
            cerr << x[i][j] << " \n"[j == k + 1];
    cerr << x[k][k + 1] << '\n';
    x = mul(x, y);
    for (int i = 0; i <= k + 1; i++)
        for (int j = 0; j <= k + 1; j++)
            cerr << x[i][j] << " \n"[j == k + 1];
    cerr << x[k][k + 1] << '\n';
    x = mul(x, y);
    for (int i = 0; i <= k + 1; i++)
        for (int j = 0; j <= k + 1; j++)
            cerr << x[i][j] << " \n"[j == k + 1];
    cerr << x[k][k + 1] << '\n';
    x = mul(x, y);
    for (int i = 0; i <= k + 1; i++)
        for (int j = 0; j <= k + 1; j++)
            cerr << x[i][j] << " \n"[j == k + 1];
    cerr << x[k][k + 1] << '\n';
    return x[k][k + 1];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 0; i < 15; i++)
        C[0][i] = 1;
    for (int i = 1; i < 15; i++)
        for (int j = i; j < 15; j++)
            C[i][j] = add(C[i][j - 1], C[i - 1][j - 1]);
    int t; cin >> t;
    while (t--) {
        long long n; int k, res = 0;
        cin >> n >> k;
        // for (int i = 0; i <= k; i++)
        //     if ((k - i) & 1)
        //         res = sub(res, mul(C[i][k], calc(n, i)));
        //     else res = add(res, mul(C[i][k], calc(n, i)));
        // cout << setw(9) << setfill('0') << res << '\n';
        calc(n ,k);
    }
}