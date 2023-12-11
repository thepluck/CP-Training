// Problem: B. The Bakery
// Contest: Codeforces - Codeforces Round #426 (Div. 1)
// URL: https://codeforces.com/problemset/problem/833/B
// Memory Limit: 256 MB
// Time Limit: 2500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

struct segTree {
    static const int N = 35005;
    
    int val[N * 4], tag[N * 4];
    int lo, hi, n;
    
    void init(int n) {
        memset(val, 0, sizeof val);
        memset(tag, 0, sizeof tag);
        this->n = n;
    }
    
    void pushTag(int i, int v) {
        val[i] += v; tag[i] += v;
    }
    
    void pushDown(int i) {
        pushTag(i * 2, tag[i]);
        pushTag(i * 2 + 1, tag[i]);
        tag[i] = 0;
    }
    
    void pushUp(int i) {
        val[i] = max(val[i * 2], val[i * 2 + 1]);
    }
    
    void update(int i, int l, int r, int v) {
        if (l > hi || r < lo) return;
        if (l >= lo && r <= hi)
            return pushTag(i, v);
        pushDown(i);
        int m = (l + r) / 2;
        update(i * 2, l, m, v);
        update(i * 2 + 1, m + 1, r, v);
        pushUp(i);
    }
    
    int query(int i, int l, int r) {
        if (l > hi || r < lo) return 0;
        if (l >= lo && r <= hi) return val[i];
        pushDown(i);
        int m = (l + r) / 2;
        return max(query(i * 2, l, m),
        query(i * 2 + 1, m + 1, r));
    }
    
    void update(int l, int r, int v) {
        lo = l; hi = r;
        update(1, 1, n, v);
    }
    
    int query(int l, int r) {
        lo = l; hi = r;
        return query(1, 1, n);
    }
} ST;

const int N = 35005;
const int K = 55;

int val[N], last[N], dp[K][N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> val[i];
    for (int i = 1; i <= k; i++) {
        memset(last, 0, sizeof last);
        ST.init(n);
        for (int j = i; j <= n; j++) {
            if (last[val[j]])
                ST.update(i, last[val[j]], -1);
            last[val[j]] = j;
            ST.update(j, j, dp[i - 1][j - 1]);
            ST.update(i, j, 1);
            dp[i][j] = ST.val[1];
        }    
    }
    cout << dp[k][n] << '\n';
}