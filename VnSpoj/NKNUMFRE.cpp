#include <bits/stdc++.h>
using namespace std;

bool is_friendly(int x){
    int t = 0, a = x;
    while (a > 0){
        t = t * 10 + a % 10; a /= 10;
    }
    return __gcd(t, x) == 1;
}

int main(){
    int a, b; cin >> a >> b; int cnt = 0;
    for (int i = a; i <= b; i++)
        cnt += is_friendly(i);
    cout << cnt << '\n';
}