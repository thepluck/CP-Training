#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()
#define lb lower_bound
#define ub upper_bound

int main(){
    freopen("darts.inp", "r", stdin);
    freopen("darts.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, res = 0, m;
    cin >> n >> m;
    vector <int> val, a(n);
    val.push_back(0);
    for (int &x : a){
        cin >> x; val.push_back(x);
    }
    for (int x : a)
        for (int y : a)
            val.push_back(x + y);
    sort(val.begin(), val.end());
    for (int x : val){
        auto it = ub(all(val), m - x);
        if (it != val.begin()){
            --it; res = max(res, x + *it);
        }
    }
    cout << res << '\n';
}