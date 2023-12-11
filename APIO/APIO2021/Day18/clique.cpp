#include <bits/stdc++.h>

using namespace std;

#define ctz __builtin_ctzll
#define popcnt __builtin_popcountll

long long adj[100];
int N, M, K, deg[606]; bool flag;
vector <int> A[606], B[606];
bool C[606][606];

void rec(long long cur, long long rem) {
    if (flag) return;
    if (popcnt(cur) + popcnt(rem) < K) return;
    if (popcnt(cur) >= K) {
        while (K--) {
            cout << ctz(cur) + 1 << ' ';
            cur -= cur & -cur;
        }
        cout << '\n'; flag = 1; return;
    }
    int u = ctz(rem);
    rec(cur | (1ll << u), rem & adj[u]);
    rec(cur, rem ^ (1ll << u));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) {
        cin >> N;
        if (N <= 60) {
            cin >> M >> K; flag = 0;
            memset(adj, 0, sizeof adj);
            while (M--) {
                int u, v; cin >> u >> v;
                u--; v--;
                adj[u] |= 1ll << v;
                adj[v] |= 1ll << u;
            }
            rec(0, (1ll << N) - 1);
            if (!flag) cout << "-1\n";
        } else {
            cin >> M >> K;
            for (int i = 1; i <= N; i++) {
                A[i].clear(); B[i].clear();
            }
            memset(C, 0, sizeof C);
            memset(deg, 0, sizeof deg);
            while (M--) {
                int u, v; cin >> u >> v;
                A[u].push_back(v);
                A[v].push_back(u);
                deg[u]++; deg[v]++;
                C[u][v] = C[v][u] = 1;
            }
            for (int u = 1; u <= N; u++)
                for (int v = 1; v <= N; v++)
                    if (!C[u][v])
                        B[u].push_back(v);
            vector <int> ans;
            for (int i = 1; i <= K; i++) {
                int u = max_element(deg + 1,
                deg + N + 1) - deg;
                if (deg[u] < 0) break;
                ans.push_back(u);
                for (int v : B[u]) {
                    if (deg[v] < 0) continue;
                    deg[v] = -1;
                    for (int w : A[v]) deg[w]--;
                }
            }
            if (ans.size() == K) {
                for (int u : ans)
                    cout << u << ' ';
            } else cout << -1;
            cout << '\n';
        }
    }
}