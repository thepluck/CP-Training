#include <bits/stdc++.h>

using namespace std;

struct aho_corasick {
    struct node {
        int nxt[26], len, link, leaf;

        node(int len = 0): len(len), link(0), leaf(0) {
            memset(nxt, 0, sizeof nxt);
        }
    };

    vector <node> tree;
    vector <string> str;

#define nxt(i, c) tree[i].nxt[c - 'a']
#define link(i) tree[i].link
#define leaf(i) tree[i].leaf
#define len(i) tree[i].len

    aho_corasick(): tree(1) {}

    void add(const string &s) {
        int u = 0;
        for (char c : s) {
            if (!nxt(u, c)) {
                nxt(u, c) = tree.size();
                tree.emplace_back(len(u) + 1);
            }
            u = nxt(u, c);
        }
        leaf(u)++; str.push_back(s);
    }

    void build() {
        queue <int> que; que.emplace(0);
        while (que.size()) {
            int u = que.front(); que.pop();
            leaf(u) += leaf(link(u));
            for (char c = 'a'; c <= 'z'; c++) {
                int v = nxt(u, c);
                if (v) {
                    link(v) = u ? nxt(link(u), c) : 0;
                    que.emplace(v);
                } else nxt(u, c) = nxt(link(u), c);
            }
        }
    }

    int count(const string &s) const {
        int u = 0, cnt = 0;
        for (char c : s)
            cnt += leaf(u = nxt(u, c));
        return cnt;
    }

    bool empty() const {
        return str.empty();
    }

    size_t size() const {
        return str.size();
    }

    ~aho_corasick() {
        tree.clear(); str.clear();
    }
};

struct dynamic_aho_corasick {
    aho_corasick tree[20];

    void add(const string &s) {
        for (int i = 0; i < 20; i++)
            if (tree[i].empty()) {
                tree[i].add(s);
                for (int j = 0; j < i; j++) {
                    for (string t : tree[j].str)
                        tree[i].add(t);
                    tree[j] = aho_corasick();
                }
                tree[i].build(); break;
            }
    }

    int count(const string &s) {
        int cnt = 0;
        for (int i = 0; i < 20; i++)
            if (tree[i].size())
                cnt += tree[i].count(s);
        return cnt;
    }
} ins, del;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int Q; cin >> Q;
    while (Q--) {
        int cmd; string s;
        cin >> cmd >> s;
        if (cmd == 1) ins.add(s);
        else if (cmd == 2) del.add(s);
        else cout << ins.count(s) - del.count(s) << endl;
    }
}