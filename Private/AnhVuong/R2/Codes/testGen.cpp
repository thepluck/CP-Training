#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int rand(int from, int to) {
    return uniform_int_distribution <int> (from, to)(rng);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
}