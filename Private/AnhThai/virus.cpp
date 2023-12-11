#include <bits/stdc++.h>
using namespace std;

struct AhoCorasick {
    struct state{
        int nxt[2], aut[2];
        int link, cnt, leaf;

        state(): link(0), cnt(0), leaf(0) {
            memset(nxt, 0, sizeof nxt);
            memset(aut, 0, sizeof aut);
        }
    };

    vector <string> pool;
    vector <state> tree;

    AhoCorasick() {
        tree.push_back(state());
    }

    void clear() {
        pool.clear(); tree.clear();
        tree.push_back(state());
    }

    int size() const {
        return pool.size();
    }

#define nxt(u, c) tree[(u)].nxt[(c) - '0']
#define aut(u, c) tree[(u)].aut[(c) - '0']
#define link(u) tree[(u)].link
#define cnt(u) tree[(u)].cnt
#define leaf(u) tree[(u)].leaf

    void insert(const string &s) {
        pool.push_back(s); int pt = 0;
        for (char c : s) {
            if (!nxt(pt, c)) {
                nxt(pt, c) = tree.size();
                tree.push_back(state());
            }
            pt = nxt(pt, c);
        }
        leaf(pt)++;
    }

    void automata() {
        queue <int> q; q.push(0);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            cnt(u) = leaf(u) + cnt(link(u));
            for (char c = '0'; c <= '1'; c++) {
                int v = nxt(u, c);
                if (v) {
                    link(v) = u ? aut(link(u), c) : 0;
                    q.push(v); aut(u, c) = v;
                }
                else aut(u, c) = aut(link(u), c);
            }
        }
    }

    int count(const string &s) {
        int pt = 0, res = 0;
        for (char c : s) {
            pt = aut(pt, c); res += cnt(pt);
        }
        return res;
    }
};

struct DynAho {
     AhoCorasick pool[31]; int sz = 0;

    void move(AhoCorasick &src, AhoCorasick &des) {
        for (auto s : src.pool) des.insert(s);
        src.clear();
    }

    DynAho(): sz(0) {}

    void insert(const string &s) {
        pool[sz].insert(s);
        int cur = sz, pw = 1;
        while (sz && pool[sz - 1].size() == pw) {
            pw *= 2; sz--;
        }
        while (cur > sz) {
            move(pool[cur], pool[sz]); cur--;
        }
        pool[sz++].automata();
    }

    int count(const string &s) {
        int res = 0;
        for (int i = 0; i < sz; i++)
            res += pool[i].count(s);
        return res;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    DynAho A;
    int Q; cin >> Q;
    while (Q--) {
        int cmd; string S; cin >> cmd >> S;
        if (cmd) cout << A.count(S) << '\n';
        else A.insert(S);
    }
}
