#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("maxsegment.inp", "r", stdin);
    freopen("maxsegment.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, k; cin >> n >> n >> k;
    deque <int> dq;
    vector <int> a(n);
    for (int &x : a) cin >> x;
    for (int i = 0; i < k - 1; i++){
        while (!dq.empty() &&
        a[dq.back()] <= a[i])
            dq.pop_back();
        dq.push_back(i);
    }
    for (int i = k - 1; i < n; i++){
        while (!dq.empty() &&
        a[dq.back()] <= a[i])
            dq.pop_back();
        dq.push_back(i);
        cout << a[dq.front()] << ' ';
        if (dq.front() == i - k + 1)
            dq.pop_front();
    }
}
