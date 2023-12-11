#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock
::now().time_since_epoch().count());

int n, reqA, A[105], D[105][105];
bool used[105]; int minD = INT_MAX;
vector <int> minP, curP;

void DFS(int i, int curA, int curD) {
    if (curD > minD) return;
    if (clock() > 10 * CLOCKS_PER_SEC) return;
    if (curA >= reqA) {
        if (curD + D[i][0] < minD) {
            minD = curD + D[i][0]; minP = curP;
        }
        return;
    }
    vector <int> can;
    for (int j = 1; j <= n; j++)
        if (!used[j]) can.push_back(j);
    shuffle(can.begin(), can.end(), rng);
    for (int j : can) {
        curP.push_back(j); used[j] = true;
        DFS(j, curA + A[j], curD + D[i][j]);
        curP.pop_back(); used[j] = false;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    // int n, reqA;
    // cin >> n >> reqA;
    // vector <pair <int, int>> A(n);
    // for (int i = 0; i < n; i++) {
    //     cin >> A[i].first;
    //     A[i].second = i + 1;
    // }
    // vector <vector <int>> D(n + 1, vector <int> (n + 1));
    // for (int i = 0; i <= n; i++)
    //     for (int j = 0; j <= n; j++)
    //         cin >> D[i][j];
    // int minDist = INT_MAX; vector <int> ans;
    // while (clock() < 20 * CLOCKS_PER_SEC) {
    //     shuffle(A.begin(), A.end(), rng);
    //     int localMin = INT_MAX, lef, rig;
    //     int curA = 0, curDist = 0;
    //     for (int i = 0, j = 0; i < n; i++) {
    //         while (j < n && curA < reqA) {
    //             curA += A[j].first;
    //             if (j > i) curDist +=
    //             D[A[j - 1].second][A[j].second];
    //             j++;
    //         }
    //         if (curA < reqA) break;
    //         if (localMin > curDist +
    //         D[0][A[i].second] +
    //         D[A[j - 1].second][0]) {
    //             localMin = curDist +
    //             D[0][A[i].second] +
    //             D[A[j - 1].second][0];
    //             lef = i; rig = j;
    //         }
    //         if (i + 1 < j) curDist -=
    //         D[A[i].second][A[i + 1].second];
    //         curA -= A[i].first;
    //     }
    //     if (localMin < minDist) {
    //         minDist = localMin; ans.clear();
    //         for (int i = lef; i < rig; i++)
    //             ans.push_back(A[i].second);
    //     }
    // }
    // if (minDist == INT_MAX) return cout << -1, 0;
    // cout << minDist << '\n' << ans.size() << '\n';
    // for (int pos : ans) cout << pos << ' ';
    cin >> n >> reqA;
    for (int i = 1; i <= n; i++) cin >> A[i];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            cin >> D[i][j];
    DFS(0, 0, 0);
    cout << minD << ' ' << minP.size() << '\n';
    for (int pos : minP) cout << pos << ' ';
}