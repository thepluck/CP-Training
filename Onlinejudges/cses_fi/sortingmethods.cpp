#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define lb lower_bound
#define all(v) v.begin(), v.end()

const int N = 2e5 + 5;
int bit[N], nxt[N], p[N], vs[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, cyc = 0; cin >> n;
    for_each(p + 1, p + n + 1,
    [](int &x){cin >> x;});
    auto update = [&](int i){
        for (; i <= n; i += i & -i)
            bit[i]++;
    };
    auto query = [&](int i){
        int res = 0;
        for (; i > 0; i -= i & -i)
            res += bit[i];
        return res;
    };
    function <void(int)> dfs
    = [&](int u){
        vs[u] = 1;
        if (vs[nxt[u]]) cyc++;
        else dfs(nxt[u]);
    };
    long long res = 0;
    for (int i = n; i > 0; i--){
        res += query(p[i]);
        update(p[i]);
        nxt[i] = p[i];
    }
    cout << res << ' ';
    for (int i = 1; i <= n; i++)
        if (!vs[i]) dfs(i);
    cout << n - cyc << ' ';
    vector <int> lis;
    res = 0; cyc = n;
    for (int i = 1; i <= n; i++){
        auto it = lb(all(lis), p[i]);
        if (it == lis.end())
            lis.eb(p[i]);
        else *it = p[i];
    }
    cout << n - lis.size() << ' ';
    for (int i = n; i > 0; i--)
        if (p[i] == cyc){
            cyc--; res++;
        }
    cout << n - res << '\n';
}