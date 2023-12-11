#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock
::now().time_since_epoch().count());

int rand(int l, int r) {
    return uniform_int_distribution <int> (l, r)(rng);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N = 20, Q = 100;
    cout << 1 << '\n' << N << ' ' << Q << '\n';
    for (int i = 2; i <= N; i++)
        cout << rand(1, i - 1) << ' ' << i << '\n';
    while (Q--) {
        int r = rand(1, N);
        int s = rand(1, N);
        int t = rand(1, N);
        cout << r << ' ' << s << ' ' << t << '\n';
    }
}