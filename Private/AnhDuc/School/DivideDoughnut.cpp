#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int l = 0, r = 5e8 - 1, m, cur;
    cout << "QUERY " << l << ' ' << r << endl;
    cin >> cur; 
    if (cur * 2 == n){
        cout << "YES 0" << endl; return 0;
    }
    while (r - l > 2){
        m = (l + r) >> 1; int x;
        cout << "QUERY " << m << ' ' << m + int(5e8 - 1) << endl;
        cin >> x;
        if (x * 2 == n){
            cout << "YES " << m << endl; return 0;
        }
        if (1ll * (n - 2 * cur) * (n - 2 * x) < 0) r = m;
        else {
            l = m; cur = x;
        }
    }
    if (cur * 2 == n) cout << "YES " << l << endl;
    else cout << "YES " << l + 1 << endl;
}