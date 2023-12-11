#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 1e5 + 10;
bool flip[maxn << 2];
int node[maxn << 2];
typedef const int& ci;

void update(ci i, ci lo, ci hi, ci a, ci b){
    if (lo >= a && hi <= b){
        flip[i] ^= 1;
        node[i] = hi - lo + 1 - node[i];
        return;
    }
    int mi = (hi + lo) >> 1;
    if (a <= mi) update(i << 1, lo, mi, a, b);
    if (mi < b) update(i << 1 | 1, mi + 1, hi, a, b);
    node[i] = node[i << 1] + node[i << 1 | 1];
    if (flip[i]) node[i] = hi - lo + 1 - node[i];
}

int get(ci i, ci lo, ci hi, ci a, ci b, int f){
    if (lo >= a && hi <= b)
        if (f) return hi - lo + 1 - node[i];
        else return node[i];
    int mi = (lo + hi) >> 1;
    f ^= flip[i];
    int res = 0;
    if (a <= mi) res += get(i << 1, lo, mi, a, b, f);
    if (mi < b) res += get(i << 1 | 1, mi + 1, hi, a, b, f);
    f ^= flip[i]; return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++){
        int c, u, v;
        cin >> c >> u >> v;
        if (c == 0) update(1, 1, n, u, v);
        else cout << get(1, 1, n, u, v, 0) << '\n';
    }
}
