#include <bits/stdc++.h>

using namespace std;

int pw[5], n;

bool used[5][5];

int bit(int state, int i) {
    return state / pw[i] % n;
}

int rec(int d, const vector <int> &states) {
    if (states.size() == 0) return 0;
    if (d == 7 || states.size() == 1) return d;
    int res = 7;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++) {
            vector <int> poss;
            if (used[i][j]) continue;
            used[i][j] = 1;
            for (int state : states)
                if (bit(state, i) < bit(state, j))
                    poss.emplace_back(state);
            int cur = rec(d + 1, poss);
            if (cur >= res) {
                used[i][j] = 0; continue;
            }
            poss.clear();
            for (int state : states)
                if (bit(state, i) > bit(state, j))
                    poss.emplace_back(state);
            cur = max(cur, rec(d + 1, poss));
            res = min(res, cur);
            used[i][j] = 0;
        }
    return res;
}

int main() {
    freopen("coin2.inp", "r", stdin);
    freopen("coin2.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n; pw[0] = 1;
    vector <int> states, perm;
    for (int i = 0; i < n; i++)
        perm.emplace_back(i);
    for (int i = 1; i < n; i++)
        pw[i] = pw[i - 1] * n;
    do {
        int state = 0;
        for (int i = 0; i < n; i++)
            state += pw[i] * perm[i];
        states.emplace_back(state);
    }
    while (next_permutation
    (perm.begin(), perm.end()));
    cout << rec(0, states) << '\n';
}