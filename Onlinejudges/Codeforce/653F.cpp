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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; string s; cin >> n >> s;
    SufArr tab(s);
    vector <int> BIT(n + 5), d(n + 5);
    auto add = [&](int i, int v) {
        for (i++; i < n + 5; i += i & -i)
            BIT[i] += v;
    };
    auto get = [&](int i) {
        int v = 0;
        for (i++; i > 0; i -= i & -i)
            v += BIT[i];
        return v;
    };
    stack <pair <int, int>> st;
    st.emplace(n, n); add(n, 1);
    long long res = 0;
    for (int i = n - 1; i >= 0; i--) {
        d[i] = d[i + 1];
        if (s[i] == ')') d[i]++;
        else d[i]--;
        while (st.size() &&
        d[st.top().first] > d[i]) {
            add(st.top().first, -1);
            st.pop();
        }
        int j = i;
        if (st.size() &&
        d[st.top().first] == d[i])
            j = st.top().second;
        res += get(j) - get(min(j,
        i + tab.lcp[tab.rnk[i]]));
        add(i, 1); st.emplace(i, j);
    }
    cout << res << '\n';
}