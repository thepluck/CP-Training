#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};

int Ele[N][N], Eup[N][N];
char str[N][N]; int cmpCnt;
int sum[N][N], id[N][N];
int lef[N * N], rig[N * N];
int up[N * N], down[N * N];
queue <pair <int, int>> que;
vector <pair <int, int>> adj[N][N];

void addEdge(int x, int y, int u, int v) {
    adj[x][y].emplace_back(u, v);
    adj[u][v].emplace_back(x, y);
}

bool isAlone(int i, int j) {
    return str[i][j] == str[i + 1][j]
    && str[i][j] == str[i][j + 1] &&
    str[i][j] == str[i + 1][j + 1];
}

void BFS(int i, int j) {
    que.emplace(i, j);
    id[i][j] = ++cmpCnt;
    while (que.size()) {
        tie(i, j) = que.front(); que.pop();
        lef[cmpCnt] = min(lef[cmpCnt], j);
        rig[cmpCnt] = max(rig[cmpCnt], j);
        up[cmpCnt] = min(up[cmpCnt], i);
        down[cmpCnt] = max(down[cmpCnt], i);
        for (auto pp : adj[i][j]) {
            int x, y; tie(x, y) = pp;
            if (!id[x][y]) {
                id[x][y] = cmpCnt;
                que.emplace(x, y);
            }
        }
    }
}

int getRec(int x1, int y1, int x2, int y2) {
    return sum[x2][y2] - sum[x2][y1]
    - sum[x1][y2] + sum[x1][y1];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, q; cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        cin >> (str[i] + 1);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (str[i][j] != str[i + 1][j])
                addEdge(i, j, i, j - 1);
            if (str[i][j] != str[i][j + 1])
                addEdge(i, j, i - 1, j);
            if (str[i][j] != str[i - 1][j])
                addEdge(i - 1, j, i - 1, j - 1);
            if (str[i][j] != str[i][j - 1])
                addEdge(i, j - 1, i - 1, j - 1);
        }
    memset(lef, 0x3f, sizeof lef);
    memset(up, 0x3f, sizeof up);
    memset(rig, -1, sizeof rig);
    memset(down, -1, sizeof down);
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            if (!id[i][j]) BFS(i, j);
    for (int i = 1; i <= cmpCnt; i++)
        sum[down[i]][rig[i]]++;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            sum[i][j] += sum[i - 1][j] +
            sum[i][j - 1] - sum[i - 1][j - 1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            Ele[i][j] = Ele[i][j - 1] +
            (str[i][j] != str[i + 1][j]);
            Eup[i][j] = Eup[i - 1][j] +
            (str[i][j] != str[i][j + 1]);
        }
    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int cntV = (x2 - x1 + 2) * (y2 - y1 + 2);
        int cntE = (x2 - x1 + y2 - y1 + 2) * 2;
        for (int i = y1; i < y2; i++)
            cntE += Eup[x2][i] - Eup[x1 - 1][i];
        for (int i = x1; i < x2; i++)
            cntE += Ele[i][y2] - Ele[i][y1 - 1];
        
        x1--; y1--;
        int cmp = getRec(x2 - 1, y2 - 1, x1, y1);
        vector <int> tmp;
        for (int i = x1; i < x2; i++) {
            int pp = id[i][y1];
            if (down[pp] < x2 && rig[pp] < y2
            && down[pp] > x1 && rig[pp] > y1
            && (up[pp] <= x1 || lef[pp] <= y1))
                tmp.push_back(pp);
        }
        for (int i = y1; i < y2; i++) {
            int pp = id[x1][i];
            if (down[pp] < x2 && rig[pp] < y2
            && down[pp] > x1 && rig[pp] > y1
            && (up[pp] <= x1 || lef[pp] <= y1))
                tmp.push_back(pp);
        }
        sort(tmp.begin(), tmp.end());
        tmp.erase(unique(tmp.begin(),
        tmp.end()), tmp.end());
        cmp -= tmp.size();
        cout << (cmp + 1 - cntV + cntE) << '\n';
        
    }

}