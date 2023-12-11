#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 5;
int a[maxn][maxn], key[maxn], n;
bitset <maxn> avail;
const int inf = 0x3f3f3f3f;

int get_min(){
    int minv = inf, id;
    for (int i = 1; i <= n; i++)
        if (avail[i] && key[i] < minv){
            minv = key[i]; id = i;
        }
    return id;
}

void change_key(int u){
    for (int v = 1; v <=  n; v++)
        if (avail[v] && a[u][v] < key[v])
            key[v] = a[u][v];
}

int prim(){
    avail.set();
    memset(key, 0x3f, sizeof key);
    int cnt = 1; int weight = 0;
    avail[1] = false;
    change_key(1);
    while (cnt < n){
        int u = get_min();
        avail[u] = false;
        weight += key[u];
        change_key(u); cnt++;
    }
    return weight;
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    cout << prim();
}
