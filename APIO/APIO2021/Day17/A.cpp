#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

using ii = pair <int, int>;

const int LOG = 16;
const int MAXN = 10005;

vector <int> take[LOG];
int A[MAXN], B[MAXN], P[MAXN];

void solve(vector <int> V, int k, bool d) {
    vector <int> X[2];
    for (auto p : V)
        X[(p >> k) & 1].push_back(p);
    if (k > 0) {
        solve(X[d], k - 1, d ^ 1);
        solve(X[d ^ 1], k - 1, d);
    }
    for (auto p : X[d])
        take[k].push_back(B[p]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++) {
        cin >> B[i]; P[B[i]] = i;
    }
    int k = 0;
    while ((1 << k) < N - 1) k++;
    vector <int> V;
    for (int i = 0; i < N; i++)
        V.push_back(P[A[i]]);
    solve(V, k, 0); int res = 0;
    for (int i = 0; i <= k; i++)
        res += !take[i].empty();
    cout << res << '\n';
    for (int i = 0; i <= k; i++)
        if (take[i].size()) {
            cout << take[i].size();
            for (int x : take[i])
                cout << ' ' << x;
            cout << '\n';
        }
}