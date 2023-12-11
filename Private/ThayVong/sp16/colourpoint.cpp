#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 5e5 + 5;
int pos[N]; ll ans[N];

int main(){
    freopen("colourpoint.inp", "r", stdin);
    freopen("colourpoint.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1, x; i <= n; i++){
        cin >> x;
        ans[x] += 1ll * (i - pos[x]) * (n - i + 1);
        pos[x] = i;
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << '\n';
}