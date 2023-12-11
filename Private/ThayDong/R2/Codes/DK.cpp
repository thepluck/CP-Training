#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int occ[2005], cur[2005], tmp[2005];

int main() {
    freopen("DK.inp", "r", stdin);
    freopen("DK.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n, maxDif = 0; cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        occ[x]++; tmp[x]++;
        maxDif = max(maxDif, x);
    }
    vector <int> curAns, curCnt;
    vector <int> finalAns(n + 2);
    curAns.push_back(0);
    for (int st = 0; st < 100; st++) {
        int leftCnt = n;
        for (int i = 1; i < curAns.size(); i++)
            for (int j = 0; j < i; j++)
                if (occ[abs(curAns[i] - curAns[j])]) {
                    occ[abs(curAns[i] - curAns[j])]--;
                    leftCnt--;
                }
        while (leftCnt) {
            int bestCnt = -1, bestX = 0;
            for (int x = 0; x <= maxDif * 2; x++) {
                int cnt = 0;
                memset(cur, 0, sizeof cur);
                for (int y : curAns) cur[abs(x - y)]++;
                for (int i = 0; i <= maxDif; i++)
                    cnt += min(occ[i], cur[i]);
                if (cnt > bestCnt) {
                    bestCnt = cnt; bestX = x;
                } else if (cnt == bestCnt) {
                    if (rng() & 1) bestX = x;
                }
            }
            for (int y : curAns)
                if (occ[abs(bestX - y)]) {
                    occ[abs(bestX - y)]--; leftCnt--;
                }
            curAns.push_back(bestX);
        }
        if (curAns.size() < finalAns.size())
            finalAns = curAns;
        memcpy(occ, tmp, sizeof occ);
        vector <pair <int, int>> sorted;
        for (int i = 0; i < curAns.size(); i++) {
            memset(cur, 0, sizeof cur);
            for (int j = 0; j < curAns.size(); j++)
                if (i != j)
                    cur[abs(curAns[i] - curAns[j])]++;
            int cnt = 0;
            for (int x = 0; x <= maxDif; x++)
                cnt += min(occ[x], cur[x]);
            sorted.emplace_back(cnt, curAns[i]);
        }
        sort(sorted.begin(), sorted.end(),
        greater <pair <int, int>> ());
        sorted.erase(unique(sorted.begin(),
        sorted.end()), sorted.end());
        curAns.clear();
        for (int i = 0; i < sorted.size() && i < 5; i++)
            curAns.push_back(sorted[i].second);
    }
    cout << finalAns.size() << '\n';
    for (int x : finalAns) cout << x << ' ';
}
