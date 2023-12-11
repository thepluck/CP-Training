#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()
#define ub upper_bound
#define lb lower_bound
const int N = 4e5 + 5;
struct que{
    int type, a, b;
    que(): a(0), b(0){}
};

using ll = long long;
vector <int> cmp; int a[N];
que q[N]; ll sum[N << 2];
int lo[N << 2], hi[N << 2], cnt[N << 2];

void build(int i, int l, int r){
    lo[i] = l; hi[i] = r;
    if (l == r) return;
    int m = (l + r) >> 1;
    build(i << 1, l, m);
    build(i << 1 | 1, m + 1, r);
}

void update(int i, int pos, bool type){
    if (lo[i] > pos || hi[i] < pos) return;
    if (lo[i] == hi[i]){
        if (type){
            cnt[i]++; sum[i] += a[pos];
        }
        else if (cnt[i] > 0){
            cnt[i]--; sum[i] -= a[pos];
        }
        return;
    }
    update(i << 1, pos, type);
    update(i << 1 | 1, pos, type);
    cnt[i] = cnt[i << 1] + cnt[i << 1 | 1];
    sum[i] = sum[i << 1] + sum[i << 1 | 1];
}

int kth(int i, int k){
    if (lo[i] == hi[i]) return lo[i];
    if (cnt[i << 1] >= k) return kth(i << 1, k);
    else return kth(i << 1 | 1, k - cnt[i << 1]);
}

long long query(int i, int l, int r){
    if (lo[i] > r || hi[i] < l) return 0;
    if (lo[i] >= l && hi[i] <= r) return sum[i];
    return query(i << 1, l, r) + query(i << 1 | 1, l, r);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n; build(1, 1, 2 * n);
    for (int i = 1; i <= n; i++){
        cin >> q[i].type;
        if (q[i].type <= 2){
            cin >> q[i].a; cmp.push_back(q[i].a);
        }
        else if (q[i].type == 4){
            cin >> q[i].a >> q[i].b;
            cmp.push_back(q[i].a);
            cmp.push_back(q[i].b);
        }
        else if (q[i].type == 3) cin >> q[i].a;
    }
    sort(all(cmp)); cmp.resize(unique(all(cmp)) - cmp.begin());
    for (int i = 1; i <= n; i++){
        if (q[i].type == 1){
            int t = ub(all(cmp), q[i].a) - cmp.begin();
            a[t] = q[i].a; update(1, t, 1);
        }
        if (q[i].type == 2){
            int t = ub(all(cmp), q[i].a) - cmp.begin();
            a[t] = q[i].a; update(1, t, 0);
        }
        if (q[i].type == 3) cout << a[kth(1, q[i].a)] << '\n';
        if (q[i].type == 4){
            int x = ub(all(cmp), q[i].a) - cmp.begin();
            int y = ub(all(cmp), q[i].b) - cmp.begin();
            a[x] = q[i].a; a[y] = q[i].b;
            cout << query(1, x, y) << '\n';
        }
    }
}