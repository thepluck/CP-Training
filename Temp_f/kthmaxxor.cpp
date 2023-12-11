#include <bits/stdc++.h>
using namespace std;

struct xor_vectors{
    int basis[32], sz;
    bool insert(int x){
        for (int i = 31; i >= 0; i--)
            if (x >> i & 1){
                if (!basis[i]){
                    basis[i] = x; sz++; return 1;
                }
                else x ^= basis[i];
            }
        return 0;
    }
    int order(int k){
        int x = 0, tot = 1 << sz;
        for (int i = 31; i >= 0; i--)
            if (basis[i]){
                tot >>= 1;
                if (tot < k){
                    if (!(x >> i & 1)) x ^= basis[i];
                    k -= tot;
                }
                else if (x >> i & 1) x ^= basis[i];
            }
        return x;
    }
} vs;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int q, cmd, k; cin >> q;
    while (q--){
        cin >> cmd >> k;
        if (cmd == 1) vs.insert(k);
        else cout << vs.order(k) << '\n';
    }
}