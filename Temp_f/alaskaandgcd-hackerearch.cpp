#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int mod = 1e9 + 7;
int phi[N], f[N], bit[N], a[N], n;

void pre_calc(){
    for (int i = 1; i < N; i++) phi[i] = i;
    for (int i = 2; i < N; i++)
        if (phi[i] == i)
            for (int j = i; j < N; j += i)
                phi[j] -= phi[j] / i;
    for (int i = 1; i < N; i++)
        for (int j = i; j < N; j += i)
            f[j] = (f[j] + 1ll * i * phi[j / i]) % mod;
}

void update(int i, int val){
    for (; i <= n; i += i & -i){
        bit[i] = (bit[i] + val) % mod;
        if (bit[i] < 0) bit[i] += mod;
    }
}

int get_sum(int i){
    int res = 0;
    for (; i > 0; i -= i & -i)
        res = (res + bit[i]) % mod;
    return res;
}

int get_sum(int l, int r){
    return (get_sum(r) - get_sum(l - 1) + mod) % mod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    pre_calc(); cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i]; update(i, f[a[i]]);
    }
    int q, u, v; cin >> q; char cmd;
    while (q--){
        cin >> cmd >> u >> v;
        if (cmd == 'C') 
            cout << get_sum(u, v) << '\n';
        else {
            update(u, f[v] - f[a[u]]); a[u] = v;
        }
    }
}