#include <bits/stdc++.h>
using namespace std;

struct node {
    int nxt[26];

    node() {
        memset(nxt, 0, sizeof nxt);
    }
};

vector <node> tr;

void insert(const string &s) {
    int pt = 0;
    for (char c : s) {
        int t = c - 'a';
        if (!tr[pt].nxt[t]) {
            tr[pt].nxt[t] = tr.size();
            tr.emplace_back();
        }
        pt = tr[pt].nxt[t];
    }
}

int main() {
    freopen("printer.inp", "r", stdin);
    freopen("printer.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n, mx = 0; cin >> n;
    string s; int res = n;
    tr.emplace_back();
    for (int i = 0; i < n; i++) {
        cin >> s; insert(s);
        mx = max(mx, int(s.size()));
    }
    res += 2 * (tr.size() - 1);
    res -= mx; cout << res << '\n';
}