#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define ub upper_bound
#define all(v) (v).begin(), (v).end()

const int N = 2e5 + 5;
const int mod = 1e9 + 7;
int bit[N], a[N];
vector <int> cmp;

void update(int i, int val){
    for (; i < N; i += i & -i)
        bit[i] = (bit[i] + val) % mod;
}

int query(int i){
    int res = 0;
    for (; i > 0; i -= i & -i)
        res = (res + bit[i]) % mod;
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i]; cmp.eb(a[i]);
    }
    sort(all(cmp)); int res = 0;
    cmp.resize(distance(cmp.begin(),
    unique(all(cmp))));
    for (int i = 1; i <= n; i++)
        a[i] = distance(cmp.begin(),
        ub(all(cmp), a[i]));
    for (int i = 1; i <= n; i++){
        int tmp = query(a[i] - 1) + 1;
        res = (res + tmp) % mod;
        update(a[i], tmp);
    }
    cout << res << '\n';
}