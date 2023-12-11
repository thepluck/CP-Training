#include <bits/stdc++.h>

using namespace std;

#define popcnt __builtin_popcount
#define ctz __builtin_ctz

bool f[105][105];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int q; cin >> q;
    while (q--) {
        int u, v; cin >> u >> v;
        if (u > v) {
            cout << "NO\n"; continue;
        }
        int dif = popcnt(u) - popcnt(v);
        if (dif < 0) {
            cout << "NO\n"; continue;
        }
        bool flag = true;
        for (int i = 29; i >= 0; i--) {
            if (u >> i & 1) {
                if (!(v >> i & 1)) {
                    flag = false; break;
                }
            }    
            else {
                if (!(v >> i & 1)) continue;
                int id = -1;
                for (int j = i - 1; j >= 0; j--)
                    if (u >> j & 1) {
                        if (dif) {
                            u ^= 1 << j; dif--;
                        }
                        else {
                            id = j; break;
                        }
                    }
                if (id < 0) {
                    flag = false; break;
                }
                u ^= 1 << id;
                
            }
        }
        cout << (flag ? "YES\n" : "NO\n");
    }
}