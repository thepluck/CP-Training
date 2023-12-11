#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[N]; long long cnt[1 << 10];

int main(){
    //freopen("cmndig.inp", "r", stdin);
    //freopen("cmndig.out", "w", stdout); 
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 1, x; i <= n; i++){
        cin >> x; int msk = 0;
        do {
            msk |= 1 << (x % 10); x /= 10;
        }
        while (x > 0);
        cnt[msk]++;
    }
    long long res = 0;
    for (int i = 0; i < 1024; i++){
        for (int j = i + 1; j < 1024; j++)
            if (i & j) res += cnt[i] * cnt[j];
        res += cnt[i] * (cnt[i] - 1) / 2;
    }
    cout << res << '\n';
}