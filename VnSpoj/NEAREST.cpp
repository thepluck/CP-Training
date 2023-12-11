#include <bits/stdc++.h>
using namespace std;

#define lb lower_bound
#define ub upper_bound

template <class T>
class point{
public:
    T x, y;

    point(): x(0), y(0){}

    point(T x, T y): x(x), y(y){}

    friend bool operator < (point a, point b){
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    }

    friend point operator + (point a, point b){
        return point(a.x + b.x, a.y + b.y);
    }

    friend point operator - (point a, point b){
        return point(a.x - b.x, a.y - b.y);
    }

    friend T dot(point a, point b){
        return a.x * b.x + a.y * b.y;
    }

    friend T cross(point a, point b){
        return a.x * b.y - a.y * b.x;
    }

    friend T norm(point a){
        return a.x * a.x + a.y * a.y;
    }

    friend T dis(point a, point b){
        return sqrt(norm(a - b));
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n; double res = 1e20;
    cout << setprecision(3) << fixed;
    vector <point <double>> pt(n);
    for (auto &p : pt) cin >> p.x >> p.y;
    sort(pt.begin(), pt.end());
    set <point <double>> s;
    for (int i = 0, j = 0; i < n; i++){
        while (pt[i].x - pt[j].x >= res)
            s.erase({pt[j].y, pt[j].x}), j++;
        auto l = s.lb({pt[i].y - res, pt[i].x});
        auto r = s.ub({pt[i].y + res, pt[i].x});
        for (; l != r; l++)
            res = min(res, dis(pt[i], {l->y, l->x}));
        s.insert({pt[i].y, pt[i].x});
    }
    cout << res << '\n';
}