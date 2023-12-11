#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

using ii = pair <int, int>;

const int N = 1005;
int dis[N][N];
bool bl[N][N]; char a[N][N];
char cc[] = {'L', 'R', 'U', 'D'};
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
ii dq[2 * N * N]; int st, en;

int main(){
    freopen("maze.inp", "r", stdin);
    freopen("maze.out", "w", stdout);
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%s", a[i] + 1);
    memset(dis, -1, sizeof dis);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] == 'C'){
                bl[i][j] = 1;
                int x = i, y = j - 1;
                while (y > 0 && a[x][y] != 'W'
                && a[x][y] != 'C'){
                    bl[x][y] = 1; y--;
                }
                x = i, y = j + 1;
                while (y <= m && a[x][y] != 'W'
                && a[x][y] != 'C'){
                    bl[x][y] = 1; y++;
                }
                x = i - 1; y = j;
                while (x > 0 && a[x][y] != 'W'
                && a[x][y] != 'C'){
                    bl[x][y] = 1; x--;
                }
                x = i + 1; y = j;
                while (x <= n && a[x][y] != 'W'
                && a[x][y] != 'C'){
                    bl[x][y] = 1; x++;
                }
            }
    int x = 0, y = 0; st = N * N; en = st;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            if (a[i][j] == 'S'){
                x = i; y = j;
            }
            if (a[i][j] == 'L' || a[i][j] == 'R'
            || a[i][j] == 'U' || a[i][j] == 'D')
                bl[i][j] = 0;
        }
    if (!bl[x][y]){
        dq[en++] = {x, y}; dis[x][y] = 0;
    }
    while (en - st){
        tie(x, y) = dq[st++];
        for (int k = 0; k < 4; k++)
            if (a[x][y] == cc[k] || a[x][y] == '.' ||
                a[x][y] == 'S'){
                int i = x + dx[k], j = y + dy[k];
                if (i == 0 || i > n) continue;
                if (j == 0 || j > m) continue;
                if (bl[i][j] || ~dis[i][j]) continue;
                if (a[x][y] == cc[k]){
                    dis[i][j] = dis[x][y];
                    dq[--st] = {i, j};
                }
                else {
                    dis[i][j] = dis[x][y] + 1;
                    dq[en++] = {i, j};
                }
            }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] == '.')
                printf("%d\n", dis[i][j]);
}