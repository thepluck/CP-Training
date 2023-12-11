#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 3e5 + 5;
ll f[N], g[N], p[N], a[N];
int start, n, d;

void calc1(int l, int r, int optl, int optr){
    int m = (l + r) / 2, optm; ll sum = 0;
    priority_queue <int,
    vector <int>, greater <int>> pq;
    for (int i = start; i < optl; i++){
        sum += a[i]; pq.push(a[i]);
    }
    for (int i = optl; i <= optr; i++){
        sum += a[i]; pq.push(a[i]);
        if (i - start > m) break;
        while (pq.size() > m - i + start){
            sum -= pq.top(); pq.pop();
        }
        if (sum > f[m]){
            f[m] = sum; optm = i;
        }
    }
    p[m] = optm;
    if (l < m) calc1(l, m - 1, optl, optm);
    if (m < r) calc1(m + 1, r, optm, optr);
}

void calc2(int l, int r, int optl, int optr){
    if (optl < optr) return;
    int m = (l + r) / 2, optm; ll sum = 0;
    priority_queue <int,
    vector <int>, greater <int>> pq;
    for (int i = start - 1; i > optl; i--){
        sum += a[i]; pq.push(a[i]);
    }
    for (int i = optl; i >= optr; i--){
        sum += a[i]; pq.push(a[i]);
        if (start - 1 - i > m) break;
        while (pq.size() > m + i - start + 1){
            sum -= pq.top(); pq.pop();
        }
        if (sum > g[m]){
            g[m] = sum; optm = i;
        }
    }
    if (l < m) calc2(l, m - 1, optl, optm);
    if (m < r) calc2(m + 1, r, optm, optr);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> start >> d; start++;
    for (int i = 1; i <= n; i++) cin >> a[i];
    calc1(1, d, start, n);
    calc2(1, d, start - 1, 1);
    ll res = 0;
    for (int i = 1; i <= d; i++){
        res = max(res, f[i]);
        if (d - i - (p[i] - start) > 0)
            res = max(res, f[i] +
            g[d - i - p[i] + start - 1]);
    }
    cout << res << '\n';
}