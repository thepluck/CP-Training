#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;
const int N = 305;
int w[N][N], n, dis[N];
bitset <N> used;

int prim(){
    int cnt = 0, total = 0; used[0] = true; dis[0] = inf;
    while (cnt < n){
        auto pt = min_element(dis + 1, dis + n + 1);
        total += *pt; used[pt - dis] = true; 
        dis[pt - dis] = inf; cnt++;
        for (int i = 1; i <= n; i++)
            if (!used[i]) dis[i] = min(dis[i], w[pt - dis][i]);
    }
    return total;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> dis[i]; w[0][i] = w[i][0] = dis[i];
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> w[i][j];
    cout << prim() << '\n';
}