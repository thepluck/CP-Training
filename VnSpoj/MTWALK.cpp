#include <bits/stdc++.h>
using namespace std;

using ii = pair <int, int>;
int h[105][105], n, x, y;
bitset <105> used[105];

int r[] = {-1, 0, 0, 1};
int c[] = {0, -1, 1, 0};

bool av(int i, int j, int lo, int hi){
    return h[i][j] >= lo && h[i][j] <= hi && !used[i][j];
}

bool bfs(int lo, int hi){
    queue <ii> q; q.push({1, 1});
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) used[i][j] = false;
    used[1][1] = true;
    while (!q.empty()){
        tie(x, y) = q.front(); q.pop();
        if (x == n && y == n) return true;
        for (int k = 0; k < 4; k++)
            if (av(x + r[k], y + c[k], lo, hi)){
                used[x + r[k]][y + c[k]] = true;
                q.push({x + r[k], y + c[k]});
            }
    }
    return false;
}

int main(){
    vector <int> val; cin >> n;
    int lo = 0, hi = 0, mi, res;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++){
            cin >> h[i][j]; hi = max(hi, h[i][j]);
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (h[i][j] <= h[1][1]) 
                val.push_back(h[i][j]);
    for (int i = 1; i <= n; i++){
        h[0][i] = h[i][0] = -1;
        h[n + 1][i] = h[i][n + 1] = -1;
    }
    while (lo <= hi){
        mi = (lo + hi) >> 1; bool flag = false;
        for (auto x : val) if (bfs(x, x + mi)){
            flag = true; break;
        }
        if (flag){
            res = mi; hi = mi - 1;
        }
        else lo = mi + 1;
    }
    cout << res << '\n';
}