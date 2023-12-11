#include <bits/stdc++.h>
using namespace std;

const int N = 5e6 + 5;
using ll = long long;
int pre[N], mp[N];

void sieve(){
    iota(pre, pre + N, 0);
    for (int i = 2; i * i < N; i++)
        if (pre[i] == i)
            for (int j = i * i; j < N; j += i)
                pre[j] = min(pre[j], i);
}

void cal(int x){
    int seed = 1;
    while (x > 1){
        int t = pre[x], cnt = 0;
        while (x % t == 0){
            cnt++; x /= t;
        }
        if (cnt & 1) seed *= t;
    }
    mp[seed]++;
}

int main(){
    //freopen("SQUARE.inp", "r", stdin);
    //freopen("SQUARE.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n; sieve();
    for (int i = 1; i <= n; i++) cal(i);
    long long res = 0;
    for (int i = 1; i <= n; i++)
        res += 1ll * mp[i] * (mp[i] - 1) *
        (mp[i] - 2) / 6;
    cout << res << '\n';
}