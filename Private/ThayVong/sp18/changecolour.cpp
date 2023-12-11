#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e6 + 5;
int c[N], tim[N];
queue <int> que;

int main(){
    freopen("changecolour.inp", "r", stdin);
    freopen("changecolour.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    memset(tim, -1, sizeof tim);
    for (int i = 1; i <= n; i++){
        char x; cin >> x;
        c[i] = x == 'R';
    }
    c[0] = c[n + 1] = -1;
    for (int i = 1; i <= n; i++)
        if (c[i] == c[i - 1] ||
            c[i] == c[i + 1]){
            tim[i] = 0; que.push(i);
        }
    while (!que.empty()){
        int u = que.front(); que.pop();
        if (u > 1 && c[u - 1] != c[u]
        && tim[u - 1] == -1){
            tim[u - 1] = tim[u] + 1;
            que.push(u - 1);
        }
        if (u < n && c[u + 1] != c[u]
        && tim[u + 1] == -1){
            tim[u + 1] = tim[u] + 1;
            que.push(u + 1);
        }
    }
    while (q--){
        int u; ll st; cin >> u >> st;
        if (tim[u] == -1 || st <= tim[u])
            cout << (c[u] ? 'R' : 'B') << '\n';
        else {
            int tmp = st - tim[u] & 1;
            cout << ((c[u] ^ tmp) ? "R\n" : "B\n");
        }
    }
}