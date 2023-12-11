#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int bit[N][N], a[N][N];

void update(int x, int y){
    for (int i = x; i < N; i += i & -i)
        for (int j = y; j < N; j += j & -j)
            bit[i][j] += a[x][y];
}

int query(int x, int y){
    int res = 0;
    for (int i = x; i > 0; i -= i & -i)
        for (int j = y; j > 0; j -= j & -j)
            res += bit[i][j];
    return res;
}

int query(int t, int l, int b, int r){
    return query(t - 1, l - 1) + query(b, r)
        - query(b, l - 1) - query(t - 1, r);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++){
            char x; cin >> x;
            if (x == '*'){
                a[i][j] = 1; update(i, j);
            }
            else a[i][j] = -1;
        }
    for (int i = 1; i <= q; i++){
        int cmd, t, l, b, r;
        cin >> cmd >> t >> l;
        if (cmd == 1){
            a[t][l] *= -1; update(t, l);
        }
        else {
            cin >> b >> r;
            cout << query(t, l, b, r) << '\n';
        }
    }
}