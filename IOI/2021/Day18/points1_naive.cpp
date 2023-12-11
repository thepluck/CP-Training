#include <bits/stdc++.h>

using namespace std;


struct point {
    int x, y;

    bool operator < (const point &o) const {
        return x < o.x;
    }
};

const int MAXN = 700005;

point P[MAXN];
int minL[MAXN], maxL[MAXN];
int minR[MAXN], maxR[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> P[i].x >> P[i].y;
    sort(P + 1, P + N + 1);
    minL[0] = minR[N + 1] = INT_MAX;
    maxL[0] = maxR[N + 1] = INT_MIN;
    for (int i = 1; i <= N; i++) {
        minL[i] = min(minL[i - 1], P[i].y);
        maxL[i] = max(maxL[i - 1], P[i].y);
    }
    for (int i = N; i > 0; i--) {
        minR[i] = min(minR[i + 1], P[i].y);
        maxR[i] = max(maxR[i + 1], P[i].y);
    }
    int res = INT_MAX;
    for (int l = 1; l <= N; l++)
        for (int r = l; r <= N; r++)
            res = min(res, P[r].x - P[l].x + max(maxL[l - 1],
            maxR[r + 1]) - min(minL[l - 1], minR[r + 1])),
            cerr << l << ' ' << r << ' ' << P[r].x - P[l].x + max(maxL[l - 1],
            maxR[r + 1]) - min(minL[l - 1], minR[r + 1]) << '\n';
    cout << res << '\n';
}