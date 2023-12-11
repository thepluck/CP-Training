#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int rand(int l, int r) {
    return uniform_int_distribution<int> (l, r)(rng);
}

const int N = 1 << 20;

bool vis[N];

int main() {
    int n, k; cin >> n >> k;
    vector<int> res;
    while (clock() < 30 * CLOCKS_PER_SEC) {
        vector<int> cur(1, 0);
        int x = 0, y = 0;
        for (int i = 0; i < cur.size(); i++) {
            vis[cur[i]] = 1; bool flag = 0;
            vector<int> p, q;
            for (int j = 0; j < n; j++)
                if (cur[i] >> j & 1)
                    p.push_back(j);
                else q.push_back(j);
            shuffle(q.begin(), q.end(), rng);
            shuffle(p.begin(), p.end(), rng);
            if (rand(1, 100) == 100) swap(p, q);
            for (int j : p) {
                int z = y;
                if (cur[i] >> j & 1) z--;
                else z++;
                if (z > k || z < x ||
                vis[cur[i] ^ (1 << j)]) continue;
                cur.push_back(cur[i] ^ (1 << j));
                x = y; y = z; flag = 1; break;
            }
            if (flag) continue;
            for (int j : q) {
                int z = y;
                if (cur[i] >> j & 1) z--;
                else z++;
                if (z > k || z < x ||
                vis[cur[i] ^ (1 << j)]) continue;
                cur.push_back(cur[i] ^ (1 << j));
                x = y; y = z; flag = 1; break;
            }
        }
        for (int x : cur) vis[x] = 0;
        if (cur.size() > res.size()) res = cur;
    }
    cout << res.size() << '\n';
    for (int x : res) {
        for (int i = 0; i < n; i++) {
            cout << (x & 1); x >>= 1;
        }
        cout << '\n';
    }
}
