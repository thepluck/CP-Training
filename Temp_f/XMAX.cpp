#include <bits/stdc++.h>
using namespace std;

using ll = long long;
struct xor_vectors{
    ll basis[64]; int bs_sz;
    bool insert(ll mask){
        bool flag = false;
        for (int i = 63; i >= 0; i--){
            if (!(mask >> i & 1)) continue;
            if (!basis[i]){
                basis[i] = mask; flag = 1;
            }
            mask ^= basis[i];
        }
        bs_sz += flag; return flag;
    }
    ll order(int k){

    }
    ll get_max(){
        ll res = 0;
        for (int i = 63; i >= 0; i--){
            if (!basis[i]) continue;
            if (res >> i & 1) continue;
            res ^= basis[i];
        }
        return res;
    }
} vs;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; ll x; cin >> n;
    while (n--){
        cin >> x; vs.insert(x);
    }
    cout << vs.get_max() << '\n';
}