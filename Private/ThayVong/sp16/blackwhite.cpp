#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int main(){
    freopen("blackwhite.inp", "r", stdin);
    freopen("blackwhite.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, pos[2]; cin >> n;
    long long res = 0;
    pos[0] = pos[1] = 0;
    for (int i = 1, x; i <= n; i++){
        cin >> x; pos[x] = i;
        res += pos[x ^ 1];
    }
    cout << res << '\n';
}