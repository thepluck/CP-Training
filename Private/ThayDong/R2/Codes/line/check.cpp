#include <bits/stdc++.h>

using namespace std;

pair <int, int> a[100005], b[100005];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ifstream fi("test/test003/line.inp");
    ifstream fo("test/test003/line.out");
    int n; fi >> n; int m; fo >> m;
    for (int i = 1; i <= n; i++)
        fi >> a[i].first >> a[i].second;
    for (int i = 1; i <= m; i++)
        fo >> b[i].first >> b[i].second;
    for (int i = 1; i <= n; i++) {
        bool flag = false;
        for (int j = 0; j < m; j++) {
            if (a[i].first == b[j].first &&
            a[i].first == b[j + 1].first) {
                int x, y;
                tie(x, y) = minmax(b[j].second, b[j + 1].second);
                if (x <= a[i].second && y >= a[i].second) flag = true;
            }
            if (a[i].second == b[j].second &&
            a[i].second == b[j + 1].second) {
                int x, y;
                tie(x, y) = minmax(b[j].first, b[j + 1].first);
                if (x <= a[i].first && y >= a[i].first) flag = true;
            }
        }
        if (!flag) {
            cout << a[i].first << ' ' << a[i].second << '\n'; return 0;
        }
    }
}