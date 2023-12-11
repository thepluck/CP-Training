#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void sol(){
    ll x, y, a, b; cin >> x >> y >> a >> b;
    if (a * 2 <= b){
        cout << a * (x + y) << '\n';
    }
    else {
        if (x < y) swap(x, y);
        cout << y * b + (x - y) * a << '\n';
    }
}

int main(){
    int t; cin >> t; while (t--) sol();
}