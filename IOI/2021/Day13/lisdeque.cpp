#include <bits/stdc++.h>

using namespace std;

using ii = pair <int, int>;

const int MAXN = 200005;

vector <int> A[MAXN], S[MAXN], B;
int F[MAXN], G[MAXN], L[MAXN], R[MAXN];;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    priority_queue <ii, vector <ii>, greater <ii>> pq;
    for (int i = 0; i < N; i++) {
        int K; cin >> K;
        A[i].resize(K); S[i].resize(K);
        vector <int> lis;
        for (int j = 0; j < K; j++) {
            cin >> A[i][j];
            auto it = lower_bound(lis.begin(), lis.end(), A[i][j]);
            F[j] = it - lis.begin();
            if (it != lis.end()) *it = A[i][j];
            else lis.push_back(A[i][j]);
        }
        lis.clear();
        for (int j = K - 1; j >= 0; j--) {
            auto it = lower_bound(lis.begin(), lis.end(), A[i][j]);
            G[j] = it - lis.begin();
            if (it != lis.end()) *it = A[i][j];
            else lis.push_back(A[i][j]);
        }
        int p = 0;
        for (int j = 1; j < K; j++)
            if (F[p] + G[p] < F[j] + G[j]) p = j;
        S[i][L[i] = R[i] = p] = true;
        for (int j = p - 1; j >= 0; j--)
            if (F[j] + 1 == F[L[i]] && A[i][j] < A[i][L[i]])
                S[i][L[i] = j] = true;
        for (int j = p + 1; j < K; j++) {
            if (G[j] + 1 == G[R[i]] && A[i][j] < A[i][R[i]])
                S[i][R[i] = j] = true;
        }
        for (int j = 0; j < L[i]; j++)
            B.push_back(A[i][j]);
        for (int j = K - 1; j > R[i]; j--)
            B.push_back(A[i][j]);
        pq.emplace(min(A[i][L[i]], A[i][R[i]]), i);
    }
    int res = 0;
    while (pq.size()) {
        int v, i; res++;
        tie(v, i) = pq.top(); pq.pop();
        B.push_back(v);
        if (v == A[i][L[i]]) {
            while (++L[i] <= R[i] && !S[i][L[i]])
                B.push_back(A[i][L[i]]);
        } else {
            while (--R[i] >= L[i] && !S[i][R[i]])
                B.push_back(A[i][R[i]]);
        }
        if (L[i] <= R[i])
            pq.emplace(min(A[i][L[i]], A[i][R[i]]), i);
    }
    cout << res << '\n';
    for (int x : B) cout << x << ' ';
}