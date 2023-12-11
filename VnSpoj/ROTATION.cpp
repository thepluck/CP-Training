#include <bits/stdc++.h>
using namespace std;
int n, ans, type, u, v;

int main(){
    cin >> n;
    while (--n){
        cin >> u >> v >> type;
        ans ^= type;
    }
    cout << ans << '\n';
}