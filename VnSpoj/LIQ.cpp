#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector <int> a(n);
    for (int &i : a) cin >> i;
    vector <int> tail(n + 1, INT_MAX);
    tail[0] = INT_MIN;
    int res = 0;
    for (int x : a){
        int k = lower_bound(tail.begin(), tail.end(), x) - tail.begin();
        tail[k] = x;
        res = max(res, k);
    }
    cout << res; return 0;
}