#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
const int S = 100;
const int Q = 1000005;

vector<pair<int, int>> adj[N];
vector<int> pos[N];
int p[N], a[N], bit[N];
long long delta[Q];

void add(int i) {
    for (; i > 0; i -= i & -i) bit[i]++;
}

int get(int i) {
    int res = 0;
    for (; i < N; i += i & -i) res += bit[i];
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k, q;
    cin >> n >> k >> q;
    long long inv = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; p[i] = i;
        pos[a[i]].push_back(i);
        inv += get(a[i] + 1); add(a[i]);
    }
    for (int i = 1; i <= q; i++) {
        int x; cin >> x; swap(p[x], p[x + 1]);
        int y = p[x + 1]; x = p[x];
        if (pos[x].size() >= S) adj[x].emplace_back(y, i);
        else if (pos[y].size() >= S) adj[y].emplace_back(x, -i);
        else {
            delta[i] = pos[x].size() * pos[y].size();
            for (int yi = 0, xi = 0; yi < pos[y].size(); yi++) {
                while (xi < pos[x].size() && pos[x][xi] < pos[y][yi]) xi++;
                delta[i] -= xi * 2;
            }
        }
    }
    for (int x = 1; x <= n; x++) {
        if (pos[x].size() < S) continue;
        memset(bit, 0, sizeof bit);
        for (int i : pos[x]) bit[i] = 1;
        for (int i = 1; i <= n; i++) bit[i] += bit[i - 1];
        sort(adj[x].begin(), adj[x].end());
        for (int i = 0; i < adj[x].size(); ) {
            int y = adj[x][i].first;
            long long res = pos[x].size() * pos[y].size();
            for (int j : pos[y]) res -= bit[j] * 2;
            while (i < adj[x].size() && adj[x][i].first == y) {
                if (adj[x][i].second > 0)
                    delta[adj[x][i].second] = res;
                else delta[-adj[x][i].second] = -res;
                i++;
            }
        }
    }
    for (int i = 1; i <= q; i++) {
        inv += delta[i]; cout << inv << '\n';
    }
}