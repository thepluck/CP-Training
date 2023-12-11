#include <bits/stdc++.h>
using namespace std;

void setup(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
}

int main(){
    setup();
    int n; cin >> n;
    long long a[n + 1]; a[0] = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i]; a[i] += a[i - 1];
    }
    long long maxv = 0, minv = 0;
    long long ans = LLONG_MIN;
    for (int i = 1; i <= n; ++i){
        if (i < n) ans = max(ans, a[i] - minv);
        if (i > 1) ans = max(ans, a[n] - a[i - 1] + maxv);
        maxv = max(maxv, a[i - 1]);
        minv = min(minv, a[i]);
    }
    cout << ans << '\n';
}
