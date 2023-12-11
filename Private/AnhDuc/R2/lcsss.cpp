/// Time : O((n+m)log(n+m) + d^2)
/// Memory : O(n + d^2))
#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmax(X &a, const Y &b) {
    return a < b ? a = b, 1 : 0;
}

const int V = 5000;
const int N = 100005;

int _dp[V + 5][2 * V + 5];
int a[N], b[N];
int _tr[V + 5][2 * V + 5];

#define dp(d, k) _dp[(d)][(k) + V]
#define tr(d, k) _tr[(d)][(k) + V]

struct SuffixArray {
    vector <int> sa, rnk, lcp;

    SuffixArray(vector <int> s): sa(s.size() + 1),
    rnk(s.size()), lcp(s.size()) {
        s.push_back(0); int n = s.size();
        vector <int> nsa(n), cl(n), ncl(n);
        vector <int> cnt(max(n, 2000));
        for (int i = 0; i < n; i++)
            cnt[s[i]]++;
        for (int i = 1; i < 2000; i++)
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

const int LG = 18;

struct RMQ {
    vector <int> mi[LG];

    RMQ(const vector <int> &a) {
        int n = a.size(); mi[0] = a;
        for (int k = 1; k < LG; k++) {
            mi[k].resize(n);
            for (int i = 0; i + (1 << k) <= n; i++)
                mi[k][i] = min(mi[k - 1][i],
                mi[k - 1][i + (1 << (k - 1))]);
        }
    }

    int getMin(int l, int r) {
        if (l > r) swap(l, r);
        int k = __lg(r - l);
        return min(mi[k][l], mi[k][r - (1 << k)]);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int m, n; cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        cin >> a[i]; a[i]++;
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i]; b[i]++;
    }
    memset(_dp, -1, sizeof _dp);
    dp(0, 0) = 0; vector <int> ans;
    vector <int> tmp(a + 1, a + m + 1);
    tmp.push_back(1);
    copy(b + 1, b + n + 1, back_inserter(tmp));
    SuffixArray arr(tmp); RMQ rmq(arr.lcp);
    for (int d = 0; ; d++) {
        for (int k = -d; k <= d; k += 2) {
            if (dp(d, k) < 0) continue;
            if (dp(d, k) < m && dp(d, k) + k < n)
                dp(d, k) += rmq.getMin(arr.rnk[dp(d, k)],
                arr.rnk[dp(d, k) + k + m + 1]);
        }
        if (dp(d, n - m) == m) {
            int k = n - m;
            while (d > 0) {
                int k1 = tr(d, k), dp1;
                if (k1 < k) dp1 = dp(d - 1, k1);
                else dp1 = dp(d - 1, k1) + 1;
                for (int i = dp(d, k); i > dp1; i--)
                    ans.push_back(a[i]);
                k = k1; d--;
            }
            for (int i = dp(0, 0); i > 0; i--)
                ans.push_back(a[i]);
            reverse(ans.begin(), ans.end());
            cout << ans.size() << '\n';
            for (int x : ans) cout << x - 1 << ' ';
            return 0;
        }
        for (int k = -d; k <= d; k += 2) {
            if (dp(d, k) < 0) continue;
            if (dp(d, k) < m)
                if (cmax(dp(d + 1, k - 1), dp(d, k) + 1))
                    tr(d + 1, k - 1) = k;
            if (dp(d, k) + k < n)
                if (cmax(dp(d + 1, k + 1), dp(d, k)))
                    tr(d + 1, k + 1) = k;
        }
    }
}
