#define forn(i, j, k) for (int i = (j); i <= (k); i++)
#define ford(i, j, k) for (int i = (j); i >= (k); i--)
#include <bits/stdc++.h>
using namespace std;
long long bit[int(1e6 + 1)], a[int(1e6 + 1)];
int n;

void init(){
    if (fopen("BIT.inp", "r")){
        freopen("BIT.inp", "r", stdin);
        freopen("BIT.out", "w", stdout);
    }
}

void update(int i, int val){
    for (; i <= n; i += i & (-i)) bit[i] += val;
}

int get(int i){
    if (i == 0) return 0;
    int ans = 0;
    for (; i > 0; i -= i & (-i)) ans += bit[i];
    return ans;
}

void build(){
    for (int i = 1; i <= n; i++){
        bit[i] += a[i];
        int j = i + (i & -i);
        if (j <= n) bit[j] += bit[i];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    init(); cin >> n;
    forn(i, 1, n) cin >> a[i];
    memset(bit, 0, sizeof bit); build();
    int t; cin >> t;
    char x; int u, v;
    while (t--){
        cin >> x >> u >> v;
        if (x == 'q'){
            cout << get(v) - get(u - 1) << '\n';
        }
        else update(u, v);
    }
    return 0;
}