#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

pair <int, int> a[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i].second >> a[i].first;
    sort(a + 1, a + n + 1);
    long long lo = 0, hi = 1e15;
    while (lo < hi) {
        long long mi = (lo + hi) / 2;
        priority_queue <int> pq;
        long long curt = 0; int miss = 0;
        for (int i = 1; i <= n; i++) {
            curt += a[i].second;
            pq.emplace(a[i].second);
            if (curt > mi * a[i].first) {
                curt -= pq.top();
                pq.pop(); miss++;
            }
        }
        if (miss <= m) hi = mi;
        else lo = mi + 1;
    }
    cout << hi << '\n';
}