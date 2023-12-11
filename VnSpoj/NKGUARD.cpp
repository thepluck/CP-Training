#include <bits/stdc++.h>
using namespace std;

int h[1000][1000], n, m;
bitset <1000> used[1000];
int r[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int c[] = {-1, 0, 1, -1, 1, -1, 0, 1};
bool is_node(int i, int j){
    return i > 0 && j > 0 && i <= n && j <= m;
}

bool dfs(int i, int j){
    used[i][j] = true; bool res = true;
    for (int k = 0; k < 8; k++)
        if (is_node(i + r[k], j + c[k])){
            if (h[i + r[k]][j + c[k]] > h[i][j]) 
                res = false;
            if (h[i + r[k]][j + c[k]] == h[i][j] && !used[i + r[k]][j + c[k]]) 
                res &= dfs(i + r[k], j + c[k]);
        }
    return res;
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> h[i][j];
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!used[i][j]) cnt += dfs(i, j);
    cout << cnt << '\n';
}