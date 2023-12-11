/// Harder knapsack
#include <bits/stdc++.h>
using namespace std;
 
using ll = long long; deque <int> dq[1005]; ll f[10005], g[10005];
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); memset(f, 0xc0, sizeof f); 
    int n, w, v, a, m; cin >> n >> m; cin >> w >> v >> a; 
    for (int j = 0; j <= m; j++) if (j % w == 0 && j / w <= a) f[j] = (j / w) * v;
    for (int i = 1; i < n; i++){
        cin >> w >> v >> a; for (int j = 0; j < w; j++) dq[j].clear();
        for (int j = 0; j <= m; j++){
            int t = j % w; while (!dq[t].empty() && dq[t].front() < j - w * a) dq[t].pop_front();
            while (!dq[t].empty() && f[dq[t].back()] + 1ll * (j - dq[t].back()) / w * v <= f[j]) dq[t].pop_back();
            dq[t].push_back(j); g[j] = f[dq[t].front()] + 1ll * (j - dq[t].front()) / w * v;
        }
        for (int j = 0; j <= m; j++) swap(f[j], g[j]);
    }
    cout << *max_element(f, f + m + 1) << '\n';