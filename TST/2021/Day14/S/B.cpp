#include <bits/stdc++.h>

using namespace std;

bool isPrime(int x) {
    if (x == 1) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}

int main() {
    freopen("primes.inp", "r", stdin);
    freopen("primes.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    if (n == 1) cout << -1;
    else if (isPrime(n)) cout << 1;
    else if (~n & 1) cout << 2;
    else if (isPrime(n - 2)) cout << 2;
    else cout << 3;
    cout << " " << (n == 1 ? -1 : n / 2);
}