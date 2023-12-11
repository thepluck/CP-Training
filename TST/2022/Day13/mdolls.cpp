#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
const int S = 200;
const int M = 500005;

struct query {
    int l, r, id;

    query() {}

    query(int l, int r, int id): l(l), r(r), id(id) {}
};

int a[N], pre[N], nex[N], n, q, pos[N];
query que[M]; long long ans = 0;
long long tmp[M];

void del(int x) {
    int y = pre[x], z = nex[x];
    if (y > 0 && z <= n)
        ans += abs(pos[y] - pos[z]);
    if (y > 0)
        ans -= abs(pos[x] - pos[y]);
    if (z <= n)
        ans -= abs(pos[x] - pos[z]);
    nex[y] = z; pre[z] = y;
}

void add(int x) {
    int y = pre[x], z = nex[x];
    if (y > 0 && z <= n)
        ans -= abs(pos[y] - pos[z]);
    if (y > 0)
        ans += abs(pos[x] - pos[y]);
    if (z <= n)
        ans += abs(pos[x] - pos[z]);
    nex[y] = pre[z] = x;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i]; pos[a[i]] = i;
    }
    for (int i = 0; i < q; i++) {
        cin >> que[i].l >> que[i].r;
        que[i].l--; que[i].r--;
        que[i].id = i;
    }
    sort(que, que + q, [](query x, query y) {
        if (x.l / S != y.l / S)
            return x.l < y.l;
        return x.r > y.r;
    });
    int bl = -1, l, r;
    for (int i = 0; i < q; i++) {
        if (bl != que[i].l / S) {
            bl = que[i].l / S;
            l = bl * S; r = n - 1;
            memset(pre, 0, sizeof pre);
            for (int j = l; j <= r; j++)
                pre[a[j]] = 1;
            pre[0] = pre[n + 1] = 1;
            vector<int> v; ans = 0;
            for (int j = 0; j <= n + 1; j++)
                if (pre[j]) v.push_back(j);
            for (int j = 0; j + 1 < v.size(); j++) {
                nex[v[j]] = v[j + 1]; pre[v[j + 1]] = v[j];
                if (v[j] > 0 && v[j + 1] <= n)
                    ans += abs(pos[v[j]] - pos[v[j + 1]]);
            }
        }
        while (r > que[i].r) del(a[r--]);
        for (int j = l; j < que[i].l; j++) del(a[j]);
        tmp[que[i].id] = ans;
        for (int j = que[i].l - 1; j >= l; j--) add(a[j]);
        assert(l <= que[i].l && r == que[i].r);
    }
    for (int i = 0; i < q; i++)
        cout << tmp[i] << '\n'; 
}