#include <bits/stdc++.h>
using namespace std;

template <class T>
struct heap {
    vector <int> val, pos;
    vector <T> prio; int n = 0;

    heap(int n = 0): val(n + 5),
    pos(n + 5), prio(n + 5) {}

    int size() const {
        return n;
    }

    bool empty() const {
        return n == 0;
    }

    void up_heap(int i) {
        int r, c = pos[i];
        while (true) {
            r = c / 2;
            if (!r || prio[i] >=
            prio[val[r]]) break;
            val[c] = val[r];
            pos[val[c]] = c;
            c = r;
        }
        val[c] = i; pos[i] = c;
    }

    void down_heap(int i) {
        int r = pos[i], c;
        while (true) {
            c = r * 2;
            if (c < n && prio[val[c]]
            > prio[val[c + 1]]) c++;
            if (c > n || prio[i] <=
            prio[val[c]]) break;
            val[r] = val[c];
            pos[val[r]] = r;
            r = c;
        }
        val[r] = i; pos[i] = r;
    }

    pair <int, T> top() const {
        return {val[1], prio[val[1]]};
    }

    void push(int i, T p) {
        prio[i] = p; n++;
        val[n] = i; pos[i] = n;
        up_heap(i);
    }

    void pop() {
        pos[val[1]] = 0;
        prio[val[1]] = 0;
        val[1] = val[n--];
        pos[val[1]] = 1;
        if (n > 1) down_heap(val[1]);
    }

    void update(int i, T p) {
        if (prio[i] < p) {
            prio[i] = p;
            down_heap(i);
        }
        else {
            prio[i] = p;
            up_heap(i);
        }
    }
};

template <class T>
struct edge {
    int v; T w;

    edge(int v, T w): v(v), w(w) {}
};

const int N = 500005;
const long long inf = 1e18;

vector <edge <int>> g[N];
long long d[N]; int tr[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    memset(tr, -1, sizeof tr);
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    heap <long long> pq(n);
    for (int i = 0; i < n; i++)
        if (i == s)
            pq.push(i, d[i] = 0);
        else pq.push(i, d[i] = inf);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    while (pq.size()) {
        int u; long long w;
        tie(u, w) = pq.top(); pq.pop();
        if (w == inf) break;
        for (auto e : g[u])
            if (d[e.v] > w + e.w) {
                d[e.v] = w + e.w;
                tr[e.v] = u;
                pq.update(e.v, d[e.v]);
            }
    }
    vector <int> path;
    if (d[t] == inf) {
        cout << "-1\n"; return 0;
    }
    cout << d[t] << '\n';
    while (~t) {
        path.push_back(t); t = tr[t];
    }
    cout << path.size() - 1 << '\n';
    while (path.size() > 1) {
        cout << path.back() << ' ';
        path.pop_back();
        cout << path.back() << '\n';
    }
}