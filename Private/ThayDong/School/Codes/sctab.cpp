#include <bits/stdc++.h>
using namespace std;

vector <char> vs(10);
int n, m, res = INT_MAX, cur;
vector <vector <int>> a;
vector <int> p, q;

void rec() {
    if (cur > res) return;
    if (p == q) res = min(res, cur);
    vector <int> r = p; int tmp = cur;
    for (int j = 0; j < m; j++) {
        if (vs[j]) continue; p = r;
        stable_sort(p.begin(), p.end(),
        [&](int x, int y) {
            return a[x][j] < a[y][j];
        });
        cur = tmp * 10 + j + 1;
        vs[j] = 1; rec(); vs[j] = 0;
    }
}

int main() {
    freopen("sctab.inp", "r", stdin);
    freopen("sctab.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int s; cin >> n >> m >> s;
    a.resize(n, vector <int> (m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    for (int i = 0; i < n; i++) {
        p.push_back(i); q.push_back(i);
    }
    while (s--) {
        int j; cin >> j; j--;
        stable_sort(q.begin(), q.end(),
        [&](int x, int y) {
            return a[x][j] < a[y][j];
        });
    }
    rec(); stack <int> st;
    while (res > 0) {
        st.push(res % 10); res /= 10;
    }
    cout << st.size() << '\n';
    while (st.size()) {
        cout << st.top() << ' ';
        st.pop();
    }
}