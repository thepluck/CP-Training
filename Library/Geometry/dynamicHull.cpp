#include <bits/stdc++.h>

using namespace std;

using Tp = long long;

struct point {
    Tp x, y;
    
    point(Tp x = 0, Tp y = 0): x(x), y(y) {}
    
    bool operator < (const point &o) const {
        return x != o.x ? x < o.x : y < o.y;
    }
    
    bool operator == (const point &o) const {
        return x == o.x && y == o.y;
    }
    
    point& operator -= (const point &o) {
        x -= o.x; y -= o.y; return *this;
    }
    
    point operator - (const point &o) const {
        return point(*this) -= o;
    }
};

Tp cross(const point &a, const point &b) {
    return a.x * b.y - a.y * b.x;
}

Tp orient(const point &a,
const point &b, const point &c) {
    return cross(b - a, c - b);
}

bool ccw(const point &a,
const point &b, const point &c) {
    return orient(a, b, c) > 0;
}

bool cw(const point &a,
const point &b, const point &c) {
    return orient(a, b, c) < 0;
}

struct pointSet : set <point> {
    bool isInside(const point &p) {
        auto it = lower_bound(p);
        if (it == end()) return false;
        if (it->x == p.x) return it->y >= p.y;
        if (it == begin()) return false;
        return !cw(*prev(it), p, *it);
    }
    
    void addPoint(const point &p) {
        if (isInside(p)) return;
        auto it = lower_bound(p);
        if (it != begin()) {
            it = prev(it);
            while (it != begin()) {
                auto it1 = prev(it);
                if (ccw(p, *it, *it1)) break;
                it = prev(erase(it));
            }
        }
        it = lower_bound(p);
        if (it != end()) {
            while (true) {
                auto it1 = next(it);
                if (it1 == end()) break;
                if (cw(p, *it, *it1)) break;
                it = erase(it);
            }
        }
        it = lower_bound(p);
        if (it == begin() || it == end())
            insert(p);
        else {
            auto it1 = prev(it);
            if (ccw(*it, p, *it1)) insert(p);
        }
    }
};

struct dynamicHull {
    pointSet up, down;
    
    void addPoint(const point &p) {
        up.addPoint(p);
        down.addPoint({p.x, -p.y});
    }
    
    bool isInside(const point &p) {
        return up.isInside(p) &&
        down.isInside({p.x, -p.y});
    }
};

int main() {
    
}