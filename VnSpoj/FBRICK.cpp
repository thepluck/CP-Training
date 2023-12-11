#include <bits/stdc++.h>
using namespace std;


pair <int, int> test;
int n, mod;

struct modular{
    int val;
    modular(): val(0){}
    template <class T>
    modular(T x): val(x % mod){
        if (val < 0) val += mod;
    }
};

modular operator + (const modular &a, const modular &b){
    return modular(a.val + b.val);
}

modular operator * (const modular &a, const modular &b){
    return modular(1ll * a.val * b.val);
}

void operator *= (modular &a, const modular &b){
    a = a * b;
}

void operator += (modular &a, const modular &b){
    a = a + b;
}

struct matrix{
    int n, m; vector <vector <modular>> c;
    matrix(){}
    matrix(int n, int m): n(n), m(m){
        c.resize(n + 1, vector <modular> (m + 1));
    }
    vector <modular>& operator [] (int i){
        return c[i];
    }
};

matrix operator * (matrix a, matrix b){
    matrix c(a.n, b.m);
    for (int i = 1; i <= a.n; i++)
        for (int j = 1; j <= b.m; j++)
            for (int k = 1; k <= a.m; k++)
                c[i][j] += a[i][k] * b[k][j];
    return c;
}

matrix fast_pow(matrix a, int x){
    matrix res(a.m, a.m);
    for (int i = 1; i <= a.m; i++) res[i][i] = 1;
    for (; x > 0; x >>= 1){
        if (x & 1) res = res * a; a = a * a;
    }
    return res;
}

void solve(){
    int x; cin >> x >> n >> mod;
    matrix a(4, 1), b(4, 4);
    a[1][1] = modular(1ll * x * x + 1);
    a[2][1] = modular(1ll * x * x);
    a[3][1] = modular(1);
    a[4][1] = modular(x);
    b[1][1] = b[1][3] = b[2][3] = b[3][2] = modular(1);
    b[1][2] = b[2][2] = modular(4) * modular(1ll * x * x);
    b[1][4] = b[2][4] = modular(-4) * modular(x);
    b[4][2] = modular(2) * modular(x);
    b[4][4] = modular(-1);
    a = fast_pow(b, n - 2) * a;
    cout << a[1][1].val << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--) solve();
}