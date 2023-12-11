#include <bits/stdc++.h>

using namespace std;

const int N = 300005;

vector <int> adj[N];
int cnt[N], sum[N], lef[N], rig[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, p; cin >> n >> p;
    for (int i = 1; i <= n; i++) {
        cin >> lef[i] >> rig[i];
        adj[lef[i]].push_back(i);
        adj[rig[i]].push_back(i);
        cnt[lef[i]]++; cnt[rig[i]]++;
    }
    for (int i = 1; i <= n; i++)
        sum[cnt[i]]++;
    for (int i = n - 1; i >= 0; i--)
        sum[i] += sum[i + 1];
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        int cur = sum[max(0, p - cnt[i])];
        for (int j : adj[i]) {
            if (lef[j] == i)
                if (cnt[rig[j]]-- ==
                p - cnt[i]) cur--;
            if (rig[j] == i)
                if (cnt[lef[j]]-- ==
                p - cnt[i]) cur--;
        }
        res += cur - (cnt[i] * 2 >= p);
        for (int j : adj[i]) {
            if (lef[j] == i)
                cnt[rig[j]]++;
            if (rig[j] == i)
                cnt[lef[j]]++;
        }
    }
    cout << res / 2 << '\n';
}