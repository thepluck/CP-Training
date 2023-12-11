#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define lb lower_bound
#define ub upper_bound
using ll = long long;
const int N = 1e4 + 5;
const int K = 55;
const int VAL = 1e5 + 5;
ll bit[VAL][K], inc[N][K]; int a[N], n;
const int mod = 5000000;

void update(int i, int k, ll val){
    for (; i < N; i += i & -i)
        bit[i][k] = (bit[i][k] + val) % mod;
}

ll retrieve(int i, int k){
    ll res = 0;
    for (; i > 0; i -= i & -i)
        res = (res + bit[i][k]) % mod;
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n; int k; cin >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i]; a[i] += 2;
    }
    vector <int> v(a + 1, a + n + 1);
    sort(all(v));
    for (int i = 1; i <= n; i++)
        a[i] = lb(all(v), a[i]) - v.begin() + 1;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= k; j++){
            if (j == 1) inc[i][j] = 1;
            else inc[i][j] = retrieve(a[i] - 1, j - 1);
            update(a[i], j, inc[i][j]);
        }
    }
    ll res = 0;
    for (int i = 1; i <= n; i++)
        res = (res + inc[i][k]) % mod;
    cout << res;
}
