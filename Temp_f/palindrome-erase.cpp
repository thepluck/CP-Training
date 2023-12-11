#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int par[N]; int n = 1e6, col = n;

int find(int u) {
    return par[u] ? par[u] = find(par[u]) : u;
}

bool unite(int u, int v) {
    u = find(u); v = find(v);
    if (u != v) return par[v] = u;
    return 0;
}

void match(int p) {
    cout << p << '\n';
    for (int i = 1, j = n; i < j; i++, j--) {
        if (i == p) i++; if (j == p) j--;
        col -= unite(i, j);
    }
}

int main(int argc, char **argv) {
    registerGen(argc, argv, 1);
    match(rnd.next(1, n / 2));
    match(rnd.next(1, n / 2));
    match(rnd.next(n / 2 + 1, n));
    match(rnd.next(n / 2 + 1, n));
    cout << col << '\n';
}