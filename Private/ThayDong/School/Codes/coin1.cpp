#include <bits/stdc++.h>

using namespace std;

const int pw[] = {1, 3, 9, 27, 81};

vector <array <int, 2>> one;
vector <array <int, 4>> two;

int bit(int state, int i) {
    return state / pw[i] % 3;
}

void gen(int a, int b, int i,
int state, vector <int> &states) {
    if (i == 5) {
        if (!a && !b)
            states.emplace_back(state);
        return;
    }
    if (a) {
        int _state = state;
        gen(a - 1, b, i + 1, _state, states);
    }
    if (b) {
        int _state = state + pw[i] * 2;
        gen(a, b - 1, i + 1, _state, states);
    }
    int _state = state + pw[i];
    gen(a, b, i + 1, _state, states);
}

int rec(int d, const vector <int> &states) {
    if (states.size() == 0) return 0;
    if (d == 4) return 4; bool same = 1;
    for (int i = 0; i < 5; i++) {
        if (bit(states[0], i) != 1) continue;
        for (int state : states)
            if (bit(state, i) != 1) same = 0;
    }
    if (same) return d; int res = 4;
    for (const auto &op : one) {
        vector <int> poss;
        for (int state : states)
            if (bit(state, op[0]) < bit(state, op[1]))
                poss.emplace_back(state);
        int cur = rec(d + 1, poss);
        if (cur >= res) continue;
        poss.clear();
        for (int state : states)
            if (bit(state, op[0]) == bit(state, op[1]))
                poss.emplace_back(state);
        cur = max(cur, rec(d + 1, poss));
        if (cur >= res) continue;
        poss.clear();
        for (int state : states)
            if (bit(state, op[0]) > bit(state, op[1]))
                poss.emplace_back(state);
        res = min(res, max(cur, rec(d + 1, poss)));
    }
    for (const auto &op : two) {
        vector <int> poss;
        for (int state : states)
            if (bit(state, op[0]) + bit(state, op[1])
            < bit(state, op[2]) + bit(state, op[3]))
                poss.emplace_back(state);
        int cur = rec(d + 1, poss);
        if (cur >= res) continue;
        poss.clear();
        for (int state : states)
            if (bit(state, op[0]) + bit(state, op[1])
            == bit(state, op[2]) + bit(state, op[3]))
                poss.emplace_back(state);
        cur = max(cur, rec(d + 1, poss));
        if (cur >= res) continue;
        poss.clear();
        for (int state : states)
            if (bit(state, op[0]) + bit(state, op[1])
            > bit(state, op[2]) + bit(state, op[3]))
                poss.emplace_back(state);
        res = min(res, max(cur, rec(d + 1, poss)));
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int a, b; cin >> a >> b;
    vector <int> states;
    gen(a, b, 0, 0, states);
    for (int i = 0; i < 4; i++)
        for (int j = i + 1; j < 5; j++)
            one.push_back({i, j});
    for (int i = 0; i < 2; i++)
        for (int j = i + 1; j < 3; j++)
            for (int k = j + 1; k < 4; k++)
                for (int l = k + 1; l < 5; l++) {
                    two.push_back({i, j, k, l});
                    two.push_back({i, k, j, l});
                    two.push_back({i, l, j, k});
                }
    cout << rec(0, states) << '\n';
}