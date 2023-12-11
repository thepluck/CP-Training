#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

struct triple {
    int a, b, c;

    triple(int a, int b, int c): a(a), b(b), c(c) {}

    bool operator < (const triple &o) const {
        return a < o.a || (a == o.a && b < o.b)
        || (a == o.a && b == o.b && c < o.c);
    }
};

const int MAXN = 100005;

vector <int> can;
int pos[MAXN], deg[MAXN];
deque <int> per; int timer;
multiset <triple> req;
vector <triple> adj[MAXN];

void rec() {
    int p = can.back(); can.pop_back();
    if (--timer == 0) {
        per.push_back(p); return;
    }
    vector <pair <int, int>> cur;
    for (triple tr : adj[p]) {
        if (!req.count(tr)) continue;
        req.erase(req.find(tr));
        if (tr.a == p) {
            cur.emplace_back(tr.c, tr.b);
            if (--deg[tr.b] == 0)
                can.push_back(tr.b);
        } else if (tr.c == p) {
            cur.emplace_back(tr.a, tr.b);
            if (--deg[tr.b] == 0)
                can.push_back(tr.b);
        }
    }
    rec(); int cnt[] = {0, 0};
    for (auto pp : cur)
        cnt[pos[pp.fi] < pos[pp.se]]++;
    if (cnt[0] < cnt[1]) {
        pos[p] = pos[per.back()] + 1;
        per.push_back(p);
    } else {
        pos[p] = pos[per.front()] - 1;
        per.push_front(p);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    for (int i = 0, a, b, c; i < M; i++) {
        cin >> a >> b >> c; deg[b]++;
        req.emplace(a, b, c);
        adj[a].emplace_back(a, b, c);
        adj[c].emplace_back(a, b, c);
    }
    for (int i = 1; i <= N; i++)
        if (deg[i] == 0)
            can.push_back(i);
    timer = N; rec();
    for (int p : per) cout << p << ' ';
}
