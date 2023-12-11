#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

void gen1(int t, int n, vector<int> &a) {
    vector<int> par = rnd.partition(rnd.wnext(1, n, -t), n);
}

void gen2(int t, int n, vector<int> &a) {

}

int main(int argc, char **argv) {
    registerGen(argc, argv, 1);
    int subtask = opt<int> ("subtask");
    int n, d = subtask > 3, x, y;
    if (subtask == 1) {
        n = rnd.wnext(6, 3); x = 2; y = 0;
    } else if (subtask == 2) {
        n = rnd.wnext(200, 20); x = 10; y = 5; 
    } else if (subtask == 3) {
        n = rnd.wnext(2000, 50); x = 20; y = 10;
    } else if (subtask == 4) {
        n = rnd.wnext(200, 20); x = 10; y = 5;
    } else {
        n = rnd.wnext(2000, 50); x = 20; y = 10;
    }
    int m = rnd.next(0, n);
    vector<int> a;
}