#include <bits/stdc++.h>
using namespace std;

#define lb lower_bound
const int N = 5e5 + 5;
using ll = long long;
const ll inf = 0x3f3f3f3f3f3f3f3f;

template <class T>
void read_n(T *a, int n){
    for (int i = 0; i < n; cin >> a[i++]);
}

template <class X, class Y>
bool chkmin(X &a, const Y &b){
    return a > b ? a = b, 1 : 0;
}

class fenwick{
private:
    ll bit[N]; int n;
public:
    fenwick(int _n): n(_n + 5){
        fill_n(bit + 1, n, 0);
    }

    void update(int i, int val){
        for (; i <= n; i += i & -i) 
            bit[i] += val;
    }

    ll get(int i){
        ll res = 0;
        for (; i > 0; i -= i & -i)
            res += bit[i];
        return res;
    }
};

int a[N], b[N], p[N]; ll dp[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n; read_n(a + 1, n); read_n(p + 1, n);
    cin >> m; read_n(b + 1, m); fill_n(dp + 1, m, inf); fenwick f(m);
    for (int i = 1; i <= n; i++){
        int j = lb(b + 1, b + m + 1, a[i]) - b;
        f.update(1, p[i]); if (p[i] > 0) f.update(j + 1, -p[i]);
        if (a[i] == b[j])
            chkmin(dp[j], dp[j - 1] - p[i] + f.get(j) - f.get(j + 1));
    }
    if (dp[m] + f.get(m + 1) >= 1e15) return puts("NO"), 0;
    cout << "YES\n" << dp[m] + f.get(m + 1) << '\n';
}