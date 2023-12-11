#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

const int N = 205;
const long long INF = 0x3f3f3f3f3f3f3f3f;

string s[N];
long long f[N][N], g[N][N];
int n, m, x; vector <int> id;
set <pair <string, string>> p;


void floyd() {
    int x = id.size();
    for (int k = 0; k < x; k++)
        for (int i = 0; i < x; i++)
            for (int j = 0; j < x; j++)
                g[id[i]][id[j]] = min(g[id[i]][id[j]],
                g[id[i]][id[k]] + g[id[k]][id[j]]);
}

int main() {
    freopen("suffix.in", "r", stdin);
    freopen("suffix.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int test = 0;
    while (cin >> s[0]) {
        if (s[0] == ".") break;
        cout << "Case " << ++test << ": ";
        cin >> s[1] >> n;
        int l = s[0].size(); p.clear();
        for (int i = 1; i <= n; i++) {
            cin >> s[2 * i] >> s[2 * i + 1];
            p.emplace(s[2 * i], s[2 * i + 1]);
        }
        memset(f, 0, sizeof f);
        m = (n + 1) * 2; id.clear();
        for (int d = 1; d <= l; d++) {
            memset(g, 0x3f, sizeof g);
            for (int i = 0; i < m; i++) {
                if (s[i].size() < d) continue;
                id.push_back(i);
                for (int j = 0; j < m; j++) {
                    if (s[j].size() < d) continue;
                    pair <string, string> pp(
                    s[i].substr(s[i].size() - d, d),
                    s[j].substr(s[j].size() - d, d));
                    if (p.count(pp)) g[i][j] = 1;
                    else if (pp.fi[0] == pp.se[0])
                        g[i][j] = f[i][j];
                }
            }
            floyd(); swap(f, g);
        }
        if (f[0][1] == INF)
            cout << "No solution\n";
        else cout << f[0][1] << '\n';
    }
}
