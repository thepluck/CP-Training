#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

struct rectangle {
    int B, L, T, R;
};

const int MOD = 1000000007;
const int MAXN = 2005;

int M, N, K, L, way;
int F[MAXN], G[MAXN];
set <pair <int, int>> pts;
vector <pair <int, int>> req;
vector <rectangle> rec;
bool used[100];

bool intersect(const rectangle &p,
const rectangle &q) {
    if (min(p.T, q.T) < max(p.B, q.B))
        return false;
    if (min(p.R, q.R) < max(p.L, q.L))
        return false;
    return true;
}

int add(int x, int y) {
    if ((x += y) >= MOD) x -= MOD;
    return x;
}

int mul(int x, int y) {
    return (long long)x * y % MOD;
}

int calc(int W, int H) {
    if (W > H) swap(W, H);
    if (W == L) return F[H];
    if (H % L) return 0;
    if (L == 1 || W < L) return 1;
    int res = 1;
    for (int i = L; i <= H; i += L) {
        G[i] = mul(F[i - 1], W - L + 1);
        for (int j = L; j < i; j += L)
            G[i] = add(G[i], mul(G[j],
            mul(F[i - j - 1], W - L)));
        res = add(res, G[i]);
    }
    return res;
}

void DFS(int dep) {
    if (dep == K) return void(way++);
    int x, y; tie(x, y) = *pts.begin();
    pts.erase(pts.begin());
    for (int i = 0; i < K; i++)
        if (!used[i]) {
            rectangle p = {x, y, x +
            req[i].fi, y + req[i].se};
            bool flag = false;
            for (auto q : rec)
                if (intersect(p, q)) flag = true;
            if (flag) continue;
            if (p.T > M || p.R > N) continue;
            for (auto q : rec)
                if (q.R > p.R && q.T == x - 1)
                    pts.emplace(x, p.R + 1);
            for (auto q : rec)
                if (q.T > p.T && q.R == y - 1)
                    pts.emplace(p.T + 1, y);
            rec.push_back(p); used[i] = true;
            DFS(dep + 1);
            rec.pop_back(); used[i] = false;
            for (auto q : rec)
                if (q.R > p.R && q.T == x - 1)
                    pts.erase({x, p.R + 1});
            for (auto q : rec)
                if (q.T > p.T && q.R == y - 1)
                    pts.erase({p.T + 1, y});
    }       
    for (int i = 0; i < K; i++)
        if (!used[i] && req[i].fi != req[i].se) {
            rectangle p = {x, y, x +
            req[i].se, y + req[i].fi};
            bool flag = false;
            for (auto q : rec)
                if (intersect(p, q)) flag = true;
            if (flag) continue;
            if (p.T > M || p.R > N) continue;
            for (auto q : rec)
                if (q.R > p.R && q.T == x - 1)
                    pts.emplace(x, p.R + 1);
            for (auto q : rec)
                if (q.T > p.T && q.R == y - 1)
                    pts.emplace(p.T + 1, y);
            rec.push_back(p); used[i] = true;
            DFS(dep + 1);
            rec.pop_back(); used[i] = false;
            for (auto q : rec)
                if (q.R > p.R && q.T == x - 1)
                    pts.erase({x, p.R + 1});
            for (auto q : rec)
                if (q.T > p.T && q.R == y - 1)
                    pts.erase({p.T + 1, y});
            
        }
    pts.emplace(x, y);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> M >> N >> K >> L;
    if (M > N) swap(M, N);
    for (int i = 0; i < L; i++) F[i] = 1;
    for (int i = L; i <= N; i++)
        F[i] = add(F[i - 1], F[i - L]);
    int res = 1;
    for (int i = 0; i < K; i++) {
        int W, H; cin >> W >> H;
        req.emplace_back(W - 1, H - 1);
        res = mul(res, calc(W, H));
    }
    rec.push_back({1, 0, M, 0});
    rec.push_back({0, 1, 0, N});
    pts.emplace(1, 1); DFS(0);
    cout << mul(way, res) << '\n';
}
