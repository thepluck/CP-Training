#include <bits/stdc++.h>

using namespace std;

using Tp = long long;

struct point {
    Tp x, y;

    point(Tp x = 0, Tp y = 0): x(x), y(y) {}

    point& operator -= (const point &o) {
        x -= o.x; y -= o.y; return *this;
    }

    point operator - (const point &o) const {
        return point(*this) -= o;
    }
};

Tp dot(const point &a, const point &b) {
    return a.x * b.x + a.y * b.y;
}

Tp cross(const point &a, const point &b) {
    return a.x * b.y - a.y * b.x;
}

Tp norm(const point &p) {
    return p.x * p.x + p.y * p.y;
}

int half(const point &p) {
    return p.x < 0 || (p.x == 0 && p.y < 0);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    if (N == 1) return cout << "Possible\n1", 0;
    vector<pair<point, int>> P;
    {
        point p1, p2;
        for (int i = 1; i <= N; i++) {
            cin >> p2.x >> p2.y;
            if (i == 1) p1 = p2;
            else P.emplace_back(p2 - p1, i);
        }
    }
    sort(P.begin(), P.end(),
    [&](const pair<point, int> &a,
    const pair<point, int> &b) {
        if (half(a.first) != half(b.first))
            return half(a.first) < half(b.first);
        if (cross(a.first, b.first) == 0)
            return norm(a.first) < norm(b.first);
        return cross(a.first, b.first) > 0;
    });
    vector <vector <int>> chain;
    for (int i = 0; i + 1 < N; ) {
        chain.emplace_back();
        chain.back().push_back(P[i].second);
        int j = i + 1;
        while (j + 1 < N && cross
        (P[i].first, P[j].first) == 0)
            chain.back().push_back(P[j++].second);
        i = j;
    }
    if (chain.size() == 1)
        return cout << "Impossible", 0;
    cout << "Possible\n1";
    for (int i : chain[0]) cout << '\n' << i;
    for (int i = 1; i < chain.size(); i++)
        for (auto it = chain[i].rbegin();
        it != chain[i].rend(); it = next(it))
            cout << '\n' << *it;
}