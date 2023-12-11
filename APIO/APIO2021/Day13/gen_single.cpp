#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock
::now().time_since_epoch().count());

int rand(int l, int r) {
    return uniform_int_distribution <int> (l, r)(rng);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N = rand(90000, 100000);
    int M = rand(90000, 100000);
    int Q = rand(90000, 100000);
    cout << N << ' ' << M << ' ' << Q << '\n';
    while (M--) {
        int u = rand(1, N), v = rand(1, N);
        cout << u << ' ' << v << '\n';
    }
    while (Q--) {
        int u = rand(1, N), v = rand(1, N);
        if (u > v) swap(u, v);
        cout << u << ' ' << v << '\n';
    }
}