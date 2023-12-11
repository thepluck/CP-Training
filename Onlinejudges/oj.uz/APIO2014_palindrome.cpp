#include <bits/stdc++.h>

using namespace std;

struct eerTree {
    struct state {
        int nxt[26], len, link, cnt;

        state(int len, int link, int cnt):
        len(len), link(link), cnt(cnt) {
            memset(nxt, 0, sizeof nxt);
        }
    };

    vector <state> tree;
    string s; int last;
    vector <int> topo;

    void extend(int pos) {
        int chr = s[pos] - 'a', cur = last;
        while (pos - tree[cur].len <= 0 ||
        s[pos - tree[cur].len - 1] != s[pos])
            cur = tree[cur].link;
        if (tree[cur].nxt[chr]) {
            last = tree[cur].nxt[chr];
            tree[last].cnt++; return;
        }
        last = tree.size();
        tree.emplace_back(tree[cur].len + 2, 0, 1);
        tree[cur].nxt[chr] = last;
        if (cur == 0) {
            tree[last].link = 1; return;
        }
        cur = tree[cur].link;
        while (pos - tree[cur].len <= 0 ||
        s[pos - tree[cur].len - 1] != s[pos])
            cur = tree[cur].link;
        tree[last].link = tree[cur].nxt[chr];
    }

    eerTree(string s): s(s), last(1) {
        tree.emplace_back(-1, 0, 0);
        tree.emplace_back(0, 0, 0);
        for (int i = 0; i < s.size(); i++)
            extend(i);
        vector <int> cnt(s.size() + 1);
        for (int i = 2; i < tree.size(); i++)
            cnt[tree[i].len]++;
        for (int i = 1; i <= s.size(); i++)
            cnt[i] += cnt[i - 1];
        topo.resize(tree.size() - 2);
        iota(topo.begin(), topo.end(), 2); 
        for (int i = 2; i < tree.size(); i++)
            topo[--cnt[tree[i].len]] = i;
        for (int i = topo.size() - 1; i >= 0; i--) {
            int cur = topo[i];
            tree[tree[cur].link].cnt += tree[cur].cnt;
        }
    }

    long long maxOccurrenceValue() {
        long long val = 0;
        for (int i : topo)
            val = max(val, 1ll * tree[i].len * tree[i].cnt);
        return val;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s; eerTree eT(s);
    cout << eT.maxOccurrenceValue() << '\n';
}
