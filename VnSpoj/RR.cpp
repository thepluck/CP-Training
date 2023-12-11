#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    string s; getline(cin, s);
    ll cntx = 0, cntxy = 0;
    char x, y; cin >> x >> y;
    for (char c : s){
        if (c == y) cntxy += cntx;
        if (c == x) cntx++;
    }
    cout << cntxy << '\n';
}