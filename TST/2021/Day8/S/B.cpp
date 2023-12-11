#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

long long dp[200];

int main() {
    memset(dp[0], 0x3f, sizeof dp[0]);
}