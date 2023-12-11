#include <bits/stdc++.h>

using namespace std;

struct SuffixArray {
    vector <int> sa, rnk, lcp;

    SuffixArray(string s): sa(s.size() + 1),
    rnk(s.size()), lcp(s.size()) {

    }
};

const int N = 1100005;
const int LOG = 20;

int mn[LOG][N], mx[LOG][N], ans[N];
int sa[N], rnk[N], lcp[LOG][N];
int nsa[N], cl[N], ncl[N], cnt[N], lg[N];
string t[N];

int get(int l, int r) {
    int k = lg[r - l];
    return min(lcp[k][l], lcp[k][r - (1 << k)]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int m; cin >> m; string s;
    for (int i = 0; i < m; i++) {
        cin >> t[i]; s += t[i]; s.push_back(0);
    }
    int n = s.size();
    for (int i = 2; i < N; i++)
        lg[i] = lg[i / 2] + 1;
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
        memset(cnt, 0, sizeof cnt);
        for (int i = 0; i < n; i++)
            cnt[cl[i]]++;
        for (int i = 1; i < n; i++)
            cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; i--) {
            int j = (sa[i] - l + n) % n;
            nsa[--cnt[cl[j]]] = j;
        }
        swap(sa, nsa); ncl[sa[0]] = 0;
        for (int i = 1; i < n; i++) {
            ncl[sa[i]] = ncl[sa[i - 1]];
            if (cl[sa[i]] != cl[sa[i - 1]])
                ncl[sa[i]]++;
            else if (cl[(sa[i] + l) % n]
            != cl[(sa[i - 1] + l) % n])
                ncl[sa[i]]++;
        }
        swap(cl, ncl);
    }
    for (int i = 0; i < n; i++) {
        rnk[sa[i]] = i;
        mn[0][i] = mx[0][i] = sa[i];
    }
    for (int i = 0, l = 0; i < n; i++) {
        if (rnk[i] == n - 1) l = 0;
        else {
            int j = sa[rnk[i] + 1];
            while (max(i, j) + l < n &&
            s[i + l] == s[j + l]) l++;
            lcp[0][rnk[i]] = l;
        }
        if (l) l--;
    }
    for (int k = 1; k < LOG; k++)
        for (int i = 0; i + (1 << k) <= n; i++) {
            mn[k][i] = min(mn[k - 1][i],
            mn[k - 1][i + (1 << (k - 1))]);
            mx[k][i] = max(mx[k - 1][i],
            mx[k - 1][i + (1 << (k - 1))]);
            lcp[k][i] = min(lcp[k - 1][i],
            lcp[k - 1][i + (1 << (k - 1))]);
        }
    int p = 0;
    for (int i = 0; i < m; i++) {
        int l = t[i].size(); vector<int> v;
        for (int j = p; j < p + l; j++) {
            int q = rnk[j] + 1;
            for (int k = LOG - 1; k >= 0; k--)
                if (q + (1 << k) <= n && mn[k][q] >= p && mx[k][q] < p + l)
                    q += 1 << k;
            if (q < n) ans[j] = get(rnk[j], q);
            q = rnk[j];
            for (int k = LOG - 1; k >= 0; k--)
                if (q - (1 << k) >= 0 && mn[k][q - (1 << k)] >= p && mx[k][q - (1 << k)] < p + l)
                    q -= 1 << k;
            if (q > 0) ans[j] = max(ans[j], get(q - 1, rnk[j]));
            v.push_back(j);
        }
        sort(v.begin(), v.end(), [&](int x, int y) {
            return rnk[x] < rnk[y];
        });
        for (int i = 0; i + 1 < v.size(); i++)
            ans[v[i]] = max(ans[v[i]], get(rnk[v[i]], rnk[v[i + 1]]));
        long long res = 1ll * l * (l + 1) / 2;
        for (int j = p; j < p + l; j++)
            res -= min(ans[j], p + l - j);
        cout << res << '\n'; p += l + 1;
    }
}