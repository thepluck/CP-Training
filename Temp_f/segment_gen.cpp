#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

void rec(int l, int r, vector<int> id,
vector<int> &len, vector<int> &pos) {
    if (id.empty()) return;
    if (l == r) {
        for (int i : id) pos[i] = l;
        return;
    }
    double ratio = rnd.next(1.0);
    vector<int> lef, rig;
    int m = (l + r) / 2;
    for (int i : id)
        if (len[i] < m && rnd.next(1.0) > ratio)
            lef.push_back(i);
        else rig.push_back(i);
    rec(l, m, lef, len, pos);
    rec(m + 1, r, rig, len, pos);
}

int main(int argc, char **argv) {
    registerGen(argc, argv, 1);
    string subtask(argv[1]);
    int n, q, k;
    if (subtask == "sub1") {
        k = 1;
        n = rnd.wnext(2, 2000, 20);
        q = rnd.wnext(1, 2000, 20);
    } else if (subtask == "sub2") {
        k = 1;
        n = rnd.wnext(2, 100000, 20);
        q = rnd.wnext(1, 100000, 20);
    } else if (subtask == "sub3") {
        k = 2;
        n = rnd.wnext(2, 100000, 20);
        q = rnd.wnext(1, 100000, 20);
    } else if (subtask == "sub4") {
        n = rnd.wnext(2, 100000, 20);
        q = rnd.wnext(1, 100000, 20);
        k = rnd.wnext(1, min(n, 30), 5);
    } else {
        n = rnd.wnext(2, 100000, 20);
        q = rnd.wnext(1, 100000, 20);
        k = rnd.wnext(1, n, 20);  
    }
    cout << n << ' ' << q << ' ' << k << '\n';                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
    vector<int> len(n), pos(n);
    for (int i = 0; i < n; i++)
        len[i] = rnd.next(1, 500);
    vector<int> id(n);
    iota(id.begin(), id.end(), 0);
    rec(2, 1000000000, id, len, pos);
    shuffle(id.begin(), id.end());
    for (int i : id)
        cout << pos[i] - len[i] << ' ' << pos[i] << '\n';
    while (q--) {
        int d = rnd.next(2, 1000000000);
        int c = rnd.next(1, d - 1);
        cout << c << ' ' << d << '\n';
    }
}