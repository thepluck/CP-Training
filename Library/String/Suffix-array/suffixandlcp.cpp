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
