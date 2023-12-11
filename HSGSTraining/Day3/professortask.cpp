#include <bits/stdc++.h>
using namespace std;

#define lb lower_bound

using ll = long long;

struct point{
    ll x = 0, y = 0;

    point(){}

    point(int x, int y): x(x), y(y){}

    bool operator < (const point &o) const {
        return x < o.x || (x == o.x && y < o.y);
    }

    bool operator > (const point &o) const {
        return x > o.x || (x == o.x && y > o.y);
    }

    bool operator ==
    (const point &o) const {
        return x == o.x && y == o.y;
    }
};

using cp = const point&;

point operator + (cp a, cp b){
    return point(a.x + b.x, a.y + b.y);
}

point operator - (cp a, cp b){
    return point(a.x - b.x, a.y - b.y);
}

ll dot(cp a, cp b){
    return a.x * b.x + a.y * b.y;
}

ll cross(cp a, cp b){
    return a.x * b.y - a.y * b.x;
}

ll norm(cp a){
    return a.x * a.x + a.y * a.y;
}

double abs(cp a){
    return sqrt(norm(a));
}

bool cw(cp a, cp b, cp c){
    return cross(a, b) + cross(b, c) + cross(c, a) < 0;
}

bool ccw(cp a, cp b, cp c){
    return cross(a, b) + cross(b, c) + cross(c, a) > 0;
}

template <class cmp>
struct dynamic_hull {
    set <point, cmp> hull;

    void insert(const point &pt) {
        auto i = hull.lb(pt);
        if (i != hull.end() && *i == pt) return;
        auto j = i;
        if (j != hull.begin()) {
            j--;
            while (j != hull.begin()) {
                auto k = j--;
                if (cross(*k - *j, pt - *k) > 0) break;
                hull.erase(k);
            }
        }
        if (i != hull.end()) {
            auto k = i;
            while (++i != hull.end()) {
                if (cross(*k - pt, *i - pt)) break;
                hull.erase(k); k = i;
            }
        }
        i = hull.lb(pt);
        if (i == hull.end() || i == hull.begin())
            hull.insert(pt);
        else {
            j = i--;
            if (cross(pt - *i, *j - *i) > 0)
                hull.insert(pt);
        }
    }

    bool query(const point &pt) {
        auto i = hull.lb(pt);
        if (*i == pt) return 1;
        if (i == hull.end() || i == hull.begin())
            return 0;
        auto j = i--;
        return cross(pt - *i, *j - *i) <= 0;
    }
};

int main() {
    freopen("tt.inp", "r", stdin);
    freopen("tt.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    dynamic_hull <less <point>> up;
    dynamic_hull <greater <point>> down;
    while (n--) {
        int cmd; point pt;
        cin >> cmd >> pt.x >> pt.y;
        if (cmd == 1) {
            up.insert(pt); down.insert(pt);
            for (auto p : up.hull)
                cout << p.x << ' ' << p.y << '\n';
            for (auto p : down.hull)
                cout << p.x << ' ' << p.y << '\n';
        }
        else {
            if (up.query(pt) && down.query(pt))
                cout << "YES\n";
            else cout << "NO\n";
        }
    }
}