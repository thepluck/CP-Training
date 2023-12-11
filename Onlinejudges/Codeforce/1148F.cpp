
// Problem : F. Foo Fighters
// Contest : Codeforces - Codeforces Global Round 3
// URL : https://codeforces.com/contest/1148/problem/F
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

int hb[N], val[N];
long long mask[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    long long res = 0, sum = 0;
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> val[i] >> mask[i];
        sum += val[i]; hb[i] = 61;
        while ((1ll << hb[i])
        > mask[i]) hb[i]--;
    }
    if (sum < 0) {
        for (int i = 1; i <= n; i++)
            val[i] = -val[i];
    }
    for (int b = 0; b <= 61; b++) {
        sum = 0;
        for (int i = 1; i <= n; i++)
            if (hb[i] == b)
                sum += val[i];
        if (sum > 0) {
            res += 1ll << b;
            for (int i = 1; i <= n; i++)
                if (mask[i] >> b & 1)
                    val[i] = -val[i];
        }
    }
    cout << res << '\n';
}