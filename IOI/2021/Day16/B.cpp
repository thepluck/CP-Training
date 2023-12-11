#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

vector<int> P[26];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string S, T; cin >> S;
    for (int i = 0; i < S.size(); i++)
        P[S[i] - 'a'].push_back(i);
    int Q; cin >> Q;
    vector<int>::iterator it;
    long long res = 1;
    while (Q--) {
        cin >> T; int cur = 1;
        for (int i = 0, j = -1; i < T.size(); i++) {
            if (P[T[i] - 'a'].empty()) {
                cur = MOD - 1; break;
            }
            it = upper_bound(P[T[i] - 'a'].begin(), P[T[i] - 'a'].end(), j);
            if (it == P[T[i] - 'a'].end()) {
                cur++; it = P[T[i] - 'a'].begin();
            }
            j = *it;
        }
        res = res * cur % MOD;
    }
    cout << res << '\n';
}