#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 4000005;
int pre[N], phi[N]; ll f[N];

void pre_calc(){
    for (int i = 1; i < N; i++) phi[i] = i;
    for (int i = 2; i < N; i++)
        if (phi[i] == i)
            for (int j = i; j < N; j += i)
                phi[j] -= phi[j] / i;
    for (int i = 1; i < N; i++)
        for (int j = 2 * i; j < N; j += i)
            f[j] = f[j] + 1ll * i * phi[j / i];
    for (int i = 1; i < N; i++) f[i] += f[i - 1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    pre_calc(); int n;
    while (cin >> n){
        if (n == 0) return 0; 
        cout << f[n] << '\n';
    }

}