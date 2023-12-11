#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

struct edge {
    int u, v; long long w;
    
    edge(int u, int v, long long w): u(u), v(v), w(w) {}
};

const int MAXN = 100;

long long A[MAXN], ans[MAXN], dis[MAXN];

void solve() {
    int N; long long K; cin >> N >> K; K *= 8;
    for (int i = 0; i < N; i++) {
        cin >> A[i]; ans[i] = 0; A[i] *= 8;
        for (int mask = 0; mask < (1 << i); mask++) {
            vector <int> pos; bool flag = false;
            for (int j = 0; j < i; j++) {
                if (!(mask >> j & 1) && ans[j] == 1) {
                    flag = true; break;
                }
                if ((mask >> j & 1) && ans[j] == 2) {
                    flag = true; break;
                }
                if (mask >> j & 1) pos.push_back(j);
            }
            if (flag) continue;
            if (mask == 0) {
                flag = false;
                for (int j = 0; j < i; j++)
                    if (ans[j] == 3 && !(mask >> j & 1) && K >= A[j]) {
                        flag = true; break;
                    }
                if (K >= A[i]) flag = true;
                if (flag) continue;
                ans[i] += 2; goto done1;
            }
            do {
                vector <edge> grp; flag = false;
                for (int j = 0; j <= i; j++)
                    if ((ans[j] == 3 && !(mask >> j & 1)) || j == i) {
                        vector <int> tmp;
                        for (int k = 0; k < pos.size(); k++)
                            if (pos[k] < j) tmp.push_back(pos[k]);
                        if (tmp.empty()) {
                            if (K >= A[j]) {
                                flag = true; break;
                            }
                        } else {
                            for (int k = 0; k + 1 < tmp.size(); k++)
                                grp.emplace_back(tmp[k], tmp[k + 1], A[tmp[k]] + A[j] - 1);
                            grp.emplace_back(N, tmp[0], A[j] - 1);
                            grp.emplace_back(tmp.back(), N, A[tmp.back()] - K + A[j] - 1);
                        }
                    }
                if (flag) continue;
                for (int j = 0; j + 1 < pos.size(); j++)
                    grp.emplace_back(pos[j + 1], pos[j], -A[pos[j]]);
                grp.emplace_back(pos[0], N, 0);
                grp.emplace_back(N, pos.back(), K - A[pos.back()]);
                memset(dis, 0x3f, sizeof dis);
                for (int st = 0; st < pos.size(); st++)
                    for (auto e : grp)
                        cmin(dis[e.v], dis[e.u] + e.w);
                bool neg = false;
                for (auto e : grp)
                    if (cmin(dis[e.v], dis[e.u] + e.w)) {
                        neg = true; break;
                    }
                if (!neg) {
                    ans[i] += 2; goto done1;
                }
            } while (next_permutation(pos.begin(), pos.end()));
        }
        done1:;
        for (int mask = 0; mask < (1 << i); mask++) {
            vector <int> pos; bool flag = false;
            long long len = 1e12;
            for (int j = 0; j < i; j++) {
                if (!(mask >> j & 1) && ans[j] == 1) {
                    flag = true; break;
                }
                if ((mask >> j & 1) && ans[j] == 2) {
                    flag = true; break;
                }
                if (mask >> j & 1) pos.push_back(j);
                else if (ans[j] == 3) len = min(len, A[j]);
            }
            if (flag) continue;
            if (mask == 0) {
                flag = false;
                for (int j = 0; j < i; j++)
                    if (ans[j] == 3 && !(mask >> j & 1) && K >= A[j]) {
                        flag = true; break;
                    }
                if (K < A[i]) flag = true;
                if (flag) continue;
                ans[i] += 1; goto done2;
            }
            pos.push_back(i);
            do {
                vector <edge> grp; flag = false;
                for (int j = 0; j < i; j++)
                    if (ans[j] == 3 && !(mask >> j & 1)) {
                        vector <int> tmp;
                        for (int k = 0; k < pos.size(); k++)
                            if (pos[k] < j) tmp.push_back(pos[k]);
                        if (tmp.empty()) {
                            if (K >= A[j]) {
                                flag = true; break;
                            }
                        } else {
                            for (int k = 0; k + 1 < tmp.size(); k++)
                                grp.emplace_back(tmp[k], tmp[k + 1], A[tmp[k]] + A[j] - 1);
                            grp.emplace_back(N, tmp[0], A[j] - 1);
                            grp.emplace_back(tmp.back(), N, A[tmp.back()] - K + A[j] - 1);
                        }
                    }
                if (flag) continue;
                for (int j = 0; j + 1 < pos.size(); j++)
                    grp.emplace_back(pos[j + 1], pos[j], -A[pos[j]]);
                grp.emplace_back(pos[0], N, 0);
                grp.emplace_back(N, pos.back(), K - A[pos.back()]);
                memset(dis, 0x3f, sizeof dis);
                for (int st = 0; st < pos.size(); st++)
                    for (auto e : grp)
                        cmin(dis[e.v], dis[e.u] + e.w);
                bool neg = false;
                for (auto e : grp)
                    if (cmin(dis[e.v], dis[e.u] + e.w)) {
                        neg = true; break;
                    }
                if (!neg) {
                    ans[i] += 1; goto done2;      
                }
            } while (next_permutation(pos.begin(), pos.end()));
        }
        done2:;
        if (ans[i] == 1) cout << "sit ";
        else if (ans[i] == 2) cout << "stand ";
        else cout << "unsure ";
    }
    cout << '\n';
}

int main() {
    freopen("seats.inp", "r", stdin);
    freopen("seats.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}


