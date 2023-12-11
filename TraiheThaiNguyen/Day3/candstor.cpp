#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int C = 7e5 + 5;
bitset <C> bs; int a[N], dp[C];

int main(){
    freopen("candstor.inp", "r", stdin);
    freopen("candstor.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, res = 0, id; cin >> n;
    for (int i = 1; i <= n; cin >> a[i++]);
    for (int i = 1; i <= n; i++){
        bs.reset(); bs[0] = 1;
        for (int j = 1; j <= n; j++)
            if (i != j) bs |= bs << a[j];
        if (res < bs.count() - 1){
            res = bs.count() - 1; id = i;
        }
        else if (res == bs.count() - 1 &&
                a[id] > a[i])
            id = i;
    }
    bs.reset(); bs[0] = 1;
}