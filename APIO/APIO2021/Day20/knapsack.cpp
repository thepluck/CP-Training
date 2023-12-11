#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

void accept() {
    cout << "accept" << endl;
}

void decline() {
    cout << "decline" << endl;
}

void stop() {
    cout << "stop" << endl; exit(0);
}

const int MAXN = 505;
const int MAXM = 60005;

int DP[MAXN][MAXM];

int main() {
    int subtask, N, M;
    cin >> subtask >> N >> M;
    int W, V; cin >> W >> V;
    accept();
    while (W > 0) {
        int w, v;
        cin >> w >> v;
        if (w < W) {
            W = w; V = v;
            accept();
        } else decline();
    }
    vector <pair <int, int>> A(N);
    multiset <pair <int, int>> S;
    for (int i = 0; i < N; i++)
        while (true) {
            int w, v;
            cin >> w >> v;
            if (w > W) {
                A[i] = {w - W, v - V};
                W = w; V = v;
                accept(); break;
            } else decline();
        }
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= M; j++) {
            DP[i + 1][j] = DP[i][j];
            if (j >= A[i].first)
                DP[i + 1][j] = max(DP[i + 1][j],
                DP[i][j - A[i].fi] + A[i].se);
        }
    int bestM = 0;
    for (int j = 1; j <= M; j++)
        if (DP[N][j] >= DP[N][bestM])
            bestM = j;
    for (int i = N - 1; i >= 0; i--) {
        if (DP[i + 1][bestM] == DP[i][bestM])
            S.insert(A[i]);
        else bestM -= A[i].first;
    }
    if (S.empty()) {
        while (true) {
            int w, v; cin >> w >> v;
            if (W > w && V > v) {
                accept(); break;
            } else decline();
        }
        while (true) {
            int w, v; cin >> w >> v;
            if (W == w && V == v) stop();
            else decline();
        }
    }
    while (true) {
        int w, v; cin >> w >> v;
        if (S.count({W - w, V - v})) {
            S.erase(S.find({W - w, V - v}));
            W = w; V = v;
            if (S.empty()) stop();
            else accept();
        } else decline();
    }
}