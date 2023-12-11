#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock
::now().time_since_epoch().count());

int rand(int l, int r) {
    return uniform_int_distribution <int> (l, r)(rng);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    freopen("inp.txt", "w" ,stdout);
    int N = 2000; cout << N << '\n';
    for (int i = 2; i <= N; i++)
        cout << rand(1, i - 1) <<' ' << i << '\n';
    int D = rand(2, N / 4 - rand(0, 1)); cout << D << '\n';
}