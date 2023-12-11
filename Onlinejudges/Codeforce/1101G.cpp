#include <bits/stdc++.h>
using namespace std;

struct basis_vectors{
    int basis[31], sz;
    
    void insert(int x){
        for (int i = 0; i < 31; i++){
            if (!(x >> i & 1)) continue;
            if (!basis[i]){
                basis[i] = x; sz++; return;
            }
            x ^= basis[i];
        }
    }

    int size() const {
        return sz;
    }

    void clear(){
        memset(basis, 0, sizeof basis);
    }
} bs;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, cur = 0; cin >> n;
    for (int i = 1, x; i <= n; i++){
        cin >> x; cur ^= x; bs.insert(cur);
    }
    if (!cur) cout << "-1\n";
    else cout << bs.size() << '\n';

}