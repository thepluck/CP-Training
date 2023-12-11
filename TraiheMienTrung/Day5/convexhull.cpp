#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair <int, int>;

struct point{
    ll x = 0, y = 0;

    point(){}

    point(int x, int y): x(x), y(y){}
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
    return cross(a, b) +
    cross(b, c) + cross(c, a) < 0;
}

bool ccw(cp a, cp b, cp c){
    return cross(a, b) +
    cross(b, c) + cross(c, a) > 0;
}

struct polygon{
    vector <point> poly;

    void push(point a){
        poly.push_back(a);
    }

    int size() const {
        return poly.size();
    }

    double area() const {
        ll res = 0;
        int n = poly.size();
        for (int i = 0; i < n; i++){
            res += cross(poly[i],
            poly[(i + 1) % n]);
        }
        return 1.0 * abs(res) / 2;
    }
};

void convex_hull(vector <point> &a){
    sort(a.begin(), a.end(),
    [&](point p, point q){
        return p.x < q.x ||
        (p.x == q.x && p.y < q.y);
    });
    point p[2]; p[0] = a[0];
    p[1] = a.back();
    vector <point> up, down;
    up.push_back(p[0]);
    down.push_back(p[0]);
    for (int i = 1; i < a.size(); i++) {
        if (i == a.size() - 1 ||
        cw(p[0], a[i], p[1])) {
            while (up.size() > 1 &&
            !cw(up[up.size() - 2],
            up[up.size() - 1], a[i])) {
                up.pop_back();
            }
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 ||
        ccw(p[0], a[i], p[1])) {
            while (down.size() > 1 &&
            !ccw(down[down.size() - 2],
            down[down.size() - 1], a[i])) {
                down.pop_back();
            }
            down.push_back(a[i]);
        }
    }
    a.clear();
    for (auto pt : up) {
        a.push_back(pt);
    }
    for (int i = down.size() - 2; i > 0; i--) {
        a.push_back(down[i]);
    }
    reverse(a.begin(), a.end());
}

int main(){
    freopen("convexhull.inp", "r", stdin);
    freopen("convexhull.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.precision(1); fixed(cout);
    int n; cin >> n;
    vector <point> a(n);
    for (auto &pt : a)
        cin >> pt.x >> pt.y;
    convex_hull(a);
    auto it = min_element(a.begin(), a.end(),
    [](point p, point q){
        return p.y < q.y ||
        (p.y == q.y && p.x < q.x);
    });
    rotate(a.begin(), it, a.end());
    n = a.size(); cout << n << '\n';
    ll res = 0;
    for (int i = 0; i < n; i++) {
        res += cross(a[i], a[(i + 1) % n]);
    }
    cout << res / 2 << ' ' <<
    (res & 1 ? 5 : 0) << '\n';
    for (auto pt : a) {
        cout << pt.x << ' ' << pt.y << '\n';
    }
}
