#include <bits/stdc++.h>
using namespace std;

int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
long long n, res = LLONG_MAX;

void solve(int i, long long cur, int cnt){
    if (cnt == n){
        res = min(res, cur); return;
    }
    if (i == 10) return;
    for (int j = 1; ; j++){
        if (cur * prime[i] > res) return;
        cur *= prime[i]; if (cur < 0) return;
        solve(i + 1, cur, cnt * (j + 1));
    }
}

int main(){
    cin >> n; solve(0, 1, 1); cout << res << '\n';
}