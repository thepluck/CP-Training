#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

using ii = pair <int, int>;

struct cmp1 {
    bool operator () (const ii &a, const ii &b) {
        return a.fi == b.fi ? a.se < b.se : a.fi < b.fi;
    }
};

struct cmp2 {
    bool operator () (const ii &a, const ii &b) {
        return a.se == b.se ? a.fi < b.fi : a.se < b.se;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector <ii> chain[2], spiral, points(n);
    chain[0].emplace_back(0, 0);
    for (auto &pt : points) cin >> pt.fi >> pt.se;
    set <ii, cmp1> s1(points.begin(), points.end());
    set <ii, cmp2> s2(points.begin(), points.end());
    while (s1.size()) {
        ii lef = *s1.begin(), rig = *s1.rbegin();
        ii up = *s2.rbegin(), down = *s2.begin();
        vector <ii> pend;
        pend.push_back(lef); pend.push_back(rig);
        pend.push_back(up); pend.push_back(down);
        sort(pend.begin(), pend.end());
        pend.erase(unique(pend.begin(),
        pend.end()), pend.end());
        if (pend.size() < 4) {
            if (pend.size() == 1) {
                chain[0].push_back(lef);
                s1.erase(lef); s2.erase(lef);
                continue;
            }
            if (pend.size() == 2) {
                auto p2 = pend.back(); pend.pop_back();
                auto p1 = pend.back(); pend.pop_back();
                if (p1.se <= p2.se) {
                    chain[0].push_back(p1);
                    chain[0].push_back(p2);
                }
                else {
                    chain[1].push_back(p1);
                    chain[1].push_back(p2);
                }
                s1.erase(p1); s1.erase(p2);
                s2.erase(p1); s2.erase(p2);
                continue;
            }
            if (lef == up) {
                chain[1].push_back(lef);
                s1.erase(lef); s2.erase(lef);
            }
            if (lef == down) {
                chain[0].push_back(lef);
                s1.erase(lef); s2.erase(lef);
            }
            if (rig == up) {
                chain[0].push_back(rig);
                s1.erase(rig); s2.erase(rig);
            }
            if (rig == down) {
                chain[1].push_back(rig);
                s1.erase(rig); s2.erase(rig);
            }
            if (spiral.size()) {
                for (int i = 0; i < 4; i++) {
                    s1.insert(spiral.back());
                    s2.insert(spiral.back());
                    spiral.pop_back();
                }
            }
        }
        else {
            if (down == *next(s1.begin())) {
                chain[0].push_back(down);
                s1.erase(down); s2.erase(down);
            }
            else {
                spiral.push_back(lef);
                spiral.push_back(up);
                spiral.push_back(rig);
                spiral.push_back(down);
                for (auto pt : pend) {
                    s1.erase(pt); s2.erase(pt);
                }
            }
        }
    }
    sort(chain[0].begin(), chain[0].end());
    sort(chain[1].begin(), chain[1].end());
    vector <ii> zigzag;
    zigzag.push_back({0, 0});
    for (int i = 0; i + 1 < chain[0].size(); i++) {
        if (i & 1)
            zigzag.emplace_back(chain[0][i].fi, chain[0][i + 1].se);
        else zigzag.emplace_back(chain[0][i + 1].fi, chain[0][i].se);
    }
    zigzag.push_back(chain[0].back());
    if (spiral.size()) {
        zigzag.emplace_back(chain[0].back().fi, spiral.front().se);
        zigzag.push_back(spiral.front());
    }
    else if (chain[1].size()) {
        zigzag.emplace_back(chain[0].back().fi, chain[1].front().se);
        zigzag.push_back(chain[1].front());
    }
    for (int i = 0; i + 1 < spiral.size(); i++) {
        if (~i & 1)
            zigzag.emplace_back(spiral[i].fi, spiral[i + 1].se);
        else zigzag.emplace_back(spiral[i + 1].fi, spiral[i].se);
    }
    if (spiral.size()) {
        zigzag.push_back(spiral.back());
        if (chain[1].size()) {
            zigzag.emplace_back(spiral.back().fi, chain[1].front().se);
            zigzag.push_back(chain[1].front());
        }
    }
    for (int i = 0; i + 1 < chain[1].size(); i++) {
        if (i & 1)
            zigzag.emplace_back(chain[1][i].fi, chain[1][i + 1].se);
        else zigzag.emplace_back(chain[1][i + 1].fi, chain[1][i].se);
    }
    if (chain[1].size()) zigzag.push_back(chain[1].back());
    bitset <200005> mark;
    for (int i = 0; i + 2 < zigzag.size(); i++) {
        if (zigzag[i].fi == zigzag[i + 1].fi &&
        zigzag[i].fi == zigzag[i + 2].fi) {
            int x, y;
            tie(x, y) = minmax(zigzag[i].se, zigzag[i + 2].se);
            if (zigzag[i + 1].se >= x && zigzag[i + 1].se <= y) mark[i + 1] = true;
        }
        if (zigzag[i].se == zigzag[i + 1].se &&
        zigzag[i].se == zigzag[i + 2].se) {
            int x, y;
            tie(x, y) = minmax(zigzag[i].fi, zigzag[i + 2].fi);
            if (zigzag[i + 1].fi >= x && zigzag[i + 1].fi <= y) mark[i + 1] = true;
        }
    }
    zigzag.erase(unique(zigzag.begin(), zigzag.end()), zigzag.end());
    cout << zigzag.size() - 1 - mark.count() << '\n';
    for (int i = 1; i < zigzag.size(); i++)
        if (!mark[i])
            cout << zigzag[i].fi << ' ' << zigzag[i].se << '\n';
}