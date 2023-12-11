#include <bits/stdc++.h>

using namespace std;

struct point {
    int x, y;

    bool operator < (const point &o) const {
        return (x < o.x && y >= o.y) ||
                (x <= o.x && y > o.y);
    }
};

const int MAXN = 100005;
const int LG = 17;

point P[MAXN];
int down[MAXN][LG];
int rig[MAXN][LG];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M, Q;
    cin >> N >> M >> Q;
    for (int i = 1; i <= N; i++)
        cin >> P[i].x >> P[i].y;
    for (int i = 1; i <= M; i++) {
        int u, v; cin >> u >> v;
        if (P[v] < P[u]) swap(u, v);
        if (P[v].x > P[u].x)
            rig[u][0] = v;
        else down[u][0] = v;
    }
    down[N][0] = rig[N][0] = N;
    for (int i = 1; i < N; i++)
        if (!down[i][0] || !rig[i][0]) {
            int x = down[i][0] + rig[i][0];
            down[i][0] = rig[i][0] = x; 
        }
    for (int k = 1; k < LG; k++)
        for (int i = 1; i <= N; i++) {
            down[i][k] = down[down[i][k - 1]][k - 1];
            rig[i][k] = rig[rig[i][k - 1]][k - 1];
        }
    while (Q--) {
        int u, v; cin >> u >> v;
        if (u == v) {
            cout << "Yes\n"; continue;
        }
        if (!(P[u] < P[v] || P[v] < P[u])) {
            cout << "No\n"; continue;
        }
        if (P[v] < P[u]) swap(u, v);
        int w = u;
        for (int k = LG - 1; k >= 0; k--)
            if (P[down[w][k]] < P[v])
                w = down[w][k];
        if (P[w] < P[v]) w = down[w][0];
        if (P[w].x > P[v].x) {
            cout << "No\n"; continue;
        }
        w = u;
        for (int k = LG - 1; k >= 0; k--)
            if (P[rig[w][k]] < P[v])
                w = rig[w][k];
        if (P[w] < P[v]) w = rig[w][0];
        if (P[w].y < P[v].y) {
            cout << "No\n"; continue;
        }
        cout << "Yes\n";
    }
}
