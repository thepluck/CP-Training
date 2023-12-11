#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int lp[N], cnt[N];

void sieve(){
    iota(lp + 2, lp + N, 2);
    for (int i = 2; i * i < N; i++)
        if (lp[i] == i)
            for (int j = i * i; j < N; j += i)
                lp[j] = min(lp[j], i);
}

int code(int x){
    int res = 1;
    while (x > 1){
        int cnt = 0, t = lp[x];
        while (x % t == 0){
            x /= t; cnt++;
        }
        if (cnt & 1) res *= t;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); sieve();
    int n; cin >> n;
    long long res = 0;
    for (int i = 1; i <= n; i++)
        cnt[code(i)]++;
    for (int i = 1; i <= n; i++)
        res += 1ll * cnt[i] * (cnt[i] - 1) *
                    (cnt[i] - 2) / 6;
    cout << res << '\n';
}