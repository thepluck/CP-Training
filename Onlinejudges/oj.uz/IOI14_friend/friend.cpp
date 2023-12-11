#include "friend.h"

int findSample(int n, int confidence[], int host[], int protocol[]) {
    long long res = 0;
    for (int u = n - 1; u > 0; u--) {
        int v = host[u];
        if (protocol[u] == 0) {
            confidence[v] -= confidence[u];
            if (confidence[v] < 0)
                confidence[v] = 0;
            res += confidence[u];
        } else if (protocol[u] == 1) {
            confidence[v] += confidence[u];
        } else if (confidence[u] > confidence[v]) {
            confidence[v] = confidence[u];
        }
    }
    return res + confidence[0];
}
