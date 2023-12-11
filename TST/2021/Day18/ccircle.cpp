#include <bits/stdc++.h>

using namespace std;

void normalize(string &s, vector <int> &oper) {
    int n = s.size();
    while (true) {
        vector <int> pos;
        for (int i = 0; i < n; i++)
            if (s[i] == '1') pos.push_back(i);
        int m = pos.size();
        if (pos.size() == 1) break;
        bool found = false;
        for (int i = 0; i < m; i++) {
            int dis = pos[(i + 1) % m] - pos[i];
            if (pos[i] > pos[(i + 1) % m])
                dis = n - dis;
            if (dis & 1) {
                found = true;
                int st = pos[i];
                int en = pos[(i + 1) % m];
                s[st] = s[en] = '0';
                for (int j = (st + 1) % n; j != en; j = (j + 2) % n)
                    oper.push_back(j);
                for (int j = st; ; j = (j + 2) % n) {
                    oper.push_back(j);
                    if ((j + 1) % n == en) break;
                }
                break;
            }
        }
        if (!found) break;
    }
    if (count(s.begin(), s.end(), '1') == 1 && (n & 1)) {
        int i = find(s.begin(), s.end(), '1') - s.begin();
        if (!(n - i & 1)) {
            int cnt = (n - i) / 2;
            while (cnt--) {
                s[i] = s[i + 1] = '0';
                s[(i + 2) % n] = '1';
                oper.push_back(i + 1);
                oper.push_back(i);
                i = (i + 2) % n;
            }
        }        
    }
    for (int i = n - 1; i >= 0; i--)
        if (s[i] == '1') {
            int j = i, cnt = (n - 1 - i) / 2;
            while (cnt--) {
                if (s.substr(j, 3) == "100") {
                    s[j] = s[j + 1] = '0';
                    s[j + 2] = '1';
                    oper.push_back(j + 1);
                    oper.push_back(j);
                    j = (j + 2) % n;
                }
            }
        }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s, t; cin >> s >> t;
    vector <int> oper[2];
    normalize(s, oper[0]);
    normalize(t, oper[1]);
    reverse(oper[1].begin(), oper[1].end());
    cout << oper[0].size() + oper[1].size() << '\n';
    for (int i : oper[0]) cout << i << '\n';
    for (int i : oper[1]) cout << i << '\n';
}