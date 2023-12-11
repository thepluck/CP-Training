#include <bits/stdc++.h>
using namespace std;

vector <int> cc;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, sum = 0; cin >> n >> m;
    for (int i = 0; i < n; i++){
        int t, k, x; cin >> t >> k;
        while (k--){
            cin >> x; cc.push_back(x - sum);
        }
        sum += t;
    }
    sort(cc.begin(), cc.end());
    int wait = m < (int)cc.size() ? cc[m - 1] : cc.back();
    cout << sum + max(wait, 0) << '\n'; 
}