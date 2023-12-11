#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 10000000007;
ll f[5005], g[5005];


int main(){
    int n, m, k; cin >> k >> m >> n;
    for (int i = 1; i < m; i++) f[i] = 1;
    for (int i = 2; i <= n; i++){
        for (int j = 1; j < m; j++){
            g[j] = 0; if (j > k) g[j] = f[j - k];
            if (j + k < m) g[j] = (g[j] + f[j + k]) % mod;
        }
        for (int j = 1; j < m; j++) f[j] = g[j];
    }
    cout << accumulate(f + 1, f + n, 0ll, [](const ll &a, const ll &b){
        return (a + b) % mod;
    });
}