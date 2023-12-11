#include <bits/stdc++.h>
using namespace std;

bitset <5005> bs;

int main(){
    int c, n, x; cin >> c >> n;
    bs[0] = 1;
    while (n--){
        cin >> x; bs |= bs << x;
    }
    while (!bs[c]) --c;
    cout << c << '\n';
}