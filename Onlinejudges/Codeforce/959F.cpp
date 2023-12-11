#include <bits/stdc++.h>
using namespace std;

struct gauss{
    int bs[21], sz;

    void insert(int x) {
        for (int i = 20; ~i; i--) {
            if (!(x >> i & 1))
                continue;
            if (!bs[i]) {
                bs[i] = x; sz++;
            }
            x ^= bs[i];
        }
    }

    bool is_comb(int x) {
        for (int i = 20; ~i; i--)
            if (x >> i & 1)
                x ^= bs[i];
        return x == 0;
    }

    int size() const {
        return sz;
    }
    
    void reset() {
        memset(bs, 0, sizeof bs);
    }
};

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

gauss bs[N]; int pw[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    pw[0] = 1;
    for (int i = 1; i <= n; i++) {
        pw[i] = pw[i - 1] * 2;
        if (pw[i] >= MOD)
            pw[i] -= MOD;
        int x; cin >> x;
        bs[i] = bs[i - 1];
        bs[i].insert(x);
    }
    while (q--) {
        int l, x; cin >> l >> x;
        if (bs[l].is_comb(x))
            cout << pw[l - bs[l].sz];
        else cout << 0;
        cout << '\n';
    }
}