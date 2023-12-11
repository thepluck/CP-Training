#include <bits/stdc++.h>

using namespace std;

const int N = 400005;

int a[N];
vector<int> pos[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; a[i + n] = a[i];
        pos[a[i]].push_back(i);
    }
    for (int i = 1; i <= m; i++)
        if (pos[i].size())
            pos[i].push_back(pos[i].front() + n);
    for (int)
}