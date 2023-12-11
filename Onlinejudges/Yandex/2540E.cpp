/// minimize number of inversions on tree by changing root

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

    int countLE(int l, int r, int val) {
        if (l > r || val < low) return 0;
        if (high <= val) return r - l + 1;
        int lb = cnt[l], rb = cnt[r + 1];
        return lef->countLE(lb, rb - 1, val)
        + rig->countLE(l - lb, r - rb, val);
    }

    int countGE(int l, int r, int val) {
        if (l > r || val > high) return 0;
        if (low >= val) return r - l + 1;
        int lb = cnt[l], rb = cnt[r + 1];
        return lef->countGE(lb, rb - 1, val)
        + rig->countGE(l - lb, r - rb, val);
    }

    int countG(int l, int r, int val) {
        return r - l + 1 - countLE(l, r, val);
    }

    int countL(int l, int r, int val) {
        return r - l + 1 - countGE(l, r, val);
    }

    int cntE(int l, int r, int val) {
        if (l > r) return 0;
        if (low == high) return r - l + 1;
        int lb = cnt[l], rb = cnt[r + 1];
        int mid = (low + high) / 2;
        if (val <= mid)
            return lef->cntE(lb, rb - 1, val);
        return rig->cntE(l - lb, r - rb, val);
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

const int N = 200005;

int val[N], tin[N], tout[N], timer;
vector <int> adj[N];
pair <long long, int> res(0, 1);

void DFS1(int u, int p) {
    tin[u] = timer++;
    for (int v : adj[u])
        if (v != p) DFS1(v, u);
    tout[u] = timer;
}

void DFS2(int u, int p, long long inv, wavelet &wlt) {
    res = min(res, {inv, u});
    for (int v : adj[u])
        if (v != p) DFS2(v, u,
            inv - wlt.countG(tin[v], tout[v] - 1, val[u])
            + wlt.countG(tin[1], tout[1] - 1, val[v]) -
            wlt.countG(tin[v], tout[v] - 1, val[v]), wlt);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> val[i];
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS1(1, 0); vector <int> arr(n);
    for (int i = 1; i <= n; i++)
        arr[tin[i]] = val[i];
    wavelet wlt(arr, 1, n);
    for (int i = 1; i <= n; i++)
        res.first += wlt.countG(tin[i], tout[i] - 1, val[i]);
    DFS2(1, 0, res.first, wlt);
    cout << res.second << ' ' << res.first << '\n';
}