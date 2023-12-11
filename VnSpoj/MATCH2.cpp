
// Problem : D. MATCH2 - Bộ ghép đầy đủ trọng số cực tiểu
// Contest : Codeforces - ACM set 09
// URL : https://codeforces.com/group/FLVn1Sc504/contest/274505/problem/D
// Memory Limit : 1024 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

const int N = 205;
const int inf = 0x3f3f3f3f;

int a[N][N], dis[N]; bool ok[N];
int px[N], py[N], mat[N], tr[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    memset(a, 0x3f, sizeof a);
    int n, u, v; cin >> n;
    while (cin >> u >> v)
        cin >> a[u][v];
    for (int i = 1; i <= n; i++) {
        u = 0; mat[0] = i;
        fill_n(dis, n + 1, inf);
        fill_n(tr, n + 1, -1);
        fill_n(ok, n + 1, 0);
        while (mat[u]) {
            ok[u] = 1; int d = inf, w;
            for (v = 0; v <= n; v++) {
                if (ok[v]) continue;
                if (cmin(dis[v], a[mat[u]][v] -
                px[mat[u]] - py[v])) tr[v] = u;
                if (cmin(d, dis[v])) w = v;
            }
            for (v = 0; v <= n; v++) {
                if (ok[v]) {
                    px[mat[v]] += d;
                    py[v] -= d;
                }
                else dis[v] -= d;
            }
            u = w;
        }
        for (; u; u = v)
            mat[u] = mat[v = tr[u]];
    }
    cout << -py[0] << '\n';
    for (int i = 1; i <= n; i++)
        cout << mat[i] << ' ' << i << '\n';
}