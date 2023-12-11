#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int N, A[MAXN], pos[MAXN];
int rig[MAXN], col[MAXN];
int ST1[MAXN * 4], lo, hi, id;
vector <int> ST2[MAXN * 4];
vector <int> res;

bool comp(int i, int j) {
    return A[i] > A[j];
}

void build(int i, int l, int r) {
    if (l == r) ST1[i] = l;
    else {
        int m = (l + r) / 2;
        build(i * 2, l, m);
        build(i * 2 + 1, m + 1, r);
        if (comp(ST1[i * 2], ST1[i * 2 + 1]))
            ST1[i] = ST1[i * 2];
        else ST1[i] = ST1[i * 2 + 1];
    }
}

void update(int i, int l, int r) {
    if (l == r) ST1[i] = 0;
    else {
        int m = (l + r) / 2;
        if (m >= lo) update(i * 2, l, m);
        else update(i * 2 + 1, m + 1, r);
        if (comp(ST1[i * 2], ST1[i * 2 + 1]))
            ST1[i] = ST1[i * 2];
        else ST1[i] = ST1[i * 2 + 1];
    }
}

void query(int i, int l, int r) {
    if (l >= lo && r <= hi) {
        if (comp(ST1[i], id))
            id = ST1[i];
        return;
    }
    int m = (l + r) / 2;
    if (m >= lo) query(i * 2, l, m);
    if (m < hi) query(i * 2 + 1, m + 1, r);
}

void update(int p) {
    lo = p; update(1, 1, N);
}

void query(int l, int r) {
    lo = l; hi = r; id = 0;
    query(1, 1, N);
}

void add(int i, int l, int r) {
    if (l >= lo && r <= hi)
        return ST2[i].push_back(lo);
    int m = (l + r) / 2;
    if (m >= lo) add(i * 2, l, m);
    if (m < hi) add(i * 2 + 1, m + 1, r);
}

void find(int i, int l, int r) {
    while (ST2[i].size() &&
    comp(lo, ST2[i].back())) {
        res.push_back(ST2[i].back());
        ST2[i].pop_back();
    }
    if (l != r) {
        int m = (l + r) / 2;
        if (m >= lo) find(i * 2, l, m);
        else find(i * 2 + 1, m + 1, r);
    }
}

void add(int l, int r) {
    lo = l; hi = r; add(1, 1, N);
}

void find(int p) {
    lo = p; res.clear(); find(1, 1, N);
}

void DFS(int u) {
    update(u);
    while (true) {
        query(u, rig[u]);
        if (comp(id, u)) {
            col[id] = col[u] ^ 1; DFS(id);
        } else break;
    }
    find(u); vector <int> tmp = res;
    for (int v : tmp)
        if (col[v] < 0) {
            col[v] = col[u] ^ 1; DFS(v);
        }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 1, j = 1; i <= N; i++) {
        cin >> A[i]; pos[A[i]] = i;
        while (j <= N && pos[j])
            rig[pos[j++]] = i;
    }
    build(1, 1, N);
    for (int i = N; i > 0; i--)
        add(pos[i], rig[pos[i]]);
    memset(col, -1, sizeof col);
    for (int i = 1; i <= N; i++)
        if (col[i] < 0) {
            col[i] = 0; DFS(i);
        }
    stack <int> S[2];
    S[0].push(N + 2); S[1].push(N + 2);
    for (int i = 1, j = 1; i <= N; i++) {
        if (A[i] > S[col[i]].top())
            return cout << "NIE\n", 0;
        S[col[i]].push(A[i]);
        while (true) {
            if (S[0].top() == j) {
                S[0].pop(); j++;
            } else if (S[1].top() == j) {
                S[1].pop(); j++;
            } else break;
        }
    }
    cout << "TAK\n";
    for (int i = 1; i <= N; i++)
        cout << col[i] + 1 << ' ';
}
