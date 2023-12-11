#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()
#define lb lower_bound
#define ub upper_bound
const int N = 1e5 + 5;
int bit[N], a[N], n, k;
vector <int> cmp;

void update(int i){
    for (; i <= n; i += i & -i) bit[i]++;
}

int retrieve(int i){
    int res = 0;
    for (; i > 0; i -= i & -i) res += bit[i];
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1, x; i <= n; i++){
        cin >> x; a[i] = a[i - 1] + (x >= k);
        cmp.push_back(2 * a[i - 1] - i + 1);
    }
    sort(all(cmp)); long long res = 0;
    cmp.resize(unique(all(cmp)) - cmp.begin());
    for (int i = 1; i <= n; i++){
        update(ub(all(cmp), 2 * a[i - 1] - i + 1) - cmp.begin());
        res += retrieve(ub(all(cmp), 2 * a[i] - i) - cmp.begin());
    }
    cout << res << '\n';
}