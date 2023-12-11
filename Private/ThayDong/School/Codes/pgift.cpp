#include <bits/stdc++.h>
using namespace std;

struct rec {
    long long x1, y1, x2, y2;
};

long long w[4], wn[4], h[4], hn[4];
long long res = 1e18;
vector <int> cx, cy;
vector <rec> cur;

bool intersect(rec a, rec b) {
    if (min(a.y2, b.y2) <= max(a.y1, b.y1))
        return 0;
    if (min(a.x2, b.x2) <= max(a.x1, b.x1))
        return 0;
    return 1;
}

void dfs(int i) {
    if (i == 4) {
        long long maxx = LLONG_MIN;
        long long maxy = LLONG_MIN;
        for (rec tmp : cur) {
            maxx = max(maxx, tmp.x2);
            maxy = max(maxy, tmp.y2);
        }
        res = min(res, maxx * maxy);
        return;
    }
    vector <int> ox = cx, oy = cy;
    vector <rec> old = cur;
    for (int x : ox)
        for (int y : oy) {
            rec tmp = {x, y, x + w[i], y + h[i]};
            bool ok = 1;
            for (rec other : old)
                if (intersect(other, tmp)) {
                    ok = 0; break;
                }
            if (!ok) continue;
            cx = ox; cy = oy; cur = old;
            cx.push_back(x + w[i]);
            cy.push_back(y + h[i]);
            cur.push_back(tmp); dfs(i + 1);
        }
}

int main() {
    freopen("pgift.inp", "r", stdin);
    freopen("pgift.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 0; i < 4; i++)
        cin >> wn[i] >> hn[i];
    vector <int> p{0, 1, 2, 3};
    do {
        for (int m = 0; m < (1 << 4); m++) {
            for (int i = 0; i < 4; i++) {
                w[i] = wn[p[i]]; h[i] = hn[p[i]];
                if (m >> i & 1) swap(w[i], h[i]);
            }
            cur.clear(); cx.clear(); cy.clear();
            cx.push_back(0); cy.push_back(0); dfs(0);
        }
    }
    while (next_permutation(p.begin(), p.end()));
    cout << res << '\n';
}