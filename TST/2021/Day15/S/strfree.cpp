#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

bitset <N> bit1[26], bit2;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s, t; int q, k;
    cin >> s >> q;
    for (int i = 0; i < s.size(); i++)
        bit1[s[i] - 'a'][i] = true;
    while (q--) {
        cin >> k >> t; bit2.set();
        for (int i = 0; i < t.size(); i++)
            bit2 &= bit1[t[i] - 'a'] >> i;
        vector <int> pos;
        for (int i = bit2._Find_first();
        i < N; i = bit2._Find_next(i))
            pos.push_back(i);
        if (pos.size() < k) {
            cout << "-1\n"; continue;
        }
        int res = s.size();
        for (int i = 0; i + k <= pos.size(); i++)
            res = min(res, pos[i + k - 1] - pos[i]);
        cout << res + t.size() << '\n';
    }
}