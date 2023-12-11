#include <bits/stdc++.h>
using namespace std;

using ll = long long;
struct que{
    int t, a, b;
};
#define clz __builtin_clz
#define ub upper_bound
#define lb lower_bound
#define all(v) (v).begin(), (v).end()

const int N = 2e5 + 5;
int a[N], cnt[N]; ll sum[N], n; que q[N];

void update(int i, int val, int t){
    if (t == -1 && cnt[i] == 0) return;
    for (; i <= n; i += i & -i){
        cnt[i] += t; sum[i] += 1ll * t * val;
    }
}

int order(int k){
    int pos = 0, cur = 0, p = 1 << (31 - clz(n));
    for (; p > 0; p >>= 1)
        if (pos + p <= n && cur + cnt[pos + p] < k){
            cur += cnt[pos + p]; pos += p;
        }
    return a[pos + 1];
}

ll query(int i){
    ll res = 0;
    for (; i > 0; i -= i & -i) res += sum[i];
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n; vector <int> cmp;
    for (int i = 1; i <= n; i++){
        cin >> q[i].t;
        if (q[i].t <= 2){
            cin >> q[i].a; cmp.push_back(q[i].a); 
        }
        if (q[i].t == 3) cin >> q[i].a;
        if (q[i].t == 4) cin >> q[i].a >> q[i].b;
    }
    sort(all(cmp));
    cmp.resize(unique(all(cmp)) - cmp.begin());
    for (int i = 1; i <= n; i++){
        if (q[i].t == 1){
            int j = ub(all(cmp), q[i].a) - cmp.begin();
            a[j] = q[i].a; update(j, a[j], 1);
        }
        if (q[i].t == 2){
            int j = ub(all(cmp), q[i].a) - cmp.begin();
            a[j] = q[i].a; update(j, a[j], -1);
        }
        if (q[i].t == 3) cout << order(q[i].a) << '\n';
        if (q[i].t == 4){
            int j = lb(all(cmp), q[i].a) - cmp.begin();
            int k = ub(all(cmp), q[i].b) - cmp.begin();
            cout << query(k) - query(j) << '\n';
        }
    }
}