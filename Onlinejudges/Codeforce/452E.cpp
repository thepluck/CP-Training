#include <bits/stdc++.h>

using namespace std;

struct SufArr {
    vector <int> sa, rnk, lcp;

    SufArr(string s): sa(s.size() + 1),
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
                if (cl[sa[i]] != cl[sa[i - 1]]
                || cl[(sa[i] + l) % n] !=
                cl[(sa[i - 1] + l) % n])
                    ncl[sa[i]]++;
            }
            cl.swap(ncl);
        }
        sa.erase(sa.begin()); n--;
        for (int i = 0; i < n; i++)
            rnk[sa[i]] = i;
        for (int i = 0, l = 0; i < n; i++) {
            if  (rnk[i] == n - 1) l = 0;
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

const int MOD = 1e9 + 7;

void add(int &x, int y) {
    if ((x += y) >= MOD) x -= MOD;
}

void sub(int &x, int y) {
    if ((x -= y) < 0) x += MOD;
}

void mul(int &x, int y) {
    x = (long long)x * y % MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    int a = s1.size(), b = s2.size();
    int c = s3.size();
    SufArr SA(s1 + " " + s2 + " " + s3);
    int n = SA.sa.size();
    vector <int> pre[3];
    pre[0].resize(n + 1);
    pre[1].resize(n + 1);
    pre[2].resize(n + 1);
    for (int i = 0; i < n; i++) {
        pre[0][i + 1] = pre[0][i];
        pre[1][i + 1] = pre[1][i];
        pre[2][i + 1] = pre[2][i];
        if (SA.sa[i] < a) pre[0][i + 1]++;
        if (SA.sa[i] > a && SA.sa[i] <= a + b)
            pre[1][i + 1]++;
        if (SA.sa[i] > a + b + 1)
            pre[2][i + 1]++;
    }
    auto calc = [&](int l, int r) {
        int res = 1;
        mul(res, pre[0][r + 1] - pre[0][l]);
        mul(res, pre[1][r + 1] - pre[1][l]);
        mul(res, pre[2][r + 1] - pre[2][l]);
        return res;
    };
    vector <pair <int, int>> pos;
    for (int i = 0; i < n - 1; i++)
        pos.emplace_back(SA.lcp[i], i);
    sort(pos.rbegin(), pos.rend());
    vector <int> lef(n + 1, -1);
    vector <int> rig(n + 1, -1);
    int ptr = 0; int res = 0;
    vector <int> ans(min({a, b, c}));
    for (int l = min({a, b, c}); l > 0; l--) {
        while (ptr < pos.size()
        && pos[ptr].first >= l) {
            int i = pos[ptr++].second;
            int lo = i, hi = i;
            if (i > 0 && ~lef[i - 1]) {
                lo = lef[i - 1];
                sub(res, calc(lo, rig[lo] + 1));
            }
            if (i + 1 < pos.size()
            && rig[i + 1] >= 0) {
                hi = rig[i + 1];
                sub(res, calc(lef[hi], hi + 1));
            }
            lef[hi] = lo; rig[lo] = hi;
            add(res, calc(lo, hi + 1));
        }
        ans[l - 1] = res;
    }
    for (int x : ans) cout << x << ' ';
}