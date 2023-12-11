#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock
::now().time_since_epoch().count());

int rand(int l, int r) {
    return uniform_int_distribution <int> (l, r)(rng);
}

int main(int agrc, char *argv[]) {
    int MAXN = atoi(argv[1]);
    int X = rand(0, MAXN);
    int Y = rand(0, MAXN - X);
    int Z = rand(0, MAXN - X - Y);
    if (rng() & 1) swap(X, Y);
    if (rng() & 1) swap(Y, Z);
    if (rng() & 1) swap(X, Z);
    cout << X << ' ' << Y << ' ' << Z << '\n';
    for (int i = 0; i < X + Y + Z; i++) {
        cout << rand(1, 1e9) << ' ';
        cout << rand(1, 1e9) << ' ';
        cout << rand(1, 1e9) << '\n';
    }
}
