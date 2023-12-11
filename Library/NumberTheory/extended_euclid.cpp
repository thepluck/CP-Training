#include <bits/stdc++.h>
using namespace std;

ll ext_euclid(ll a, ll b, ll &x, ll &y){
    int g = a; x = 1; y = 0;
    if (b != 0){
        g = ext_euclid(b, a % b, y, x);
        y -= (a / b) * x;
    }
    return g;
}

int main(){
    int a, b, x, y; cin >> a >> b;
    cout << ext_euclid(a, b, x, y) << '\n';
}
