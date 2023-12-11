#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
int pre[N + 5];

void prime_sieve(){
    for (int i = 1; i <= N; i++) pre[i] = i;
    for (int i = 2; i * i <= N; i++)
        if (pre[i] == i)
            for (int j = i * i; j <= N; j += i)
                if (pre[j] == j) pre[j] = i;
}

int fastexp(int a, int b){
    int res = 1;
    for (; b > 0; b >>= 1){
        if (b & 1) res *= a; a *= a;
    }
    return res;
}

int etf(int x){
    int res = 1;
    while (x > 1){
        int p = pre[x], cnt = 0;
        while (x % p == 0){
            cnt++; x /= p;
        }
        res *= (p - 1) * fastexp(p, cnt - 1);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t, x; cin >> t; 
    prime_sieve();
    while (t--){
        cin >> x; cout << etf(x) << '\n';
    }
}