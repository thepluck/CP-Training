#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

bitset <N> bit1[26], bit2;
string s, t;

/// run in O(|s| * |t| / 64), quite fast
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> s >> t;
    for (int i = 0; i < s.size(); i++)
        bit1[s[i] - 'a'][i] = 1;
    vector <int> pos; bit2.set();
    for (int i = 0; i < t.size(); i++)
        bit2 &= bit1[t[i] - 'a'] >> i;
    for (int i = bit1._Find_first;
    i < N; i = bit1._Find_next(i))
        pos.push_back(i);
}
