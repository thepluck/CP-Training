#include <bits/stdc++.h>

using namespace std;

const int N = 300005;
const int MOD = 1e9 + 7;

int a[N], lef[N], rig[N], n;

int add(int x, int y) {
    return (x += y) >= MOD ? x - MOD : x;
}

int mul(int x, int y) {
    return (long long)x * y % MOD;
}


int sub(int x, int y) {
    return (x -= y) < 0 ? x + MOD : x;
}

int solve(int l, int m, int r) {
    if (!m) return 1;
    int ansl = solve(l, lef[m], m);
    int ansr = solve(m, rig[m], r);
    int ans = mul(ansl, ansr);
    if (l) ans = add(ans, ansr);
    if (r) ans = add(ans, ansl);
    if (l && r) ans = sub(ans, 1);
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n; stack<int> stk;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        while (stk.size() && a[i] < a[stk.top()]) {
            lef[i] = stk.top(); stk.pop();
        }
        if (stk.size()) rig[stk.top()] = i;
        stk.push(i);
    }
    int m = 0;
    while (stk.size()) {
        m = stk.top(); stk.pop();
    }
    cout << solve(0, m, 0);
}