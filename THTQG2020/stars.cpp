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

ll cal(cp a, cp b, cp c) {
    return abs(cross(a, b) +
    cross(b, c) + cross(c, a));
}

const int N = 200005;

point a[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i <= n; i++)
        cin >> a[i].x >> a[i].y;
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        vector <int> le, ri;
        for (int j = 1; j <= n; j++)
            if (ccw(a[i], a[0], a[j]))
                le.push_back(j);
            else if (cw(a[i], a[0], a[j]))
                ri.push_back(j);
        for (int j : le)
            for (int k : ri)
                if (ccw(a[j], a[0], a[k]))
                    res++;
    }
    res /= 3; cout << res << '\n';
}
