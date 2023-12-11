#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmax(X &a, const Y &b) {
    return a < b ? a = b, 1 : 0;
}

const int K = 200;
const int N = 200005;

struct query {
    int l, r, i;
    
    bool operator < (const query &o) const {
        return l / K != o.l / K ? l < o.l : r < o.r;
    }
} que[N];

int a[N], farL[N], len[N], ans[N];
int nearL[N], nearR[N], farR[N];
map <int, int> val[N];
vector <int> chain[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (val[farL[i - 1]].count(a[i])) {
            nearL[i] = val[farL[i - 1]][a[i]] - 1;
            farL[i] = farL[nearL[i]];
        }
        else nearL[i] = farL[i] = i;
        val[farL[i]][-a[i]] = i;
    }
    chain[n + 1].push_back(n + 1);
    nearR[n + 1] = farR[n + 1] = n + 1;
    len[n + 1] = 1;
    for (int i = 1; i <= n; i++)
        val[i].clear();
    for (int i = n; i > 0; i--) {
        if (val[farR[i + 1]].count(a[i])) {
            nearR[i] = val[farR[i + 1]][a[i]] + 1;
            farR[i] = farR[nearR[i]];
        }
        else nearR[i] = farR[i] = i;
        val[farR[i]][-a[i]] = i;
        chain[farR[i]].push_back(i);
        len[farR[i]]++;
    }
    for (int i = 1; i <= n + 1; i++)
        reverse(chain[i].begin(), chain[i].end());
    for (int i = 1; i <= q; i++) {
        cin >> que[i].l >> que[i].r;
        que[i].i = i;
    }
    sort(que + 1, que + q + 1);
    int last = -1, l, r, tmp = 0;
    for (int i = 1; i <= q; i++) {
        if (last != que[i].l / K) {
            last = que[i].l / K; tmp = 0;
            l = r = (last + 1) * K - 1;
            farL[l] = l;
        }
        while (r < que[i].r) {
            if (nearL[++r] >= l)
                farL[r] = farL[nearL[r]];
            else farL[r] = r;
            cmax(tmp, r - farL[r]); 
        }
        ans[que[i].i] = tmp;
        for (int j = que[i].l;
        j <= min(que[i].r, l); j++) {
            auto it = prev(upper_bound
            (chain[farR[j]].begin(),
            chain[farR[j]].end(), que[i].r + 1));
            cmax(ans[que[i].i], *it - j);
        }
    }
    for (int i = 1; i <= q; i++)
        cout << ans[i] << '\n';
}