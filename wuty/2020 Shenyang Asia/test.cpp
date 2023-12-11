#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    const int n = 24;

    int bestScore = 0;
    vector<int> patterns;

    for(int mask = 0; mask < (1 << n); ++mask) {
        int score = 0;
        for(int i = 0; i < n; ++i) {
            int odd = 0;
            for(int j = i; j < n; ++j) {
                odd ^= (mask >> j) & 1;
                score += odd;
            }
        }

        if (score < bestScore) continue;
        if (score > bestScore) {
            patterns.clear();
        }
        patterns.push_back(mask);
        bestScore = score;
    }

    cout << bestScore << endl;
    cout << patterns.size() << endl;

    for(int i = 0; i < 100; ++i) cout << bitset<n>(patterns[i]) << endl;


    return 0;
}