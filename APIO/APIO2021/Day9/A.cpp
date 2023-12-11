#include <bits/stdc++.h>
 
using namespace std;
 
struct node {
    int nxt[26], link, leaf, len;

    node(): link(0), leaf(0) {
        memset(nxt, 0, sizeof nxt);
    }
};

const int MAXN = 1000005;

vector <node> T;
string S[MAXN]; bool mark[MAXN];
int BIT[MAXN], tin[MAXN];
int tout[MAXN], timer;
vector <int> adj[MAXN];

#define nxt(i, c) T[(i)].nxt[(c)]
#define link(i) T[(i)].link
#define leaf(i) T[(i)].leaf
#define len(i) T[(i)].len

void add(const string &s) {
    int u = 0;
    for (char c : s) {
        if (!nxt(u, c - 'a')) {
            nxt(u, c - 'a') = T.size();
            T.emplace_back();
            len(T.size() - 1) = len(u) + 1;
        }
        u = nxt(u, c - 'a');
    }
    leaf(u) = u;
}

void build() {
    queue <int> q; q.push(0);
    while (q.size()) {
        int u = q.front(); q.pop();
        if (!leaf(u))
            leaf(u) = leaf(link(u));
        if (u) adj[link(u)].push_back(u);
        for (int c = 0; c < 26; c++) {
            int v = nxt(u, c);
            if (v) {
                link(v) = u ? nxt(link(u), c) : 0;
                q.push(v);
            } else nxt(u, c) = nxt(link(u), c);
        }
    }
}

void DFS(int u) {
    tin[u] = ++timer;
    for (int v : adj[u]) DFS(v);
    tout[u] = timer;
}

void add(int i, int v) {
    for (; i < MAXN; i += i & -i)
        BIT[i] += v;
}

int sum(int i) {
    int res = 0;
    for (; i > 0; i -= i & -i)
        res += BIT[i];
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    T.emplace_back();
    for (int i = 1; i <= N; i++) {
        cin >> S[i]; add(S[i]);
    }
    build(); DFS(0); int res = 0;
    for (int i = 1; i <= N; i++) {
        int u = 0, lim = INT_MAX;
        vector <int> cur, pos;
        for (int j = 0; j + 1 < S[i].size(); j++) {
            u = nxt(u, S[i][j] - 'a');
            if (leaf(u)) {
                cur.push_back(leaf(u));
                pos.push_back(j);
            }
        }
        u = nxt(u, S[i].back() - 'a');
        if (leaf(link(u))) {
            cur.push_back(leaf(link(u)));
            pos.push_back(S[i].size() - 1);
        }
        for (int j = cur.size() - 1; j >= 0; j--)
            if (lim <= pos[j] - len(cur[j]))
                mark[cur[j]] = true;
            else lim = pos[j] - len(cur[j]);
        sort(cur.begin(), cur.end());
        cur.erase(unique(cur.begin(), cur.end()), cur.end());
        for (int v : cur) add(tin[v], 1);
        for (int v : cur)
            if (sum(tout[v]) - sum(tin[v] - 1) > 1)
                mark[v] = true;
        for (int v : cur) {
            if (!mark[v]) res++;
            mark[v] = false; add(tin[v], -1);
        }   
    }
    cout << res << '\n';
}
