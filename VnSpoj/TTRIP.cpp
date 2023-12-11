#include <bits/stdc++.h>
using namespace std;

const int N = 150;
const int inf = 0x3f3f3f3f;
int path[N][N];
bitset <N> used;

template <class T, class _T>
bool chkmin(T &a, const _T &b){
    return a > b ? a = b, 1 : 0;
}

int main(){
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++){
            cin >> path[i][j];
            if (path[i][j] == 0 && i != j)
                path[i][j] = inf;
        }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                chkmin(path[i][j], path[i][k] + path[k][j]);
    int ans = 0; int pos = 1; used[1] = true;
    while (pos != n){
        int minpath = inf, next_pos;
        for (int i = 1; i < n; i++)
            if (!used[i] && minpath > path[pos][i]){
                minpath = path[pos][i]; next_pos = i;
            }
        if (minpath == inf) next_pos = n; 
        used[next_pos] = true;
        ans += path[pos][next_pos]; 
        pos = next_pos;
    }
    cout << ans << '\n';
}