#include <bits/stdc++.h>

using namespace std;

struct item {
    int x, y, t;

    item() {}

    item(int x, int y, int t):
    x(x), y(y), t(t) {}
};

vector <int> per, pos, D;
vector <long long> BIT;
int N, M, Q;
vector <item> B, C;

void add(int i, long long v) {
    for (; i <= N; i += i & -i)
        BIT[i] += v;
}

long long sum(int i) {
    long long res = 0;
    for (; i > 0; i -= i & - i)
        res += BIT[i];
    return res;
}

long long sum(int l, int r) {
    return sum(r) - sum(l - 1);
}

void Swap1(int i, int j) {
    swap(pos[per[i]], pos[per[j]]);
    swap(per[i], per[j]);
}

void Swap2(int i, int j) {
    add(per[i], 1ll * j * j - 1ll * i * i);
    add(per[j], 1ll * i * i - 1ll * j * j);
    swap(per[i], per[j]);
}

void solve(int l, int r, int x, int y) {
    if (l + 1 == r) return;
    int m = (l + r) / 2;
    solve(l, m, x, D[m]);
    solve(m, r, D[m], y);
    int i = x, j = D[m], k = x;
    while (i < D[m] && j < y) {
        if (B[i].t > B[j].t) {
            C[k++] = {pos[B[j].x],
            pos[B[j].y], B[j].t}; j++;
        } else {
            C[k++] = B[i];
            Swap1(B[i].x, B[i].y); i++;
        }
    }
    while (i < D[m]) {
        C[k++] = B[i];
        Swap1(B[i].x, B[i].y); i++;
    }
    while (j < y) {
        C[k++] = {pos[B[j].x],
        pos[B[j].y], B[j].t}; j++;
    }
    for (i = D[m] - 1; i >= x; i--)
        Swap1(B[i].x, B[i].y);
    for (i = x; i < y; i++) B[i] = C[i];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    vector <vector <item>> A(M);
    vector <item> ask;
    for (int r = 0; r < M; r++) {
        int p; cin >> p;
        int t = M - r - 1;
        A[r].emplace_back(p, p + 1, t);
    }
    cin >> Q;
    for (int t = M; t < M + Q; t++) {
        int cmd; cin >> cmd;
        if (cmd == 1) {
            int r, p; cin >> r >> p;
            item c = A[--r].back();
            A[r].emplace_back(c.x, c.y, t);
            A[r].emplace_back(p, p + 1, t);
        } else {
            int l, r; cin >> l >> r;
            ask.emplace_back(l, r, t);
        }
    }
    per.resize(N + 1);
    pos.resize(N + 1);
    BIT.resize(N + 1);
    for (int i = 0; i < A.size(); i++) {
        D.push_back(B.size());
        for (item x : A[i]) B.push_back(x);
    }
    C.resize(B.size());
    for (int i = 1; i <= N; i++) {
        per[i] = pos[i] = i;
        add(i, 1ll * i * i);
    }
    solve(0, A.size(), 0, B.size());
    for (int i = 0, j = 0; i < ask.size(); i++) {
        while (j < B.size() && B[j].t < ask[i].t) {
            Swap2(B[j].x, B[j].y); j++;
        }
        cout << sum(ask[i].x, ask[i].y) << '\n';
    }
}
