#include <bits/stdc++.h>
#include "inversion.h"

using namespace std;


const int N = 100005;

int BIT[N], pos[N], ans[N];

void update(int i, int v) {
    for (; i < N; i += i & -i) BIT[i] += v;
}

int getPos(int k) {
    int p = 0;
    for (int i = 1 << 17; i > 0; i >>= 1)
        if (p + i < N && BIT[p + i] < k) {
            p += i; k -= BIT[p];
        }
    return p + 1;
}

long long doswap2(int i, int j) {
    swap(pos[i], pos[j]);return doswap(i, j);
}

void play(int n, long long initial_inversion) {
    for (int i = 1; i <= n; i++) {
        pos[i] = i; update(i, 1);
    }
    int minId = 1;
    for (int i = 2; i <= n; i++) {
        long long new_inversion = doswap2(minId, i);
        if (new_inversion > initial_inversion) minId = i;
        initial_inversion = new_inversion;
    }
    ans[pos[minId]] = 1; update(1, -1);
    if (minId > 1) initial_inversion = doswap2(1, minId);
    bool side = 1; int low = 1, high = n;
    while (low < high) {
        long long new_inversion = doswap2(low, high);
        int dif = abs(new_inversion - initial_inversion) / 2;
        int val = getPos(dif + 1);
        if (side) {
            ans[pos[low]] = val; low++;
        }
        else {
            ans[pos[high]] = val; high--;
        }
        update(val, -1); side ^= 1;
        initial_inversion = new_inversion;
    }
    answer(ans);
}

