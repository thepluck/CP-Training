#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;
const int INF = 2e9;

mt19937 rng(chrono::high_resolution_clock
::now().time_since_epoch().count());

int rand(int l, int r) {
    return uniform_int_distribution <int> (l, r)(rng);
}

int add(int x, int y, int MOD) {
    if ((x += y) >= MOD) x -= MOD;
    return x;
}

int sub(int x, int y, int MOD) {
    if ((x -= y) < 0) x += MOD;
    return x;
}

int mul(int x, int y, int MOD) {
    return (long long)x * y % MOD;
}

const int MOD[2] = {1000006417, 1000007429};

struct hash_t {
    static const int K = 2;

    array <int, K> val;

    hash_t() {val[0] = val[1] = 0;}

    hash_t(array <int, K> val): val(val) {}

    hash_t& operator += (const hash_t &o) {
        for (int i = 0; i < K; i++)
            val[i] = add(val[i], o.val[i], MOD[i]);
        return *this;
    }

    hash_t operator + (const hash_t &o) const {
        return hash_t(*this) += o;
    }

    hash_t& operator -= (const hash_t &o) {
        for (int i = 0; i < K; i++)
            val[i] = sub(val[i], o.val[i], MOD[i]);
        return *this;
    }

    hash_t operator - (const hash_t &o) const {
        return hash_t(*this) -= o;
    }

    hash_t& operator *= (const hash_t &o) {
        for (int i = 0; i < K; i++)
            val[i] = mul(val[i], o.val[i], MOD[i]);
        return *this;
    }

    hash_t operator * (const hash_t &o) const {
        return hash_t(*this) *= o;
    }

    bool operator < (const hash_t &o) const {
        return val < o.val;
    }

    bool operator == (const hash_t &o) const {
        return val == o.val;
    }

    bool operator > (const hash_t &o) const {
        return val > o.val;
    }
};

ostream& operator << (ostream &os, const hash_t &o) {
    return os << '(' << o.val[0] << " ," << o.val[1] << ')';
}

using ans_t = tuple <int, hash_t, hash_t>;

const hash_t B({1000002233, 1000003111});

vector <int> adj[N]; hash_t pw[N];
int num[N], dep[N], par[N];
hash_t hashT[N]; bool ban[N];
vector <pair <int, int>> edge;


void DFSSpan(int u) {
    ban[u] = true;
    for (int v : adj[u])
        if (!ban[v]) {
            dep[v] = dep[u] + 1;
            par[v] = u; DFSSpan(v);
        }
}

void DFSHash(int u, int p) {
    hashT[u] = hash_t({1, 1}); dep[u] = 0;
    for (int v : adj[u])
        if (v != p && !ban[v]) {
            DFSHash(v, u);
            dep[u] = max(dep[u], dep[v] + 1);
        }
    hash_t var({num[dep[u]], num[dep[u]]});
    for (int v : adj[u])
        if (v != p && !ban[v])
            hashT[u] *= (hashT[v] + var);
}

hash_t cyclicHash(const vector <hash_t> &v) {
    int n = v.size(); hash_t res({INF, INF});
    hash_t pre, suf;
    for (int i = 0; i < n; i++)
        suf += v[i] * pw[n - i - 1];
    hash_t tmp;
    for (int i = n - 1; i >= 0; i--) {
        tmp += v[i] * pw[n - i - 1];
    }
    for (int i = 0; i < n; i++) {
        res = min(res, pre + suf * pw[i]);
        pre = pre * B + v[i];
        suf -= v[i] * pw[n - i - 1];
    }
    return res;
}

ans_t hashGraph(int m) {
    DFSSpan(1); vector <hash_t> val;
    fill(ban + 1, ban + m + 1, false);
    DFSSpan(1);
    fill(ban + 1, ban + m + 1, false);
    for (auto e : edge) {
        int u, v, w; tie(u, v) = e;
        if (dep[u] > dep[v]) swap(u, v);
        if (u != par[v]) {
            w = v;
            while (true) {
                ban[w] = true;
                if (w == u) break;
                w = par[w];
            }
            w = v;
            while (true) {
                DFSHash(w, 0);
                val.push_back(hashT[w]);
                if (w == u) break;
                w = par[w];
            }
            break;
        }
    }
    hash_t lef = cyclicHash(val);
    reverse(val.begin(), val.end());
    hash_t rig = cyclicHash(val);
    if (rig < lef) swap(lef, rig);
    return make_tuple(m, lef, rig);
}

void solve() {
    int n; cin >> n;
    vector <ans_t> ans;
    while (n--) {
        int m; cin >> m;
        for (int i = 1; i <= m; i++)
            adj[i].clear();
        edge.clear();
        for (int i = 1; i <= m; i++) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edge.emplace_back(u, v);
        }
        ans.push_back(hashGraph(m));
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(),
    ans.end()), ans.end());
    cout << ans.size() << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 0; i < N; i++)
        num[i] = rand(1, 1e9);
    pw[0] = hash_t({1, 1});
    for (int i = 1; i < N; i++)
        pw[i] = pw[i - 1] * B;
    int nTest; cin >> nTest;
    while (nTest--) solve();
}