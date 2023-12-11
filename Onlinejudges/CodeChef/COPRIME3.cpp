
// Problem : Coprime Triples
// Contest : CodeChef - Practice(Medium)
// URL : https://www.codechef.com/problems/COPRIME3
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e6 + 5;

int cnt[N], mu[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x; cnt[x]++;
    }
    mu[1] = 1; ll res = 0;
    for (int i = 1; i < N; i++) {
        for (int j = i * 2; j < N; j += i) {
            mu[j] -= mu[i];
            cnt[i] += cnt[j];
        }
        res += ll(cnt[i]) * (cnt[i] - 1)
        * (cnt[i] - 2) / 6 * mu[i];
    }
    cout << res << '\n';
}