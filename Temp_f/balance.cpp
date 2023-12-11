#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300005;

long long pre[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    long long sum = 0;
    vector<pair<long long, int>> tmp(1, {0, 0});
    for (int i = 1, x; i <= N; i++) {
        cin >> x; tmp.emplace_back(sum += x, i);
    }
    sort(tmp.begin(), tmp.end());
    for (int i = 0; i <= N; ) {
        int j = i;
        while (j <= N && tmp[j].first == tmp[i].first) j++;
        for (int k = i + 1; k < j; k++) {
            pre[tmp[k - 1].second + 1] += 1ll * (k - i) * (j - k);
            pre[tmp[k].second + 1] -= 1ll * (k - i) * (j - k);
        }
        i = j;
    }
    for (int i = 1; i <= N; i++)
        cout << (pre[i] += pre[i - 1]) << ' ';
}