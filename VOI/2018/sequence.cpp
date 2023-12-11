
// Problem : F. Ngày 2 - bài 3: Dãy xấp xỉ tăng (60 điểm)
// Contest : Codeforces - VOI 2018 - practice version
// URL : https://codeforces.com/group/FLVn1Sc504/contest/234046/problem/F
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

const int N = 300005;

int a[N], b[N];

int main() {
    freopen("sequence.inp", "r", stdin);
    freopen("sequence.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    long long ans = 0;
    priority_queue <int> pq;
    for (int i = 0; i < n; i++) {
        cin >> a[i]; a[i] -= i;
        pq.emplace(a[i]);
        if (pq.top() > a[i]) {
            ans += pq.top() - a[i];
            pq.pop();
            pq.emplace(a[i]);
        }
        b[i] = pq.top();
    }
    for (int i = n - 2; ~i; i--)
        cmin(b[i], b[i + 1]);
    cout << ans << '\n';
    for (int i = 0; i < n; i++)
        cout << b[i] + i << ' ';
}