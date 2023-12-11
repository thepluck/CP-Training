#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int rand(int l, int r) {
    return uniform_int_distribution <int> (l, r)(rng);
}

int main(int argc, char *argv[]) {
    cin.tie(0)->sync_with_stdio(0);
    int N = rand(50, 200);
    int B = rand(21, N - 1);
    int A = rand(1, B - 1);
    vector <pair <int, int>> match;
    for (int i = 1; i <= N; i++) {
        int arg = rand(0, 3);
        if ((arg & 1) && i > A)
            match.emplace_back(i - A, i);
        if ((arg >> 1 & 1) && i > B)
            match.emplace_back(i - B, i);
    }
    int M = match.size();
    cout << N << ' ' << M << ' ' << A << ' ' << B << '\n';
    for (auto m : match)
        cout << m.first << ' ' << m.second << '\n';
}
