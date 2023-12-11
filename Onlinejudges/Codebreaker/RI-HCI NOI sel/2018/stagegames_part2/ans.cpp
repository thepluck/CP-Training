#include "stagegames.h"
#include <bits/stdc++.h>

using namespace std;

namespace {
    const int N = 505;

    int a[N], p[N];
}

void play1(int n) {

}

void play2(int n) {
    memset(a, 0, sizeof a);
    p[0] = 1; p[1] = n;
    for (int i = 2; i < n; i++)
        p[i] = i;
    int pre = ask2(p);
    p[0] = n; p[1] = 1;
    int nex = ask2(p);
    a[1] = (nex - pre) / 2;
    for (int i = 2; i < n; i += 2) {
        memset(p, 0, sizeof p);
        if (i + 1 < n) {
            if (a[i - 1] > 0) {
                p[i - 1] = 2;
                p[i] = 1; p[i + 1] = n;
                int ptr = 3;
                for (int j = 0; j < n; j++)
                    if (!p[j]) p[j] = ptr++;
                pre = ask2(p);
                swap(p[i], p[i + 1]);
                nex = ask2(p);
                a[i + 1] = (nex - pre) / 2;
                if (a[i + 1] > 0) {
                    p[i - 1] = n;
                    p[i] = 1; p[i + 1] = 2;
                    nex = ask2(p);
                    a[i] = (nex - pre) / 2 - a[i + 1];
                } else {
                    swap(p[i - 1], p[i]);
                    pre = nex; nex = ask2(p);
                    a[i] = (nex - pre) / 2;
                }
            } else {
                p[i - 2] = 2;
                p[i] = 1; p[i + 1] = n;
                int ptr = 3;
                for (int j = 0; j < n; j++)
                    if (!p[j]) p[j] = ptr++;
                pre = ask2(p);
                swap(p[i], p[i + 1]);
                nex = ask2(p);
                a[i + 1] = (nex - pre) / 2;
                if (a[i + 1] > 0) {
                    p[i - 2] = n;
                    p[i] = 1; p[i + 1] = 2;
                    nex = ask2(p);
                    a[i] = (nex - pre) / 2 - a[i + 1] - a[i - 1];
                } else {
                    swap(p[i - 2], p[i]);
                    pre = nex; nex = ask2(p);
                    a[i] = (nex - pre) / 2 - a[i - 1];
                }
            }
        } else {
            p[i - 1] = 1; p[i] = n;
            int ptr = 2;
            for (int j = 0; j < n; j++)
                if (!p[j]) p[j] = ptr++;
            pre = ask2(p);
            swap(p[i], p[i - 1]);
            nex = ask2(p);
            a[i] = (nex - pre) / 2;
        }
    }
    int sh = 0;
    for (int i = 1; i < n; i++) {
        a[i] += a[i - 1];
        sh = min(sh, a[i]);
    }
    for (int i = 0; i < n; i++)
        a[i] -= sh - 1;
    answer(a);
}