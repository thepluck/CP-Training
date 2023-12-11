#include "cave.h"
#include <cstring>
#include <iostream>

const int N = 5010;

int S[N], D[N];

void exploreCave(int n) {
    memset(D, -1, sizeof D);
    for (int i = 0; i < n; i++) {
        int lo = 0, hi = n - 1, v = 0;
        for (int j = 0; j < n; j++)
            if (D[j] < 0) S[j] = 0;
        int x = tryCombination(S);
        if (x < 0 || x > i) v = 1;
        while (lo < hi) {
            int mi = (lo + hi) / 2;
            for (int j = 0; j <= mi; j++)
                if (D[j] < 0) S[j] = v;
            for (int j = mi + 1; j < n; j++)
                if (D[j] < 0) S[j] = v ^ 1;
            x = tryCombination(S);
            if (x < 0 || x > i) lo = mi + 1;
            else hi = mi;
        }
        D[hi] = i; S[hi] = v ^ 1;
    }
    answer(S, D);
}