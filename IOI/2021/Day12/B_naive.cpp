#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;
const int MAXC = 100005;
const size_t MAXS = 100005;
const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};


int N, M;
bool vis[MAXN];

#define valid(x, y) (x) >= 0 && (x) < N && (y) >= 0 && (y) < M
#define flat(x, y) (x) * M + (y)
#define comps(x, y) comps[flat(x, y)]

struct component {
    int col, idx;
    vector <int> big;
    vector <vector <int>> grp;
    vector <pair <int, int>> cell;
} comps[MAXN];

int getCol(int u) {
    return comps[comps[u].idx].col;
}

int getCol(int x, int y) {
    return getCol(flat(x, y));
}

vector <int> get(component &a, int col) {
    static int x, y;
    static vector <int> res;

    res.clear();

    if (a.cell.size() >= MAXS) {
        for (int x : a.grp[col]) {
            x = comps[x].idx;
            if (comps[x].col == col)
                res.push_back(x);
        }
        a.grp[col].clear();
        return res;
    }
    if (col) {
        for (auto pp : a.cell) {
            tie(x, y) = pp;
            for (int k = 0; k < 4; k++)
                if (valid(x + dx[k], y + dy[k]) &&
                getCol(x + dx[k], y + dy[k]) == col)
                    res.push_back(comps(x + dx[k], y + dy[k]).idx);
        }
    } else {
        for (auto pp : a.cell) {
            tie(x, y) = pp;
            for (int k = 0; k < 4; k++)
                if (valid(x + dx[k], y + dy[k]) &&
                getCol(x + dx[k], y + dy[k]) != a.col)
                    res.push_back(comps(x + dx[k], y + dy[k]).idx);
        }
    }
    return res;
}

template <class T>
void destroy(vector <T> &v) {
    v.clear();
    v.shrink_to_fit();
}

bool join(int u, int v) {
    static vector <int> tmp;

    u = comps[u].idx; v = comps[v].idx;
    if (u == v) return false;
    if (comps[u].cell.size() < comps[v].cell.size())
        swap(u, v);
    component &a = comps[u];
    component &b = comps[v];
    for (auto pp : b.cell) {
        a.cell.push_back(pp);
        comps(pp.first, pp.second).idx = u;
    }
    for (auto x : b.big)
        a.big.push_back(comps[x].idx);
    for (auto x : a.big) {
        x = comps[x].idx;
        comps[x].grp[a.col].push_back(u);
    }
    if (a.cell.size() < MAXS) {
        if (a.cell.size() + b.cell.size() >= MAXS) {
            tmp = get(a, 0);
            a.grp.resize(MAXC);
            for (int x : tmp) {
                a.grp[comps[x].col].push_back(x);
                comps[x].big.push_back(u);
            }
            tmp = get(b, 0);
            for (int x : tmp) {
                a.grp[comps[x].col].push_back(x);
                comps[x].big.push_back(u);
            }
        }
    } else if (b.cell.size() < MAXS) {
        tmp = get(b, 0);
        for (int x : tmp) {
            a.grp[comps[x].col].push_back(x);
            comps[x].big.push_back(u);
        }
    } else {
        for (int c = 1; c < MAXC; c++) {
            if (a.grp[c].size() < b.grp[c].size())
                swap(a.grp[c], b.grp[c]);
            for (int x : b.grp[c])
                a.grp[c].push_back(x);
            
        }
    }
    destroy(b.cell);
    destroy(b.big);
    destroy(b.grp);
    return true;
}

void print() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cout << getCol(i, j) << " \n"[j == M - 1];
    cout << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    vector <vector <int>> S(N, vector <int> (M));
    for (int i = 0; i < N; i++)
        for (int j = 0;  j < M; j++)
            cin >> S[i][j];
    queue <pair <int, int>> que;
    vector <int> big;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            if (vis[flat(i, j)]) continue;
            que.emplace(i, j); int x, y;
            vis[flat(i, j)] = true;
            comps(i, j).col = S[i][j] + 1;
            while (que.size()) {
                tie(x, y) = que.front(); que.pop();
                comps(i, j).cell.emplace_back(x, y);
                comps(x, y).idx = flat(i, j);
                for (int k = 0; k < 4; k++)
                    if (valid(x + dx[k], y + dy[k]) &&
                    !vis[flat(x + dx[k], y + dy[k])] &&
                    S[x + dx[k]][y + dy[k]] == S[i][j]) {
                        vis[flat(x + dx[k], y + dy[k])] = true;
                        que.emplace(x + dx[k], y + dy[k]);
                    }
            }
            if (comps(i, j).cell.size() >= MAXS)
                big.push_back(flat(i, j));
        }
    for (int u : big) {
        vector <int> neighbor; int x, y;
        for (auto pp : comps[u].cell) {
            tie(x, y) = pp;
            for (int k = 0; k < 4; k++)
                if (valid(x + dx[k], y + dy[k]) &&
                getCol(x + dx[k], y + dy[k]) != comps[u].col)
                    neighbor.push_back(comps(x + dx[k], y + dy[k]).idx);
        }
        comps[u].grp.resize(MAXC);
        for (int x : neighbor) {
            comps[u].grp[comps[x].col].push_back(x);
            comps[x].big.push_back(u);
        }
    }
    int Q; cin >> Q; int currrr = 0;
    while (Q--) {
        int x, y, col; cin >> x >> y >> col;
        x--; y--; col++;
        int u = comps(x, y).idx;
        if (col == comps[u].col) {
            print(); continue;
        }
        comps[u].col = col;
        vector <int> neighbor = get(comps[u], col);
        for (int v : neighbor) join(u, v);
        print();
    }
    // for (int i = 0; i < N; i++)
    //     for (int j = 0; j < M; j++)
    //         cout << getCol(i, j) - 1 << " \n"[j == M - 1];

}