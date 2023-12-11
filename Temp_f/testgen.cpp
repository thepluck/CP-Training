#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::high_resolution_clock
::now().time_since_epoch().count());

int rand(int l, int r) {
    return uniform_int_distribution <int> (l, r)(rng);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("input.txt", "w", stdout);
    int n = 5000; cout << n << '\n';
    for (int i = 1; i <= n; i++)
        cout << rand(1, 1000000000) << " \n"[i == n];
}