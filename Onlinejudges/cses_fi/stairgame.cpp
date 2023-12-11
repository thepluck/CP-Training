#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--){
        int n, res = 0; cin >> n;
        for (int i = 0; i < n; i++){
            int x; cin >> x;
            if (i & 1) res ^= x;
        }
        cout << (res ? "first" :
        "second") << '\n';
    }
}