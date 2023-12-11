/// random
/// :(((((((((((((((((((((())))))))))))))))))))))
/// ngu nhu con cko
#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().
time_since_epoch().count());

const int N = 3e5 + 5;
int ch[N][2], mn[N], mx[N];
vector <int> lmao;

int main(){
    freopen("SBBCFFFFS.inp", "r", stdin);
    freopen("SBBCFFFFS.out", "w", stdout);
    int n, m, k; cin >> n >> m >> k;
    for (int i = 1, x, y; i <= m; i++)
        cin >> ch[i + n][0] >> ch[i + n][1];
    string read; cin.ignore();
    for (int i = 1; i <= n; i++)
        lmao.push_back(i);
    shuffle(lmao.begin(), lmao.end(), rng);
    for (int x : lmao) cout << x << ' ';
}