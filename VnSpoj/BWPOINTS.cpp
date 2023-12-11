#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector <pair <int, bool>> a(2 * n);
    for (int i = 0; i < n; i++){
        cin >> a[i].first; a[i].second = 0;
    }
    for (int i = n; i < 2 * n; i++){
        cin >> a[i].first; a[i].second = 1;
    }
    sort(a.begin(), a.end()); int res = 0;
    for (int i = 1; i < 2 * n; i++){
        if (a[i].second != a[i - 1].second)
            res++, i++;
    }
    cout << res << '\n';
}