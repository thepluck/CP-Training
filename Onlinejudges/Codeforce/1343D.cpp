#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int solve(){
    int n, k; cin >> n >> k;
    vector <int> a(n), event((k + 1) << 1);
    for (int i = 0; i < n; cin >> a[i++]);
    for (int i = 0; i < n / 2; i++){
        int mi = min(a[i], a[n - i - 1]);
        int ma = max(a[i], a[n - i - 1]);
        event[1] += 2; 
        event[mi + 1]--;
        event[mi + ma]--; 
        event[mi + ma + 1]++;
        event[ma + k + 1]++;
    }
    int sum = 0, res = INT_MAX;
    for (int i = 1; i < size(event); i++){
        sum += event[i]; res = min(res, sum);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; 
    while (t--) cout << solve() << '\n';
}