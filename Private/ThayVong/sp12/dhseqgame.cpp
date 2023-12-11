#include <bits/stdc++.h>
using namespace std;

long long game(int d, vector<int> a){
    using ll = long long;
    int n = a.size(); vector <ll> t(n);
    for (int i = 0; i < n; i++)
        t[i] = -1ll * i * d + a[i];
    sort(t.begin(), t.end());
    ll mid = t[n / 2], res = 0;
    for (int i = 0; i < n; i++)
        res += abs(mid + 1ll * i * d - a[i]);
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("dhseqgame.inp", "r", stdin);
    freopen("dhseqgame.out", "w", stdout);
    int n, d; cin >> n >> d;
    vector <int> a(n);
    for (int &x : a) cin >> x;
    cout << game(d, a) << '\n';
}