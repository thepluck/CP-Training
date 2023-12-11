#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector <int> col[N];


int solve(int x, int k){
    int n = col[x].size(); int res = 0;
    for (int i = 0, j = 0; i < n; i++){
        if (j < i) j = i;
        while (j < n - 1 && col[x][j + 1] - col[x][i] - (j + 1 - i) <= k) j++;
        res = max(res, j - i + 1);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("bai4.inp", "r", stdin);
    freopen("bai4.out", "w", stdout);
    int n, m, x, k, res = 0; 
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++){
        cin >> x; col[x].push_back(i);
    }
    for (int i = 1; i <= m; i++)
        res = max(res, solve(i, k));
    cout << res << '\n';
}