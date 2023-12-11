#include <bits/stdc++.h>

using namespace std;

struct wavelet {
    wavelet *lef, *rig;
    vector <int> cnt;
    int low, high;

    wavelet(vector <int> arr, int low, int high):
    low(low), high(high), lef(NULL), rig(NULL) {
        if (arr.empty() || low == high) return;
        cnt.resize(arr.size() + 1);
        int mid = (low + high) / 2;
        vector <int> arrLef, arrRig;
        for (int i = 0; i < arr.size(); i++) {
            cnt[i + 1] = cnt[i];
            if (arr[i] <= mid) {
                cnt[i + 1]++;
                arrLef.push_back(arr[i]);
            }
            else arrRig.push_back(arr[i]);
        }
        lef = new wavelet(arrLef, low, mid);
        rig = new wavelet(arrRig, mid + 1, high);
    }

    int cntLeq(int l, int r, int val) {
        if (l > r || val < low) return 0;
        if (high <= val) return r - l + 1;
        int lb = cnt[l], rb = cnt[r + 1];
        return lef->cntLeq(lb, rb - 1, val)
        + rig->cntLeq(l - lb, r - rb, val);
    }

    int cntEq(int l, int r, int val) {
        if (l > r) return 0;
        if (low == high) return r - l + 1;
        int lb = cnt[l], rb = cnt[r + 1];
        int mid = (low + high) / 2;
        if (val <= mid)
            return lef->cntEq(lb, rb - 1, val);
        return rig->cntEq(l - lb, r - rb, val);
    }

    int getKth(int l, int r, int k) {
        if (low == high) return low;
        int lb = cnt[l], rb = cnt[r + 1];
        if (k <= rb - lb)
            return lef->getKth(lb, rb - 1, k);
        k -= rb - lb;
        return rig->getKth(l - lb, r - rb, k);
    }
};

const int MAXN = 200005;
const int MOD = 1000000007;

vector <int> adj[MAXN], lst;
int cnt1[MAXN], cnt2[MAXN];
int siz[MAXN], dep[MAXN], par[MAXN];
int ans1[MAXN], ans2[MAXN], pw2[MAXN];
bool vis[MAXN]; int bel[MAXN], N, D;
int tin[MAXN], tout[MAXN], timer;

int Add(int x, int y) {
    if ((x += y) >= MOD) x -= MOD;
    return x;
}
 
int Sub(int x, int y) {
    if ((x -= y) < 0) x += MOD;
    return x;
}
 
int Mul(int x, int y) {
    return (long long)x * y % MOD;
}

void DFSsiz(int u, int p) {
    siz[u] = 1;
    for (int v : adj[u])
        if (v != p && !vis[v]) {
            DFSsiz(v, u);
            siz[u] += siz[v];
        }
}

int findCen(int u) {
    int p = 0, c = u;
    while (true) {
        bool flag = false;
        for (int v : adj[c])
            if (v != p && !vis[v] &&
            siz[v] * 2 >= siz[u]) {
                p = c; c = v;
                flag = true; break;
            }
        if (!flag) break;
    }
    return c;
}

void DFSdep(int u, int p) {
    bel[tin[u] = timer++] = u;
    for (int v : adj[u])
        if (v != p && !vis[v]) {
            dep[v] = dep[u] + 1;
            DFSdep(v, u);
        }
    tout[u] = timer;
}

