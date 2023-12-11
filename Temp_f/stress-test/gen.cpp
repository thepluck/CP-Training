#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int rand(int l, int r) {
    return uniform_int_distribution<int> (l, r)(rng);
}

int main() {
    int n = 2, m = 2;
    cout << n << ' ' << m << '\n';
    while (n--) {
        cout << rand(1, 10) << ' ';
        cout << rand(1, 50) << ' ';
        cout << rand(-10, 10) << '\n';
    }
    while (m--) {
        cout << rand(1, 10) << ' ';
        cout << rand(1, 50) << ' ';
        cout << rand(-10, 10) << '\n';
    }
}
