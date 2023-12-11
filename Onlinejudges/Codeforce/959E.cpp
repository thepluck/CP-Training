
// Problem : E. Mahmoud and Ehab and the xor-MST
// Contest : Codeforces - Codeforces Round #473 (Div. 2)
// URL : https://codeforces.com/contest/959/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, res = 0; cin >> n; n--;
    for (long long i = 1; i <= n; i <<= 1)
        res += ((n - i) / (i * 2) + 1) * i;
    cout << res << '\n';
}