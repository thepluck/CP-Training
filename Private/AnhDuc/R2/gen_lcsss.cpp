#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock
::now().time_since_epoch().count());

int randInt(int l, int r) {
    return uniform_int_distribution <int> (l, r)(rng);
}

const int maxLength = 100000;
const int maxDiff = 1000;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int m = randInt(1, maxLength);
    int num_swap = randInt(0, maxDiff);
    int num_insert = randInt(0, maxDiff);
    int num_erase = randInt(0, min(m +
    num_insert, maxDiff - num_insert));
    vector <int> a(m);
    for (int &x : a) x = randInt(1, maxDiff);
    vector <int> b = a;
    while (num_swap--) {
        int i = randInt(0, m - 1);
        int j = randInt(0, m - 1);
        swap(a[i], a[j]);
    }
    while (num_insert--) {
        int i = randInt(0, a.size() - 1);
        a.insert(a.begin() + i, randInt(1, maxDiff));
    }
    while (num_erase--) {
        int i = randInt(0, a.size() - 1);
        a.erase(a.begin() + i);
    }
    int n = a.size();
    cout << m << ' ' << n << '\n';
    for (int &x : b) cout << x << ' ';
    cout << '\n';
    for (int &x : a) cout << x << ' ';
}
