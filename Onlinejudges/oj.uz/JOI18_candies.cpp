#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

int L[MAXN], R[MAXN];
long long V[MAXN];

struct comp {
    bool operator () (int x, int y) const {
        return V[x] > V[y] ||
        (V[x] == V[y] && x > y);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    set<int, comp> S;
    for (int i = 1; i <= N; i++) {
        cin >> V[i];
        S.insert(L[i] = R[i] = i);
    }
    long long res = 0;
    while (S.size()) {
        auto it = S.begin();
        S.erase(it);
        int l = *it, r = R[*it];
        res += V[l];
        if (l == 1) S.erase(r + 1);
        else if (r == N)
            S.erase(L[l - 1]);
        else {
            S.erase(r + 1);
            V[l] -= V[r + 1];
            r = R[r + 1];
            S.erase(L[l - 1]);
            V[L[l - 1]] -= V[l];
            l = L[l - 1];
            L[r] = l; R[l] = r;
            S.insert(l);
        }
        cout << res << '\n';
        for (int x : S) cerr << x << ' ';
        cerr << '\n';
    }
}