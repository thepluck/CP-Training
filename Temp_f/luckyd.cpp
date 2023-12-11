#include <bits/stdc++.h>

using namespace std;

bool check(int x, int d) {
    while (x > 0) {
        if (x % 10 == d) return 1;
        x /= 10;
    }
    return 0;
}

bool dp[100005];

int main() {
    int d = 6; dp[0] = 1;
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= i; j++)
            if (check(j, d))
                dp[i] |= dp[i - j];
        if (dp[i]) cout << i << ", ";
    }
}