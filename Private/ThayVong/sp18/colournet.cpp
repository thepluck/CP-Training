#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair <int, int>;

const int N = 1005;
int col[N][N], tim[N][N], n, m, q;
int r[] = {-1, 0, 0, 1};
int c[] = {0, -1, 1, 0};
queue <ii> que;

bool is_node(int i, int j){
    return i > 0 && j > 0 &&
            i <= n && j <= m;
}

int main(){
    freopen("colournet.inp", "r", stdin);
    freopen("colournet.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> m >> q;
    memset(tim, -1, sizeof tim);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            char x; cin >> x;
            col[i][j] = x == 'R';
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            bool flag = 0;
            for (int k = 0; k < 4; k++){
                int x = i + r[k];
                int y = j + c[k];
                if (is_node(x, y) &&
                    col[i][j] == col[x][y])
                    flag = true;
            }
            if (flag){
                tim[i][j] = 0;
                que.emplace(i, j);
            }
        }
    while (!que.empty()){
        int i, j; tie(i, j) = que.front();
        que.pop();
        for (int k = 0; k < 4; k++){
            int x = i + r[k];
            int y = j + c[k];
            if (is_node(x, y) && 
                tim[x][y] == -1){
                    tim[x][y] = tim[i][j] + 1;
                    que.emplace(x, y);
                }
        }
    }
    while (q--){
        int i, j; ll st; cin >> i >> j >> st;
        if (tim[i][j] == -1 || tim[i][j] >= st)
            cout << (col[i][j] ? "R\n" : "B\n");
        else {
            int tmp = st - tim[i][j] & 1;
            cout << ((col[i][j] ^ tmp) ? "R\n" : "B\n");
        }
    }
}