#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, k; cin >> n >> m >> k;
    vector <int> a(n);
    vector <int> b(m);
    for (int &x : a) cin >> x; for (int &x : b) cin >> x;
    sort(a.begin(), a.end()); sort(b.begin(), b.end());
    for (int i = 0; i < n; i++)
        if (a[i] < i / k) return cout << -1, 0;
    int l = 0, r = m, mid, ans = 0;
    while (l <= r){
        mid = (l + r) / 2; vector <int> temp; bool flag = true;
        merge(a.begin(), a.end(), b.begin() + m - mid, b.end(), back_inserter(temp));
        for (int i = 0; i < n + mid; i++)
            if (temp[i] < i / k){
                flag = false; break;
            }
        if (flag){
            ans = mid; l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans << '\n';
}