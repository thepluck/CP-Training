#include <bits/stdc++.h>

using namespace std;

struct segment {
    int l, r;

    bool operator < (const segment &o) const {
        return l < o.l || (l == o.l && r < o.r);
    }

    bool contain(int x) {
        return l <= x && x <= r;
    }

    bool contain(int x, int y) {
        return l < x && y < r;
    }

    bool contain(const segment &o) {
        return contain(o.l, o.r);
    }
};

const int MAXN = 255;
const int MAXM = 45;

int pts[MAXN], exc;
segment seg[MAXN];
double maxPts[MAXM][MAXN][MAXN];
bool vis[MAXM][MAXN][MAXN];

double getPts(int l, int r) {
    return double(pts[r] - pts[l - 1]) / (r - l + 1);
}

double calc(int i, int l, int r, const vector <int> &ins) {
    if (vis[i][l][r]) return maxPts[i][l][r];
    vis[i][l][r] = true;
    double &res = maxPts[i][l][r] = -1e9;
    for (auto nI : ins) {
        int nL = l, nR = r;
        vector <int> nIns, lef, rig;
        double curPts = 0;
        for (auto o : ins) {
            if (o < nI) lef.push_back(seg[o].l);
            else if (seg[o].l >= seg[nI].l && seg[o].r >= seg[nI].r)
                rig.push_back(seg[o].r);
            else nIns.push_back(o);
        }
        sort(rig.rbegin(), rig.rend());
        for (int len : lef) {
            if (nL + len > r) {
                curPts = -1e9; break;
            }
            curPts += getPts(nL, nL + len - 1);
            nL += len;
        }
        for (int len : rig) {
            if (nR - len < nL) {
                curPts = -1e9; break;
            }
            curPts += getPts(nR - len + 1, nR);
            nR -= len;
        }
        if (curPts < 0) continue;
        res = max(res, curPts + calc(nI, nL, nR, nIns));
    }
    double curPts = 0;
    for (auto o : ins) {
        if (l + seg[o].l > r) {
            curPts = -1e9; break;
        }
        curPts += getPts(l, l + seg[o].l - 1);
        l += seg[o].l;
    }
    if (curPts >= 0 && seg[exc].contain(r - l + 1)) {
        curPts += getPts(l, r);
        res = max(res, curPts);
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> pts[i];
    sort(pts + 1, pts + N + 1, greater <int> ());
    for (int i = 1; i <= N; i++)
        pts[i] += pts[i - 1];
    int M; cin >> M;
    for (int i = 1; i <= M; i++)
        cin >> seg[i].l >> seg[i].r;
    sort(seg + 1, seg + M + 1);
    double res = 0;
    for (exc = 1; exc <= M; exc++) {
        memset(vis, 0, sizeof vis);
        vector <int> ins;
        for (int i = 1; i <= M; i++)
            if (i != exc) ins.push_back(i);
        res = max(res, calc(0, 1, N, ins));
    }
    cout << setprecision(10) << fixed << res << '\n';
}