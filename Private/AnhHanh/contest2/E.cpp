#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
const int LG = 17;

struct SuffixArray {
    vector <int> sa, rnk, lcp;

    SuffixArray(string s): sa(s.size() + 1),
    rnk(s.size()), lcp(s.size()) {
        s.push_back(0); int n = s.size();
        vector <int> nsa(n), cl(n), ncl(n);
        vector <int> cnt(max(n, 256));
        for (int i = 0; i < n; i++)
            cnt[s[i]]++;
        for (int i = 1; i < 256; i++)
            cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; i--)
            sa[--cnt[s[i]]] = i;
        for (int i = 1; i < n; i++) {
            cl[sa[i]] = cl[sa[i - 1]];
            if (s[sa[i]] != s[sa[i - 1]])
                cl[sa[i]]++;
        }
        for (int l = 1; l < n; l <<= 1) {
            fill(cnt.begin(), cnt.end(), 0);
            for (int i = 0; i < n; i++)
                cnt[cl[i]]++;
            for (int i = 1; i < n; i++)
                cnt[i] += cnt[i - 1];
            for (int i = n - 1; i >= 0; i--) {
                int j = (sa[i] - l + n) % n;
                nsa[--cnt[cl[j]]] = j;
            }
            sa.swap(nsa); ncl[sa[0]] = 0;
            for (int i = 1; i < n; i++) {
                ncl[sa[i]] = ncl[sa[i - 1]];
                if (cl[sa[i]] != cl[sa[i - 1]])
                    ncl[sa[i]]++;
                else if (cl[(sa[i] + l) % n]
                != cl[(sa[i - 1] + l) % n])
                    ncl[sa[i]]++;
            }
            cl.swap(ncl);
        }
        sa.erase(sa.begin()); n--;
        for (int i = 0; i < n; i++)
            rnk[sa[i]] = i;
        for (int i = 0, l = 0; i < n; i++) {
            if (rnk[i] == n - 1) l = 0;
            else {
                int j = sa[rnk[i] + 1];
                while (max(i, j) + l < n &&
                s[i + l] == s[j + l]) l++;
                lcp[rnk[i]] = l;
            }
            if (l) l--;
        }
    }
};

struct RMQ {
    vector <int> mi[LG], ma[LG];

    RMQ(const vector <int> &a) {
        int n = a.size();
        mi[0] = ma[0] = a;
        for (int k = 1; k < LG; k++) {
            mi[k].resize(n); ma[k].resize(n);
            for (int i = 0; i + (1 << k) <= n; i++) {
                mi[k][i] = min(mi[k - 1][i],
                mi[k - 1][i + (1 << (k - 1))]);
                ma[k][i] = max(ma[k - 1][i],
                ma[k - 1][i + (1 << (k - 1))]);
            }
        }
    }

    int getMin(int l, int r) {
        int k = __lg(r - l + 1);
        return min(mi[k][l],
        mi[k][r + 1 - (1 << k)]);
    }

    int getMax(int l, int r) {
        int k = __lg(r - l + 1);
        return max(ma[k][l],
        ma[k][r + 1 - (1 << k)]);
    }
};

int lef[N], rig[N], BIT[N];

void update(int i) {
    for (i++; i < N; i += i & -i) BIT[i]++;
}

int query(int i) {
    int res = 0;
    for (i++; i > 0; i -= i & -i) res += BIT[i];
    return res;
}

int main() {
    freopen("carpet.inp", "r", stdin);
    freopen("carpet.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    int n = s.size();
    SuffixArray SA(s);
    RMQ rsa(SA.sa), rlcp(SA.lcp);
    for (int i = 0, l = 0; i < n; i++) {
        while (l < min(i, n - i)) {
            int j = SA.rnk[i];
            int lo = 0, hi = j;
            while (lo < hi) {
                int mi = (lo + hi) / 2;
                if (rlcp.getMin(mi, j - 1) > l)
                    hi = mi;
                else lo = mi + 1;
            }
            int j1 = hi;
            lo = j, hi = n - 1;
            while (lo < hi) {
                int mi = (lo + hi + 1) / 2;
                if (rlcp.getMin(j, mi - 1) > l)
                    lo = mi;
                else hi = mi - 1;
            }
            int j2 = lo;
            if (rsa.getMin(j1, j2) < i - l) l++;
            else break;
        }
        lef[i] = l; if (l) l--;
    }
    long long res = 0;
    for (int i = n - 1, l = 0; i >= 0; i--) {
        while (l < min(i + 1, n - i - 1)) {
            int j = SA.rnk[i - l];
            int lo = 0, hi = j;
            while (lo < hi) {
                int mi = (lo + hi) / 2;
                if (rlcp.getMin(mi, j - 1) > l)
                    hi = mi;
                else lo = mi + 1;
            }
            int j1 = hi;
            lo = j, hi = n - 1;
            while (lo < hi) {
                int mi = (lo + hi + 1) / 2;
                if (rlcp.getMin(j, mi - 1) > l)
                    lo = mi;
                else hi = mi - 1;
            }
            int j2 = lo;
            if (rsa.getMax(j1, j2) > i) l++;
            else break;
        }
        rig[i] = l; if (l) l--;
        if (lef[i]) res += query(i + lef[i]);
        if (rig[i]) update(i - rig[i] + 1);
    }
    cout << res << '\n';
}