#include <bits/stdc++.h>
using namespace std;

class modular{
public:
    using ll = long long; ll val;
    static const int mod = 1e9 + 7;

    modular(): val(0){}

    template <typename T>
    modular(T _val): val(_val % mod){
        if (val < 0) val += mod;
    }

    bool operator != (const modular &o){
        return val != o.val;
    }

    bool operator == (const modular &o){
        return val == o.val;
    }

    friend modular operator + (const modular &a, const modular &b){
        return modular(a.val + b.val);
    }

    friend modular operator - (const modular &a, const modular &b){
        return modular(a.val - b.val);
    }

    friend modular operator * (const modular &a, const modular &b){
        return modular(a.val * b.val);
    }

    friend void operator += (modular &a, const modular &b){
        a = modular(a.val + b.val);
    }

    friend void operator -= (modular &a, const modular &b){
        a = modular(a.val - b.val);
    }

    friend void operator *= (modular &a, const modular &b){
        a = modular(a.val * b.val);
    }

    template <class T>
    friend modular pow(const modular &a, const T &k){
        modular res = 1, x = a;
        for (T i = k; i > 0; i >>= 1){
            if (i & 1) res *= x; x = x * x;
        }
        return res;
    }

    friend modular inverse(const modular &a){
        return pow(a, modular::mod - 2);
    }

    friend modular operator / (const modular &a, const modular &b){
        return a * inverse(b);
    }

    friend void operator /= (modular &a, const modular &b){
        return a = a * inverse(b);
    }

    friend istream& operator >> (istream &is, modular &a){
        modular::ll x; is >> x; a = modular(x); return is;
    }

    friend ostream& operator << (ostream &os, const modular &a){
        return os << a.val;
    }
};

#define all(v) begin(v), end(v)
const int N = 1e5 + 5;
vector <int> adj[N]; modular dp[N][3];
modular pre0[N], pre1[N], suf0[N], suf1[N];

void dfs_init(int v, int p){
    if (p != 0) adj[v].erase(find(all(adj[v]), p));
    for (int c : adj[v]) dfs_init(c, v);
}

void dfs_sol(int v){
    for (int c : adj[v]) dfs_sol(c);
    modular c1, c2, c3, c4, pre;
    fill_n(pre0, size(adj[v]), 1);
    fill_n(pre1, size(adj[v]), 1);
    fill_n(suf0, size(adj[v]) + 1, 1);
    fill_n(suf1, size(adj[v]) + 1, 1);
    if (!adj[v].empty()){
        pre0[0] = dp[adj[v][0]][0];
        pre1[0] = dp[adj[v][0]][1];
    }
    for (int i = 1; i < size(adj[v]); i++){
        pre0[i] = pre0[i - 1] * dp[adj[v][i]][0];
        pre1[i] = pre1[i - 1] * dp[adj[v][i]][1];
    }
    for (int i = size(adj[v]) - 1; ~i; i--){
        suf0[i] = suf0[i + 1] * dp[adj[v][i]][0];
        suf1[i] = suf1[i + 1] * dp[adj[v][i]][1];
    }
    if (!adj[v].empty()){
        c1 = dp[adj[v][0]][2] * suf1[1];
        c3 = dp[adj[v][0]][2] * suf0[1];
    }
    for (int i = 1; i < size(adj[v]); i++){
        c1 += dp[adj[v][i]][2] * pre1[i - 1] * suf1[i + 1];
        c3 += dp[adj[v][i]][2] * pre0[i - 1] * suf0[i + 1];
    }
    for (int i = 0; i < size(adj[v]); i++){
        c4 += dp[adj[v][i]][2] * suf0[i + 1] * pre;
        pre *= dp[adj[v][i]][0];
        pre += dp[adj[v][i]][2] * (i ? pre0[i - 1] : 1);
    }
    c2 = adj[v].empty() ? 1 : pre1[size(adj[v]) - 1];
    dp[v][0] = c1 + c4 + c2;
    dp[v][1] = c4; dp[v][2] = c2 + c3;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    dfs_init(1, 0); dfs_sol(1);
    cout << dp[1][0] << '\n';
}
