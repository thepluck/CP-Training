#include <bits/stdc++.h>

using namespace std;

struct SuffixAutomaton {
    vector <int> len, link, cnt;
    vector <array <int, 26>> nxt;
    int last;

    void extend(int c) {
        int p = last;
        /// create new state
        len.emplace_back(len[last] + 1);
        nxt.emplace_back();
        link.emplace_back();
        cnt.emplace_back(1);
        last = len.size() - 1;
        while (p >= 0 && !nxt[p][c]) {
            nxt[p][c] = last; p = link[p];
        }
        if (p < 0) link[last] = 0;
        else {
            int q = nxt[p][c];
            if (len[p] + 1 == len[q])
                link[last] = q;
            else {
                /// clone state q
                len.emplace_back(len[p] + 1);
                nxt.emplace_back(nxt[q]);
                link.emplace_back(link[q]);
                cnt.emplace_back(0);
                int clone = len.size() - 1;
                while (p >= 0 && nxt[p][c] == q) {
                    nxt[p][c] = clone; p = link[p];
                }
                link[q] = link[last] = clone;
            }
        }
    }

    SuffixAutomaton(const string &s): last(0) {
        len.emplace_back();
        nxt.emplace_back();
        link.emplace_back(-1);
        cnt.emplace_back();
        for (char c : s) extend(c - 'a');
        vector <int> tmp(s.size() + 1);
        vector <int> ord(len.size() - 1);
        for (int i = 1; i < len.size(); i++)
            tmp[len[i]]++;
        for (int i = s.size() - 1; i >= 0; i--)
            tmp[i] += tmp[i + 1];
        for (int i = 1; i < len.size(); i++)
            ord[--tmp[len[i]]] = i;
        for (int p : ord)
            cnt[link[p]] += cnt[p];
    }

    int countOccurrence(const string &s) {
        int cur = 0;
        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';
            cur = nxt[cur][c];
            if (!cur) return 0;
        }
        return cnt[cur];
    }
};

int findPeriod(const string &s) {
    vector <int> kmp(s.size());
    for (int i = 1, j = 0; i < s.size(); i++) {
        while (j && s[i] != s[j])
            j = kmp[j - 1];
        if (s[i] == s[j]) j++;
        kmp[i] = j;
    }
    return s.size() - kmp.back();
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    SuffixAutomaton SA(s);
    int q; cin >> q;
    while (q--) {
        int cur = 0, len = 0;
        string t; cin >> t;
        long long res = 0;
        for (int i = 0; i < t.size(); i++) {
            int c = t[i] - 'a';
            while (cur && !SA.nxt[cur][c]) {
                cur = SA.link[cur];
                len = SA.len[cur];
            }
            if (SA.nxt[cur][c]) {
                cur = SA.nxt[cur][c]; len++;
            }
            while (cur &&
            SA.len[SA.link[cur]] >= t.size()) {
                cur = SA.link[cur];
                len = SA.len[cur];
            }
            if (len >= t.size())
                res += SA.cnt[cur];
        }
        for (int i = 0; i + 1 < t.size(); i++) {
            int c = t[i] - 'a';
            while (cur && !SA.nxt[cur][c]) {
                cur = SA.link[cur];
                len = SA.len[cur];
            }
            if (SA.nxt[cur][c]) {
                cur = SA.nxt[cur][c]; len++;
            }
            while (cur &&
            SA.len[SA.link[cur]] >= t.size()) {
                cur = SA.link[cur];
                len = SA.len[cur];
            }
            if (len >= t.size())
                res += SA.cnt[cur];
        }
        int per = findPeriod(t);
        if (t.size() % per == 0)
            res /= t.size() / per;
        cout << res << '\n';
    }
}