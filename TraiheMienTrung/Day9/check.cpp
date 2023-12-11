#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back

struct chess {
    char t; int x, y;

    chess(char t, int x, int y):
    t(t), x(x), y(y) {}
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("check.inp", "r", stdin);
    freopen("check.out", "w", stdout);
    int n;
    while (cin >> n) {
        if (n == -1) return 0;
        int x, y; cin >> x >> y;
        vector <chess> a, b, c, d;
        chess king = {'K', x, y};
        a.push_back(king);
        b.push_back(king);
        c.push_back(king);
        d.push_back(king);
        while (n--) {
            char cc; int i, j;
            cin >> cc >> i >> j;
            chess cur = {cc, i, j};
            if (i == x) a.push_back(cur);
            if (j == y) b.push_back(cur);
            if (i + j == x + y) c.push_back(cur);
            if (i - j == x - y) d.push_back(cur);
        }
        auto cmp = [](chess p, chess q) {
            return p.x < q.x ||
            (p.x == q.x && p.y < q.y);
        };
        sort(a.begin(), a.end(), cmp);
        sort(b.begin(), b.end(), cmp);
        sort(c.begin(), c.end(), cmp);
        sort(d.begin(), d.end(), cmp);
        bool flag = 0;
        for (int i = 0; i < a.size(); i++)
            if (a[i].t == 'K') {
                if (i > 0 &&
                (a[i - 1].t == 'R' ||
                 a[i - 1].t == 'Q'))
                flag = true;
                if (i < a.size() - 1 &&
                (a[i + 1].t == 'R' ||
                 a[i + 1].t == 'Q'))
                flag = true;
            }
        for (int i = 0; i < b.size(); i++)
            if (b[i].t == 'K') {
                if (i > 0 &&
                (b[i - 1].t == 'R' ||
                 b[i - 1].t == 'Q'))
                flag = true;
                if (i < b.size() - 1 &&
                (b[i + 1].t == 'R' ||
                 b[i + 1].t == 'Q'))
                flag = true;
            }
        for (int i = 0; i < c.size(); i++)
            if (c[i].t == 'K') {
                if (i > 0 &&
                (c[i - 1].t == 'B' ||
                 c[i - 1].t == 'Q'))
                flag = true;
                if (i < c.size() - 1 &&
                (c[i + 1].t == 'B' ||
                 c[i + 1].t == 'Q'))
                flag = true;
            }
        for (int i = 0; i < d.size(); i++)
            if (d[i].t == 'K') {
                if (i > 0 &&
                (d[i - 1].t == 'B' ||
                 d[i - 1].t == 'Q'))
                flag = true;
                if (i < d.size() - 1 &&
                (d[i + 1].t == 'B' ||
                 d[i + 1].t == 'Q'))
                flag = true;
            }
        cout << (flag ? "YES\n" : "NO\n");
    }
}
