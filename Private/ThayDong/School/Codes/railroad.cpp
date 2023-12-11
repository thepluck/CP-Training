#include <bits/stdc++.h>

using namespace std;

struct dsu {
    vector <int> par;

    dsu(int n) {
        par.resize(n);
        iota(begin(par), end(par), 0);
    }

    int find_set(int u) {
        return u == par[u] ?
        u : par[u] = find_set(par[u]);
    }

    bool union_set(int u, int v) {
        u = find_set(u);
        v = find_set(v);
        if (u == v) return false;
        par[v] = u; return true;
    }
};

struct edge {
    int u, v, w;
};

long long plan_roller_coaster
(vector <int> s, vector <int> t) {
    int n = s.size();
    long long ans = 0;
    vector <int> vals;
    vector <edge> lst;
    for (int i = 0; i < n; i++) {
        vals.push_back(s[i]);
        vals.push_back(t[i]);
    }
    sort(begin(vals), end(vals));
    vals.erase(unique(begin(vals),
    end(vals)), end(vals));
    vector <int> bal(vals.size() + 1);
    dsu ds(vals.size());
    for (int i = 0; i < n; i++) {
        s[i] = lower_bound(begin(vals),
        end(vals), s[i]) - begin(vals);
        t[i] = lower_bound(begin(vals),
        end(vals), t[i]) - begin(vals);
        bal[s[i]]++; bal[t[i]]--;
        ds.union_set(s[i], t[i]);
    }
    int m = vals.size(), cur = 1;
    for (int i = m - 1; i > 0; i--) {
        cur += bal[i];
        if (cur < 0) {
            ans += (long long)cur * 
            (vals[i - 1] - vals[i]);
            ds.union_set(i - 1, i);
        }
        else if (cur > 0)
            ds.union_set(i - 1, i);
        else lst.push_back({i - 1, i,
            vals[i] - vals[i - 1]});
    }
    sort(lst.begin(), lst.end(),
    [](const edge &p, const edge &q) {
        return p.w < q.w;
    });
    for (const edge &e : lst)
        if (ds.union_set(e.u, e.v))
            ans += e.w;
    return ans;
}

int main() {
    freopen("railroad.inp", "r", stdin);
    freopen("railroad.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector <int> s(n), t(n);
    for (int i = 0; i < n; i++)
        cin >> s[i] >> t[i];
    cout << plan_roller_coaster(s, t);
}