#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

map <string, int> mp;
vector <int> pos[2]; int q;

void rev(char &c) {
    c = c == 'Y' ? 'N' : 'Y';
}

int ask(string s, int k) {
    if (q == 0) {
        cout << "DONE" << endl;
        exit(0);
    }
    for (int i = 0; i < k; i++)
        rev(s[pos[0][i]]);
    cout << s << endl;
    string a; cin >> q >> a;
    return mp[a];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    mp["FAIL"] = 0;
    mp["PASS"] = 1;
    mp["GREAT"] = 2;
    mp["PERFECT"] = 3;
    int m, a, b, n; cin >> q;
    while (true) {
        cin >> m >> a >> b >> n;
        string s; cin >> s; string t = s;
        pos[0].clear(); pos[1].clear();
        for (int i = 0; i < n; i++)
            if (s[i] == 'Y' || s[i] == 'N') {
                pos[0].push_back(i); rev(s[i]);
            } else pos[1].push_back(i);
        bool flag = false;
        int border, num = 0;
        while (true) {
            for (int i : pos[1])
                s[i] = (rng() & 1) ? 'Y' : 'N';
            int zero = ask(s, 0), all = ask(s, m);
            if (all == 3) {
                flag = true; break;
            }
            if (zero == all) continue;
            while (num < m && ask(s, num + 1) == zero)
                num++;
            border = zero; break;
        }
        if (flag) continue;
        for (int i : pos[1]) {
            rev(s[i]);
            int tmp = ask(s, num);
            if (tmp == 3) {
                flag = true; break;
            }
            rev(s[i]); t[i] = s[i];
            if (tmp == border + 1) rev(t[i]);
        }
        if (flag) continue;
        ask(t, 0); continue;
    }
}