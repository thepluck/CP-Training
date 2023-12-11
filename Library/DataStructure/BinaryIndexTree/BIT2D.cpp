#include <bits/stdc++.h>

using namespace std;

struct query {
    int t, x, y;

    query(int t, int x, int y):
    t(t), x(x), y(y) {}
};

struct BIT2D {
    vector <vector <int>> node, val; int N;

    BIT2D(int N): N(N), node(N + 5), val(N + 5) {}

    void pre_add(int x, int y) {
        for (x++; x <= N + 1; x += x & -x)
            node[x].push_back(y);
    }

    void add(int x, int y, int v) {
        for (x++; x <= N + 1; x += x & -x) {
            for (int z = upper_bound(node[x].begin(),
            node[x].end(), y) - node[x].begin();
            z <= int(node[x].size()); z += z & -z)
                val[x][z - 1] += v;
        }
    }

    void normalize() {
        for (int i = 1; i <= N + 1; i++) {
            sort(node[i].begin(), node[i].end());
            node[i].erase(unique(node[i].begin(),
            node[i].end()), node[i].end());
            val[i].resize(node[i].size());
        }
    }

    int get(int x, int y) {
        int res = 0;
        for (x++; x > 0; x -= x & -x) {
            for (int z = upper_bound(node[x].begin(),
            node[x].end(), y) - node[x].begin();
            z > 0; z -= z & -z)
                res += val[x][z - 1];
        }
        return res;
    }
};

const int MAXN = 200005;

set <int> pos[MAXN];
int A[MAXN], B[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    vector <int> rar;
    vector <query> que;
    for (int i = 1; i <= N; i++) {
        cin >> A[i]; rar.push_back(A[i]);
    }
    for (int i = 1, t, x, y; i <= Q; i++) {
        cin >> t >> x >> y;
        que.emplace_back(t, x, y);
        if (t == 1) rar.push_back(y);
    }
    sort(rar.begin(), rar.end());
    rar.erase(unique(rar.begin(),
    rar.end()), rar.end());
    for (int i = 1; i <= N; i++)
        B[i] = A[i] = lower_bound(rar.begin(),
        rar.end(), A[i]) - rar.begin();
    for (auto &q : que) if (q.t == 1)
        q.y = lower_bound(rar.begin(),
        rar.end(), q.y) - rar.begin();
    for (int i = 0; i < int(rar.size()); i++)
        pos[i].insert(0);
    BIT2D BIT(N + 1);
    for (int i = 1; i <= N; i++) {
        BIT.pre_add(*pos[A[i]].rbegin(), i);
        pos[A[i]].insert(i);
    }
    for (auto q : que) if (q.t == 1) {
        auto it = pos[B[q.x]].find(q.x);
        if (next(it) != pos[B[q.x]].end())
            BIT.pre_add(*prev(it), *next(it));
        pos[B[q.x]].erase(it);
        it = pos[q.y].insert(q.x).first;
        BIT.pre_add(*prev(it), q.x);
        if (next(it) != pos[q.y].end())
            BIT.pre_add(q.x, *next(it));
        B[q.x] = q.y;
    }
    BIT.normalize();
    for (int i = 0; i < int(rar.size()); i++) {
        pos[i].clear(); pos[i].insert(0);
    }
    for (int i = 1; i <= N; i++) {
        BIT.add(*pos[A[i]].rbegin(), i, 1);
        pos[A[i]].insert(i);
    }
    for (auto q : que) if (q.t == 1) {
        auto it = pos[A[q.x]].find(q.x);
        auto it1 = prev(it), it2 = next(it);
        BIT.add(*it1, q.x, -1);
        if (it2 != pos[A[q.x]].end()) {
            BIT.add(q.x, *it2, -1);
            BIT.add(*it1, *it2, 1);
        }
        pos[A[q.x]].erase(it);
        it = pos[q.y].insert(q.x).first;
        it1 = prev(it); it2 = next(it);
        BIT.add(*it1, q.x, 1);
        if (it2 != pos[q.y].end()) {
            BIT.add(*it1, *it2, -1);
            BIT.add(q.x, *it2, 1);
        }
        A[q.x] = q.y;
    } else cout << BIT.get(q.x - 1, q.y)
    - BIT.get(q.x - 1, q.x - 1) << '\n';
}