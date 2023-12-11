#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    bitset <100005> bs;
    int n, x; cin >> n; bs[0] = 1;
    while (n--){
        cin >> x; bs |= bs << x;
    }
    cout << bs.count() - 1 << '\n';
    for (int i = 1; i < 100005; i++)
        if (bs[i]) cout << i << ' ';
    cout << '\n';
}