#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll n, m, p;

int main(){
    cin >> n >> m; p = n * m;
    while (p > n) 
        p += (p - n - 1) / (m - 1) - n;
    cout << p << '\n';
}