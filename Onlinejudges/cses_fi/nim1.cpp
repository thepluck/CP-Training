#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t, n, x; cin >> t;
    while (t--){
        cin >> n; int nim = 0;
        while (n--){
            cin >> x; nim ^= x;
        }
        if (nim) cout << "first\n";
        else cout << "second\n";
    }
}