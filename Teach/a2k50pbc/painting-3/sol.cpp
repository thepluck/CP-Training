#include <bits/stdc++.h>
 
using namespace std;
 
struct paint {
    int a, b, c;
    
    bool operator < (const paint &o) const {
        return a - b > o.a - o.b;
    }
};
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int x, y, z; cin >> x >> y >> z;
    int n = x + y + z;
    vector<paint> v(n);
    for (auto &p : v) cin >> p.a;
    for (auto &p : v) cin >> p.b;
    for (auto &p : v) cin >> p.c;
    sort(v.begin(), v.end());
    vector<long long> pre(n + 1), suf(n + 1);
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + v[i].a;
        pq.push(v[i].c - v[i].a);
        if (i >= x) {
            pre[i + 1] += pq.top(); pq.pop();
        }
    }
    while (pq.size()) pq.pop();
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = suf[i + 1] + v[i].b;
        pq.push(v[i].c - v[i].b);
        if (n - i > y) {
            suf[i] += pq.top(); pq.pop();
        }
    }
    long long res = 0;
    for (int i = x; i <= n - y; i++)
        res = max(res, pre[i] + suf[i]);
    cout << res;
    
}

