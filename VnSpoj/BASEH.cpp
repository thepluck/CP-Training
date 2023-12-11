#include <bits/stdc++.h>
using namespace std;

int main(){
    long long k; cin >> k;
    string s;
    while (k > 0){
        s = s + char('0' + (k & 1));
        k >>= 1;
    }
    reverse(s.begin(), s.end());
    cout << s << '\n';
}