#include <bits/stdc++.h>
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define lb lower_bound
using namespace std;

const int N = 3e5 + 5;
const int M = 1e5 + 5;
using ii = pair <int, int>;
pair <ii, int> a[N]; 
int bit[M], n, ans[N];

void update(int i, int val){
    for (; i < M; i += i & -i)
        bit[i] += val;
}

int get_num(int i){
    int res = 0;
    for (; i > 0; i -= i & -i)
        res += bit[i];
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i].fi.fi >> a[i].fi.se;
        a[i].se = i;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1, j; i <= n;  i = j + 1){
        for (j = i; a[i].fi == a[j + 1].fi; j++);
        int t = get_num(a[i].fi.se);
        for (int k = i; k <= j; k++)
            ans[a[k].se] = t;
        update(a[i].fi.se, j - i + 1);
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << '\n';
}