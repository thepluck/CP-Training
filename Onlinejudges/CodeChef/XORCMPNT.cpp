
// Problem : Bitsetbaba and Power Grid
// Contest : CodeChef - May Cook-Off 2019 Division 1
// URL : https://www.codechef.com/COOK106A/problems/XORCMPNT
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

const int LG = 30;

struct basis {
    int span[LG], dim;
    
    void reset() {
        memset(span, 0, sizeof span);
        dim = 0;
    }
    
    basis() {
        reset();
    }
    
    void insert(int x) {
        for (int i = 0; i < LG; i++) {
            if (!(x >> i & 1)) continue;
            if (!span[i]) {
                span[i] = x; dim++;
            }
            x ^= span[i];
        }
    }
} bs;

void solve() {
    int k, n; cin >> k >> n;
    while (n--) {
        int x; cin >> x; bs.insert(x);
    }
    cout << (1 << (k - bs.dim)) << '\n';
    bs.reset();
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
}