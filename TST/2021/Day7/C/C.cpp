#include <bits/stdc++.h>
#include "grader.h"

using namespace std;

void Rescue(int r, int c, int rs, int cs, int x) {
    int u = rs, v = 1;
    while (u >= 1 && v <= cs) {
        int y = Measure(u, v);
        if (x > y) v++;
        else if (x < y) u--;
        else Pinpoint(u, v);
    }
    u = r; v = cs;
    while (u >= rs && v >= 1) {
        int y = Measure(u, v);
        if (x > y) u--;
        else if (x < y) v--;
        else Pinpoint(u, v);
    }
    u = rs; v = c;
    while (u <= r && v >= cs) {
        int y = Measure(u, v);
        if (x > y) v--;
        else if (x < y) u++;
        else Pinpoint(u, v);
    }
    u = 1; v = cs;
    while (u <= rs && v <= c) {
        int y = Measure(u, v);
        if (x > y) u++;
        else if (x < y) v++;
        else Pinpoint(u, v);
    }
}