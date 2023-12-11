#include <bits/stdc++.h>
using namespace std;

using ii = pair <int, int>;
int a[1005][1005], dis[1005][1005];
bool used[1005][1005];
int n, m, t; 

int r[] = {-1, 0, 0, 1};
int c[] = {0, -1, 1, 0};

bool is_node(int i, int j){
    return i > 0 && j > 0 && i <= n && j <= m;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            char x; cin >> x; a[i][j] = x - '0';
        }
    queue <ii> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            for (int k = 0; k < 4; k++)
                if (is_node(i + r[k], j + c[k]))
                    if (a[i][j] == a[i + r[k]][j + c[k]]){
                        q.push(ii(i, j)); used[i][j] = true; break;
                    }
        }
    if (q.empty()){
        while(t--){
            int i, j; long long p; cin >> i >> j >> p; cout << a[i][j] << '\n';
        }
        return 0; 
    }
    while (!q.empty()){
        int i, j; tie(i, j) = q.front(); q.pop();
        for (int k = 0; k < 4; k++)
            if (is_node(i + r[k], j + c[k]) && !used[i + r[k]][j + c[k]]){
                dis[i + r[k]][j + c[k]] = dis[i][j] + 1;
                used[i + r[k]][j + c[k]] = true; q.push({i + r[k], j + c[k]});
            }
    }
    while (t--){
        int i, j; long long p; cin >> i >> j >> p;
        if (dis[i][j] >= p) cout << a[i][j] << '\n';
        else {
            p = (p - dis[i][j]) % 2;
            cout << (a[i][j] ^ p) << '\n';
        }
    }
}