void DFScen(int u) {
    DFSsiz(u, 0); int maxd1 = 0;
    vis[u = findCen(u)] = true;
    timer = 0; dep[u] = 0; DFSdep(u, 0);
    for (int i = tin[u]; i < tout[u]; i++) {
        cnt1[dep[bel[i]]]++;
        maxd1 = max(maxd1, dep[bel[i]]);
    }
    for (int i = 1; i <= maxd1; i++)
        cnt1[i] += cnt1[i - 1];
    ans1[u] += cnt1[min(maxd1, D)];
    ans2[u] += cnt1[min(maxd1, D - 1)];
    for (int v : adj[u]) {
        if (vis[v]) continue;
        int maxd2 = 0;
        for (int i = tin[v]; i < tout[v]; i++) {
            cnt2[dep[bel[i]]]++;
            maxd2 = max(maxd1, dep[bel[i]]);
        }
        for (int i = 1; i <= maxd2; i++)
            cnt2[i] += cnt2[i - 1];
        for (int i = tin[v]; i < tout[v]; i++) {
            if (dep[bel[i]] > D) continue;
            ans1[bel[i]] += cnt1[min
            (maxd1, D - dep[bel[i]])];
            ans1[bel[i]] -= cnt2[min
            (maxd2, D - dep[bel[i]])];
            if (dep[bel[i]] >= D) continue;
            ans2[bel[i]] += cnt1[min
            (maxd1, D - 1 - dep[bel[i]])];
            ans2[bel[i]] -= cnt2[min
            (maxd2, D - 1 - dep[bel[i]])];
        }
        for (int i = 1; i <= maxd2; i++)
            cnt2[i] = 0;
    }
    for (int i = 0; i <= maxd1; i++)
        cnt1[i] = 0;
    for (int v : adj[u])
        if (!vis[v]) DFScen(v);
}

void DFSpre(int u) {
    tin[u] = timer++;
    lst.push_back(dep[u]);
    for (int v : adj[u])
        if (v != par[u]) {
            dep[v] = dep[u] + 1;
            par[v] = u; DFSpre(v);
        }
    tout[u] = timer;
}

int Calc(vector <int> &cnt1,
vector <int> &cnt2) {
    int res = 0;
    for (int i = 1; i < cnt1.size(); i++) {
        cnt1[i] += cnt1[i - 1];
        cnt2[i] += cnt2[i - 1];
    }
    res = Add(res, pw2[cnt1.back()]);
    res = Sub(res, pw2[cnt2.back()]);
    int sum = 0;
    for (int i = cnt1.size() - 1; i > 0; i--) {
        int cur = pw2[cnt2[i - 1] + sum];
        cnt1[i] -= cnt1[i - 1];
        cnt2[i] -= cnt2[i - 1];
        cur = Mul(cur, Sub
        (pw2[cnt1[i]], pw2[cnt2[i]]));
        sum += cnt2[i];
        res = Sub(res, cur);
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 1; i < N; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> D;
    if (D == 1) return cout << N - 1, 0;
    bool odd = D & 1; D /= 2;
    DFScen(1); timer = 0; DFSpre(1);
    pw2[0] = 1;
    for (int i = 1; i <= N; i++)
        pw2[i] = Add(pw2[i - 1], pw2[i - 1]);
    wavelet WT(lst, 0, N);
    int res = 0;
    if (odd) {
        for (int u = 2; u <= N; u++) {
            vector <int> cnt1(1, 0), cnt2(1, 0);
            int p = par[u];
            cnt1.push_back(WT.cntLeq(tin[u],
            tout[u] - 1, dep[u] + D));
            cnt2.push_back(WT.cntLeq(tin[u],
            tout[u] - 1, dep[u] + D - 1));
            cnt1.push_back(ans1[p] - WT.cntLeq
            (tin[u], tout[u] - 1, dep[p] + D));
            cnt2.push_back(ans2[p] - WT.cntLeq
            (tin[u], tout[u] - 1, dep[p] + D - 1));
            res = Add(res, Calc(cnt1, cnt2));

        }
    } else {
        for (int u = 1; u <= N; u++) {
            vector <int> cnt1(1, 0), cnt2(1, 0);
            for (int v : adj[u])
                if (v != par[u]) {
                    cnt1.push_back(WT.cntLeq(tin[v],
                    tout[v] - 1, dep[u] + D));
                    cnt2.push_back(WT.cntLeq(tin[v],
                    tout[v] - 1, dep[u] + D - 1));
                }
            if (par[u]) {
                cnt1.push_back(ans1[u] - accumulate
                (cnt1.begin(), cnt1.end(), 1));
                cnt2.push_back(ans2[u] - accumulate
                (cnt2.begin(), cnt2.end(), 1));
            }
            res = Add(res, Calc(cnt1, cnt2));
        }
        res = Add(res, res);
    }
    cout << res << '\n';
}