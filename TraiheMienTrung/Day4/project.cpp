#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 4e5 + 5;
int a[N], mx[N], ans[N];


int main(){
    freopen("project.inp", "r", stdin);
    freopen("project.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; ll h, s, d;
    cin >> n >> h >> s >> d;
    int k = (h + d) / s + 1;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    deque <int> dq; ll res = 0;
    memset(mx, 0x3f, sizeof mx);
    for (int i = n; i > 0; i--){
        while (!dq.empty() &&
        a[dq.back()] <= a[i])
            dq.pop_back();
        dq.push_back(i);
        mx[i] = a[dq.front()];
        if (dq.front() == i + k - 1)
            dq.pop_front();
    }
    int cur = 0; mx[n + 1] = 0;
    for (int i = 1; i <= n; i++){
        res += h * max(a[i] - cur, 0);
        cur += max(a[i] - cur, 0);
        res += s * cur; ans[i] = cur;
        if (mx[i + 1] < cur){
            res += d * (cur - mx[i + 1]);
            cur = mx[i + 1];
        }
    }
    cout << res << '\n';
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
}
