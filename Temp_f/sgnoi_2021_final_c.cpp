#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k; k++;
    vector<int> a(n), b(n);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    priority_queue<int> pq;
    int sum = 0, pre = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int cur = (b[i] - a[i] + k) % k;
        int dif = (pre - cur + k) % k;
        sum -= dif; pq.push(dif);
        if (sum < 0) {
            ans += k - pq.top();
            pq.pop(); sum += k;
        }
        pre = cur;
    }
    cout << ans;
}