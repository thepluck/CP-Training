#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv) {
    registerGen(argc, argv, 1);
    string subtask(argv[1]);
    int n;
    if (subtask == "sub1")
        n = rnd.next(450, 500);
    else if (subtask == "sub2")
        n = rnd.next(4900, 5000);
    else n = rnd.next(190000, 200000);
    vector<int> a(n); set<int> s;
    for (int i = 0; i < n; i++)
        while (s.count(a[i] = rnd.next(1, int(1e9))));
    shuffle(a.begin(), a.end());
    cout << n << '\n';
    for (int i = 0; i < n; i++)
        cout << a[i] << " \n"[i == n - 1];
}