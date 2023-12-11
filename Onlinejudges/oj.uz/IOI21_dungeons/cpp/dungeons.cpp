#include <bits/stdc++.h>

using namespace std;

namespace {
    template <class X, class Y>
    bool cmin(X &a, const Y &b) {
        return a > b ? a = b, 1 : 0;
    }

    const int MAXN = 400005;
    const long long INF = 1e9;

    struct path {
        int dest;
        long long mini, suma;
    };

    long long str[MAXN], bns[MAXN];
    int win[MAXN], lose[MAXN], N;
    path jump[MAXN][3][19];
    long long tail[MAXN];
}

void init(int n, vector<int> s, vector<int> p,
vector<int> w, vector<int> l) {
    copy(s.begin(), s.end(), str);
    copy(p.begin(), p.end(), bns);
    copy(w.begin(), w.end(), win);
    copy(l.begin(), l.end(), lose);
    str[N = n] = bns[n] = INF;
    win[N] = lose[N] = N;
    for (int i = N - 1; i >= 0; i--)
        tail[i] = tail[win[i]] + str[i];
    for (int a = 0; a < 3; a++) {
        int lo = 1 << (a << 3);
        int hi = 1 << ((a + 1) << 3);
        for (int i = 0; i <= N; i++)
            if ((lo <= str[i] && str[i] < hi) || i == N)
                jump[i][a][0] = {lose[i], str[i], bns[i]};
            else if (str[i] < lo)
                jump[i][a][0] = {win[i], INF, str[i]};
            else jump[i][a][0] = {lose[i], INF, bns[i]};
        for (int b = 1; b < 19; b++)
            for (int i = 0; i <= N; i++) {
                path &cur = jump[i][a][b];
                cur.dest = i;
                cur.mini = INF; cur.suma = 0;
                for (int j = 0; j < 2; j++) {
                    path nxt = jump[cur.dest][a][b - 1];
                    cmin(cur.mini, nxt.mini - cur.suma);
                    cur.suma += nxt.suma;
                    cur.dest = nxt.dest;
                }
            }
    }
}

long long simulate(int x, int z) {
    path cur = {x, 0, z};
    for (int a = 0; a < 3; a++) {
        int lo = 1 << (a << 3);
        int hi = 1 << ((a + 1) << 3);
        while (cur.dest < N && lo <= cur.suma && cur.suma < hi) {
            for (int b = 18; b >= 0; b--)
                while (cur.suma < jump[cur.dest][a][b].mini &&
                cur.suma + jump[cur.dest][a][b].suma < hi) {
                    cur.suma += jump[cur.dest][a][b].suma;
                    cur.dest = jump[cur.dest][a][b].dest;
                }
            if (cur.dest < N) {
                if (cur.suma < str[cur.dest]) {
                    cur.suma += bns[cur.dest];
                    cur.dest = lose[cur.dest];
                } else {
                    cur.suma += str[cur.dest];
                    cur.dest = win[cur.dest];
                }
            }
        }
    }
    return cur.suma + tail[cur.dest];
}

