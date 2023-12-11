#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock
::now().time_since_epoch().count());

int rand(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N = 10; cout << N << "\n";
    for (int i = 1; i <= N; i++)
        cout << rand(1, 20) << ' ' << rand(1, 20) << '\n';
}