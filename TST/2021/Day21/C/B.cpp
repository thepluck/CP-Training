#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 2e5 + 5;

set <pair <ll, int>> tree[N];
ll tag[N]; int req[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    int last = 0, cnt = 0;
    for (int i = 0; i < m; i++) {
        int cmd; cin >> cmd;
        if (cmd == 1) {
            cin >> req[++cnt];
            for (int j = 0; j < req[cnt]; j++) {
                int city; cin >> city;
                tree[city].emplace(tag[])
            }
        }
    }
}