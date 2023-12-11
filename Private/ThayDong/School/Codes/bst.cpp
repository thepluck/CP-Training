#include <bits/stdc++.h>
using namespace std;

vector <int> ans; bool ok = 1;

void rec(int l, int r, int h) {
    if (l > r || h < 0) return;
    int root = max(l,
    r - (1 << h - 1) + 1);
    if (root * 2 > l + r) ok = 0;
    ans.push_back(root);
    rec(l, root - 1, h - 1);
    rec(root + 1, r, h - 1);
}

int main() {
    //freopen("bst.inp", "r", stdin);
    //freopen("bst.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n, h; cin >> n >> h;
    rec(1, n, h);
    if (!ok) cout << "-1\n";
    else {
        for (int x : ans)
            cout << x << ' ';
    }
}