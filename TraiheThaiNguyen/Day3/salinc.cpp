#include <bits/stdc++.h>
using namespace std;

template <class X, class Y>
bool chkmax(X &a, const Y &b){
    return a < b ? a = b, 1 : 0;
}

const int N = 3e5 + 5;
int s[N], tag[4 * N], mx[4 * N];
vector <int> adj[N];
int lo[4 * N], hi[4 * N], ans[N];

void build(int i, int l, int r){
    lo[i] = l; hi[i] = r;
    if (l != r){
        int m = (l + r) / 2;
        build(i * 2, l, m);
        build(i * 2 + 1, m + 1, r);
    }
}

void push_tag(int i, int tg){
    tag[i] = max(tag[i], tg);
    mx[i] = max(mx[i], tag[i]);
}

void push_down(int i){
    if (tag[i] && lo[i] != hi[i]){
        push_tag(i * 2, tag[i]);
        push_tag(i * 2 + 1, tag[i]);
    }
    tag[i] = 0;
}

void set_max(int i, int l, int r, int v){
    push_down(i);
    if (lo[i] > r || hi[i] < l) return;
    if (lo[i] >= l && hi[i] <= r)
        return push_tag(i, v);
    set_max(i * 2, l, r, v);
    set_max(i * 2 + 1, l, r , v);
    mx[i] = max(mx[i * 2], mx[i * 2 + 1]);
}

void set_val(int i, int p, int v){
    push_down(i);
    if (lo[i] > p || hi[i] < p) return;
    if (lo[i] == hi[i])
        return void(mx[i] = v);
    set_val(i * 2, p, v);
    set_val(i * 2 + 1, p, v);
    mx[i] = max(mx[i * 2], mx[i * 2 + 1]);
}

int get_max(int i, int l, int r){
    if (lo[i] > r || hi[i] < l) return 0;
    if (lo[i] >= l && hi[i] <= r) return mx[i];
    return max(get_max(i * 2, l, r),
                get_max(i * 2 + 1, l, r));
}

void dfs(int u, int p, int d){
    int l = 1, r = d, m;
    while (l <= r){
        m = (l + r) / 2;
        if (get_max(1, m, d) < s[u]){
            ans[u] = d - m + 1;
            r = m - 1;
        }
        else l = m + 1;
    }
    if (ans[u]) set_max(1, d - ans[u]
                        + 1, d, s[u]);
    d++; set_val(1, d, s[u]);
    for (int v : adj[u])
        if (v != p) dfs(v, u, d);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n >> s[1];
    for (int i = 2; i <= n; i++){
        int j; cin >> s[i] >> j;
        j++; adj[j].push_back(i);
    }
    build(1, 1, n); dfs(1, 0, 0);
    for (int i = 2; i <= n; i++)
        cout << ans[i] << '\n';
}