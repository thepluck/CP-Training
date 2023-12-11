#define forn(i) for (int i = 0; i <= 1; i++)
#include <bits/stdc++.h>
const long long base = 111539786;
struct matrix{
    long long c[2][2];
    matrix(int x, int y, int z, int t){
        c[0][0] = x; c[0][1] = y;
        c[1][0] = z; c[1][1] = t;
    }
    matrix operator * (matrix a){
        matrix b(0, 0, 0, 0);
        forn(i) forn(j) forn(k)
            b.c[i][j] = (b.c[i][j] + c[i][k] * a.c[k][j]) % base;
        return b;
    }
    matrix power(long long n){
        matrix res(1, 0, 0, 1);
        for (long long i = n; i; i >>= 1){
            if (i & 1) res = res * *this;
            *this = *this * *this;
        }
        return res;
    }
};

using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n; int t;
    cin >> t;
    while (t--){
        cin >> n; matrix a(0, 1, 1, 1);
        cout << a.power(n).c[1][1] << '\n';
    }
}
