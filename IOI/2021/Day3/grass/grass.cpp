#include "grass.h"
#include <bits/stdc++.h>

template <class X, class Y>
bool cmax(X &a, const Y &b) {
    return a < b ? a = b, 1 : 0;
}

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

using ll = long long;

struct segment {
    int l, r; ll h;

    segment(int l, int r, ll h):
    l(l), r(r), h(h) {}

    bool operator < (const segment &o) const {
        return l < o.l;
    }

    bool operator > (const segment &o) const {
        return l > o.l;
    }
};

using namespace std;

vector <ll> simulate(int N, int H, int M,
vector <char> events, vector <int> X) {
    vector <ll> ferts;
    ll sum = 0, add = 0;
    set <segment> lef;
    set <segment, greater <segment>> rig;
    lef.emplace(0, N, 0);
    for (int i = 0; i < M; i++) {
        if (events[i] == 'N') {
            add += X[i]; int l = N, r = 0;
            while (lef.size() && lef.rbegin()->h + add > H) {
                auto s = *lef.rbegin(); lef.erase(s);
                sum -= s.h * (s.r - s.l);
                cmin(l, s.l); cmax(r, s.r);
            }
            while (rig.size() && rig.rbegin()->h + add > H) {
                auto s = *rig.rbegin(); rig.erase(s);
                sum -= s.h * (s.r - s.l);
                cmin(l, s.l); cmax(r, s.r); 
            }
            if (l < r) {
                sum += (-add + H) * (r - l);
                lef.emplace(l, r, -add + H);
            }
        } else if (events[i] == 'L') {
            while (lef.size() && lef.begin()->l < X[i]) {
                auto s = *lef.begin(); lef.erase(s);
                sum -= s.h * (s.r - s.l);
                if (s.r > X[i]) {
                    sum += s.h * (s.r - X[i]);
                    lef.emplace(X[i], s.r, s.h);
                }
            }
            while (rig.size() && rig.rbegin()->l < X[i]) {
                auto s = *rig.rbegin(); rig.erase(s);
                sum -= s.h * (s.r - s.l);
                if (s.r > X[i]) {
                    sum += s.h * (s.r - X[i]);
                    rig.emplace(X[i], s.r, s.h);
                }
            }
            sum += -add * X[i];
            lef.emplace(0, X[i], -add);
        } else if (events[i] == 'D') {
            X[i] = N - X[i];
            while (lef.size() && lef.rbegin()->r > X[i]) {
                auto s = *lef.rbegin(); lef.erase(s);
                sum -= s.h * (s.r - s.l);
                if (X[i] > s.l) {
                    sum += s.h * (X[i] - s.l);
                    lef.emplace(s.l, X[i], s.h);
                }
            }
            while (rig.size() && rig.begin()->r > X[i]) {
                auto s = *rig.begin(); rig.erase(s);
                sum -= s.h * (s.r - s.l);
                if (X[i] > s.l) {
                    sum += s.h * (X[i] - s.l);
                    rig.emplace(s.l, X[i], s.h);
                }
            }
            sum += -add * (N - X[i]);
            rig.emplace(X[i], N, -add);
        } else if (events[i] == 'S') {
            int l = N, r = 0;
            while (lef.size() && lef.rbegin()->h + add > X[i]) {
                auto s = *lef.rbegin(); lef.erase(s);
                sum -= s.h * (s.r - s.l);
                cmin(l, s.l); cmax(r, s.r);
            }
            while (rig.size() && rig.rbegin()->h + add > X[i]) {
                auto s = *rig.rbegin(); rig.erase(s);
                sum -= s.h * (s.r - s.l);
                cmin(l, s.l); cmax(r, s.r); 
            }
            if (l < r) {
                sum += (-add + X[i]) * (r - l);
                lef.emplace(l, r, -add + X[i]);
            }
        } else ferts.push_back(sum + add * N);
    }
    return ferts;
}
