#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x = 0; cin >> n;
    if (n == 1) cout << "4\n0 1 2 3\n"; 
    else if (n == 2) cout << "1\n4\n";
    else if (n == 3) cout << "2\n5 6\n";
    else {
        n--; long double cnt = 0, temp = n;
        while (cnt < temp) cnt += log10(++x);
        if (floor(cnt) == n) cout << "1\n" << x << '\n';
        else cout << "NO\n"; 
    }
}