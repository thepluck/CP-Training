#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
using ll = long long;
int a[N], n; ll ans;

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i]; ans += a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n / 2; i++)
        ans += a[n - i + 1] - a[i];
    cout << ans << '\n';
}