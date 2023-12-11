#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().
time_since_epoch().count());

struct custom_hash {
    static int splitmix64(int x){
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    int operator()(int x) const {
        static const int FIXED_RANDOM = rng();
        return splitmix64(x + FIXED_RANDOM);
    }
};

struct query{
    int l, r, id;

    query(): l(0), r(0), id(0){}
};

const int N = 2e5 + 5; query que[N];
int a[N], bit[N], ans[N], n, q;
unordered_map <int, int, custom_hash> last;

void update(int i, int t){
    for (; i <= n; i += i & -i) bit[i] += t;
}

int get_sum(int i){
    int res = 0;
    for (; i > 0; i -= i & -i) res += bit[i];
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= q; i++){
        cin >> que[i].l >> que[i].r;
        que[i].id = i;
    }
    sort(que + 1, que + q + 1,
    [&](query x, query y){return x.r < y.r;});
    for (int i = 1; i <= q; i++){
        for (int j = que[i - 1].r + 1;
                j <= que[i].r; j++){
            if (last[a[j]])
                update(last[a[j]], -1);
            update(last[a[j]] = j, 1);
        }
        ans[que[i].id] = get_sum(que[i].r)
                    - get_sum(que[i].l - 1);
    }
    for (int i = 1; i <= q; i++)
        cout << ans[i] << '\n';
}