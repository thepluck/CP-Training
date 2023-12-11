#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    set <int> s; int n; cin >> n;
    for (int i = 1, x; i <= n; i++){
        cin >> x;
        auto it = s.lower_bound(x);
        if (it != s.end()) s.erase(it);
        s.insert(x);
    }
    cout << s.size() << '\n';
}