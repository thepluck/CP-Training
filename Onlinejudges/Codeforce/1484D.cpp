// Problem: D. Playlist
// Contest: Codeforces - Codeforces Round #709 (Div. 2, based on Technocup 2021 Final Round)
// URL: https://codeforces.com/contest/1484/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

struct segTree {
    vector <int> cnt;
    int n, lo, hi;
    
    segTree(int n): n(n), cnt(n * 4) {}
    
    void toggle(int i, int l, int r) {
        if (l == r) {
            cnt[i] ^= 1; return;
        }
        int m = (l + r) / 2;
        if (m >= lo) toggle(i * 2, l, m);
        else toggle(i * 2 + 1, m + 1, r);
        cnt[i] = cnt[i * 2] + cnt[i * 2 + 1];
    }
    
    int find(int i, int l, int r) {
        if (l > hi || r < lo
        || cnt[i] == 0) return -1;
        if (l == r) return l;
        int m = (l + r) / 2;
        int p = find(i * 2, l, m);
        if (p >= 0) return p;
        return find(i * 2 + 1, m + 1, r);
    }
    
    void toggle(int p) {
        lo = p; toggle(1, 0, n - 1);
    }
    
    int find(int l, int r) {
        if (l > r) return -1;
        lo = l; hi = r;
        return find(1, 0, n - 1);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector <int> nxt(n), a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        segTree ST(n);
        for (int i = 0; i < n; i++) {
            nxt[i] = (i + 1) % n;
            if (__gcd(a[i], a[nxt[i]]) == 1)
                ST.toggle(i);
        }
        int p = ST.find(0, n - 1);
        vector <int> del;
        while (p >= 0) {
            del.push_back(nxt[p] + 1);
            if (__gcd(a[nxt[p]],
            a[nxt[nxt[p]]]) == 1)
                ST.toggle(nxt[p]);
            ST.toggle(p);
            nxt[p] = nxt[nxt[p]];
            if (__gcd(a[p], a[nxt[p]]) == 1)
                ST.toggle(p);
            
            int q = ST.find(p + 1, n - 1);
            if (q < 0) q = ST.find(0, p);
            p = q;
        }
        cout << del.size();
        for (int p : del) cout << ' ' << p;
        cout << '\n';
    }
}