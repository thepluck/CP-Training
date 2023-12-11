#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a, b, cn = 0;
    cin >> a >> b;
    if (__gcd(a, b) > 1){
        cout << "impossible\n";
        return 0;
    }
    if (a > b) swap(a, b);
    while (a != 1 && b != 1){
        cn += b / a; b %= a;
        swap(a, b);
    }
    cn += b - 1;
    cout << cn << '\n';
}