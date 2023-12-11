#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
int pre[N];

void sieve(){
    iota(pre + 2, pre + N, 2);
    for (int i = 2; i * i < N; i++)
        if (pre[i] == i)
            for (int j = i * i; j < N; j += i)
                pre[j] = min(pre[j], i);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; sieve();
    while (t--){
        long long k, n; cin >> n >> k;
        cout <<  n + pre[n] + (k - 1) * 2 << '\n';
    }
}