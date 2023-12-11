#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using edge = pair<int,int>;
constexpr int SQ = 666;
constexpr int Y = 17;

struct SSeq {
    int _sas[SQ], _sbs[SQ], _p = 0, t = 0;
    SSeq() {}
    void clear() { _p = 0; t = 0; }
    bool empty() { return !_p; }
    void push(int a, int b) {
        assert(a <= b);
        _sas[_p] = a;
        _sbs[_p] = b;
        _p++;
        t += b - a + 1;
    }
    void pop(int& a, int& b) {
        _p--;
        a = _sas[_p];
        b = _sbs[_p];
        t -= b - a + 1;
    }
};


struct Tree {
    vector<int> depth, dnheight, upheight, dnjump, upjump, anc[Y + 1];

    Tree(int n, const vector<edge>& edges): depth(n),
            dnheight(n, 1), dnjump(n),
            upheight(n, 0), upjump(n) {

        // adjacency list
        vector<vector<int>> adj(n);
        for (auto [a, b] : edges) {
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        // initial traversal
        anc[0].resize(n);
        parent(0) = 0;
        vector<int> pre = {0};
        for (int f = 0; f < pre.size(); f++) {
            int i = pre[f];
            for (int j : adj[i]) {
                if (j != parent(i)) {
                    parent(j) = i;
                    depth[j] = depth[i] + 1;
                    pre.push_back(j);
                }
            }
        }

        // power-of-two pointers
        for (int k = 0; k < Y; k++) {
            anc[k + 1].resize(n);
            for (int i = 0; i < n; i++) {
                anc[k + 1][i] = anc[k][anc[k][i]];
            }
        }

        // heights
        reverse(pre.begin(), pre.end());
        for (int i : pre) {
            for (int j : adj[i]) {
                if (j != parent(i)) {
                    dnheight[i] = max(dnheight[i], dnheight[j] + 1);
                }
            }
        }

        // "up" heights
        reverse(pre.begin(), pre.end());
        for (int i : pre) {
            int k = -1;
            for (int j : adj[i]) {
                if (j != parent(i)) {
                    upheight[j] = upheight[i] + 1;
                    if (dnheight[j] == dnheight[i] - 1) k = j;
                }
            }
            for (int j : adj[i]) {
                if (j != parent(i) && j != k) {
                    upheight[j] = max(upheight[j], dnheight[k] + 1);
                    upheight[k] = max(upheight[k], dnheight[j] + 1);
                }
            }
        }

        // height jumps
        for (int i : pre) {
            dnjump[i] = dnheight[parent(i)] == dnheight[i] + 1 ? dnjump[parent(i)] : i;
            upjump[i] = upheight[parent(i)] == upheight[i] - 1 ? upjump[parent(i)] : i;
        }
    }

    int& parent(int i) {
        return anc[0][i];
    }

    int ascend(int i, int d) {
        assert(d >= 0);
        for (int k = 0; k <= Y; k++, d >>= 1) {
            if (d & 1) i = anc[k][i];
        }
        assert(d == 0);
        return i;
    }

    bool is_anc(int i, int a) {
        return depth[i] >= depth[a] && ascend(i, depth[i] - depth[a]) == a;
    }

    int lca(int a, int b) {
        if (depth[a] >= depth[b]) a = ascend(a, depth[a] - depth[b]);
        if (depth[b] >= depth[a]) b = ascend(b, depth[b] - depth[a]);
        if (a == b) return a;
        for (int k = Y; k >= 0; k--) {
            if (anc[k][a] != anc[k][b]) {
                a = anc[k][a];
                b = anc[k][b];
            }
        }
        return parent(a);
    }

    tuple<int*,int*,int> _seq(int i, int a, const vector<int>& jump) {
        static int _seqi[SQ], _seqb[SQ];
        int c = 0, j;
        #define I _seqi[c]
        for (I = i; depth[j = jump[I]] > depth[a]; I = parent(j)) {
            _seqb[c++] = depth[I] - depth[j];
        }
        if (depth[I] > depth[a]) {
            _seqb[c++] = depth[I] - depth[a] - 1;
        }
        #undef I
        return {_seqi, _seqb, c};
    }

    void upseq(int i, int a, SSeq& targ) {
        auto [seqi, seqb, c] = _seq(i, a, upjump);
        for (int idx = 0; idx < c; idx++) {
            int h = upheight[seqi[idx]];
            targ.push(h - seqb[idx], h);
        }
    }

    void dnseq(int i, int a, SSeq& targ) {
        auto [seqi, seqb, c] = _seq(i, a, dnjump);
        for (int idx = c; idx--;) {
            int h = dnheight[seqi[idx]];
            targ.push(h, h + seqb[idx]);
        }
    }

    void get_seq(int r, int s, int t, int l, int u, SSeq& sq, SSeq& tq) {
        if (is_anc(s, l)) {
            dnseq(s, l, sq);
            upseq(l, u, tq);
            dnseq(t, u, tq);
        } else {
            get_seq(r, t, s, l, u, tq, sq);
        }
    }

    ll inversions(int r, int s, int t) {
        int ls = lca(r, s);
        int lt = lca(r, t);
        int u  = lca(s, t);
        int l = ls == lt ? u : ls != u ? ls : lt;
        static SSeq _sq, _tq;
        _sq.clear(), _tq.clear();
        get_seq(r, s, t, l, u, _sq, _tq);
        ll ans = _tq.t * ll(_tq.t + 1) / 2;

        for (int sa, sb, ta, tb; !_sq.empty() && !_tq.empty();) {
            _sq.pop(sa, sb), _tq.pop(ta, tb);

            if (tb < sa) {
                ans += (_sq.t + sb - sa + 1) * ll(tb - ta + 1);
                _sq.push(sa, sb); continue;
            }

            if (ta < sa) {
                ans += (_sq.t + sb - sa + 1) * ll(sa - ta);
                ta = sa;
            }

            if (ta > sb) {
                _tq.push(ta, tb); continue;
            }

            sa = min(sb, tb) + 1;
            ans += (_sq.t + sb - ta) * ll(sa - ta) - (sa - ta) * ll(sa - ta - 1) / 2;
            ta = sa;

            if (sa <= sb) {
                _sq.push(sa, sb); continue;
            }

            if (ta <= tb) {
                _tq.push(ta, tb); continue;
            }
        }

        return ans;
    }
};

void solve() {
    int n, q;
    scanf("%d%d", &n, &q);
    vector<edge> edges;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        edges.emplace_back(--a, --b);
    }
    Tree tree(n, edges);
    while (q--) {
        int r, s, t;
        scanf("%d%d%d", &r, &s, &t);
        printf("%lld\n", tree.inversions(--r, --s, --t));
    }
}

int main() {
    int t;
    for (scanf("%d", &t); t--; solve());
}