#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define fi first
#define se second

using ii = pair <int, int>;

const int N = 1e6 + 5;
int a[N]; deque <ii> dq;

int main(){
    freopen("gas.inp", "r", stdin);
    freopen("gas.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; cin >> a[i++]);
    dq.eb(a[0], k); long long cost = 0;
    for (int i = 1; i <= n; i++){
        cost += dq[0].fi; dq[0].se--;
        if (!dq[0].second) dq.pop_front();
        int need = 1;
        while (!dq.empty() &&
                dq.back().fi > a[i]){
            need += dq.back().se;
            dq.pop_back();
        }
        dq.eb(a[i], need);
    }
    cout << cost << '\n';
}
