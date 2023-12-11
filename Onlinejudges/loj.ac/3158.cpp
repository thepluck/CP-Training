#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

int A[MAXN], B[MAXN];
bool useA[MAXN], useB[MAXN];

struct cmpA {
    bool operator () (int i, int j) {
        return A[i] < A[j];
    }
};

struct cmpB {
    bool operator () (int i, int j) {
        return B[i] < B[j];
    }
};

struct cmpAB {
    bool operator () (int i, int j) {
        return A[i] + B[i] < A[j] + B[j];
    }
};

void solve() {
    int N, K, L, cnt = 0;
    cin >> N >> K >> L;
    for (int i = 0; i < N; i++) {
        cin >> A[i]; useA[i] = 0;
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i]; useB[i] = 0;
    }
    long long res = 0;
    priority_queue <int, vector <int>, cmpA> pqA[2];
    priority_queue <int, vector <int>, cmpB> pqB[2];
    priority_queue <int, vector <int>, cmpAB> pqAB;
    auto add = [&](int i, int j) {
        useA[i] = useB[j] = true;
        res += A[i] + B[j];
        if (i == j) return;
        if (useB[i] && useA[j]) cnt--;
        if (!useB[i] && !useA[j]) cnt++;
        if (!useA[j]) pqA[1].push(j);
        if (!useB[i]) pqB[1].push(i);
    };
    for (int i = 0; i < N; i++) {
        pqA[0].push(i); pqB[0].push(i);
        pqAB.push(i);
    }
    for (int st = 0; st < K; st++) {
        while (useA[pqA[0].top()]) pqA[0].pop();
        while (useB[pqB[0].top()]) pqB[0].pop();
        if (cnt < K - L) {
            add(pqA[0].top(), pqB[0].top());
            continue;
        }
        while (pqAB.size()) {
            int i = pqAB.top();
            if (useA[i] || useB[i]) pqAB.pop();
            else break;
        }
        int s0 = INT_MIN;
        if (pqAB.size()) {
            int i = pqAB.top(); s0 = A[i] + B[i];
        }
        while (pqA[1].size()) {
            int i = pqA[1].top();
            if (useA[i] || !useB[i]) pqA[1].pop();
            else break;
        }
        int s1 = INT_MIN;
        if (pqA[1].size()) {
            int i = pqA[1].top(), j = pqB[0].top();
            s1 = A[i] + B[j];
        }
        while (pqB[1].size()) {
            int j = pqB[1].top();
            if (useB[j] || !useA[j]) pqB[1].pop();
            else break;
        }
        int s2 = INT_MIN;
        if (pqB[1].size()) {
            int i = pqA[0].top(), j = pqB[1].top();
            s2 = A[i] + B[j];
        }
        if (s0 == max({s0, s1, s2})) {
            int i = pqAB.top(); add(i, i);
        }
        else if (s1 == max({s0, s1, s2})) {
            int i = pqA[1].top(), j = pqB[0].top();
            add(i, j);
        }
        else {
            int i = pqA[0].top(), j = pqB[1].top();
            add(i, j);
        }
    }
    cout << res << '\n';
}

int main() {
    freopen("sequence.in", "r", stdin);
    freopen("sequence.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}