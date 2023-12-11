#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
deque <int> mi, ma;
int a[N], res, n, k;

int main(){
    freopen("lminmax.inp", "r", stdin);
    freopen("lminmax.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0, j = 0; i < n; i++){
        if (!mi.empty() && mi.front() < i) mi.pop_front();
        if (!ma.empty() && ma.front() < i) ma.pop_front();
        while (j < n){
            if (mi.empty() || ma.empty()){
                while (!mi.empty() && a[mi.back()] >= a[j]) mi.pop_back();
                while (!ma.empty() && a[ma.back()] <= a[j]) ma.pop_back();
                ma.push_back(j); mi.push_back(j); j++;
            }
            else if (max(a[ma.front()], a[j]) - min(a[mi.front()], a[j]) <= k){
                while (!mi.empty() && a[mi.back()] >= a[j]) mi.pop_back();
                while (!ma.empty() && a[ma.back()] <= a[j]) ma.pop_back();
                ma.push_back(j); mi.push_back(j); j++;
            }
            else break;
        }
        if (a[ma.front()] - a[mi.front()] <= k) res = max(res, j - i);
    }
    cout << res << '\n';
}
