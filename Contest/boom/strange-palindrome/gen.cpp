#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock
::now().time_since_epoch().count());

int rand(int l, int r) {
    return uniform_int_distribution <int> (l, r)(rng);
}

int main(int argc, char *argv[]) {
    int len = rand(1, 3000);
    while (len--) cout<< char('a' + rand(0, 25));
}
