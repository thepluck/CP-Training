#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define lb lower_bound

using ll = long long;
const int N = 2e5 + 5;
int a[N], n, bit[2 * N]; ll ans;

void update(int i){
    for (; i <= 2 * n; i += i & -i) 
        bit[i]++;
}

int retrieve(int i){
    int res = 0;
    for (; i > 0; i -= i & -i)
        res += bit[i];
    return res;
}

set <int> s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0, x; i < n; i++){
        cin >> x; a[i] -= x;
        s.insert(a[i]); s.insert(-a[i]);
    }
    vector <int> cmp(all(s));
    for (int i = 0; i < n; i++){
        ans += retrieve(lb(all(cmp), a[i]) - cmp.begin() + 1);
        update(lb(all(cmp), -a[i]) - cmp.begin() + 2);
    }
    cout << ans << '\n';
}