#include "insects.h"
#include <bits/stdc++.h>
 
namespace {
    using namespace std;
 
    const int N = 2000;
 
    mt19937 rng(chrono::high_resolution_clock
    ::now().time_since_epoch().count());
 
    bool inside[N], dead[N]; int cnt;
    vector<int> ord;
 
    void insert(int i) {
        cnt++; inside[i] = 1;
        move_inside(ord[i]);
    }
 
    void erase(int i) {
        cnt--; inside[i] = 0;
        move_outside(ord[i]);
    }
 
}
 
int min_cardinality(int n) {
    ord.resize(n);
    iota(ord.begin(), ord.end(), 0);
    shuffle(ord.begin(), ord.end(), rng);
    for (int i = 0; i < n; i++) {
        insert(i);
        if (press_button() > 1) erase(i);
    }
    int t = cnt, l = 1, r = n / cnt;
    while (l < r) {
        int m = (l + r + 1) / 2;
        vector<int> add, remove;
        for (int i = 0; i < n; i++)
            if (!inside[i] && !dead[i]) {
                insert(i);
                if (press_button() > m) {
                    erase(i); remove.push_back(i);
                } else {
                    add.push_back(i);
                    if (cnt == m * t) break;
                }
            }
        if (cnt == m * t) l = m;
        else {
            r = cnt / t;
            for (int i : add) erase(i);
            for (int i : remove) dead[i] = 1;
        }
    }
    return l;
}