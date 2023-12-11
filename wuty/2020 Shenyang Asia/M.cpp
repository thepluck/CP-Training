#include <bits/stdc++.h>


using namespace std;

using ll = long long;

vector<ll> FWHT(vector<ll> poly, bool inv) {
    for (int len = 1; len * 2 <= poly.size(); len *= 2)
        for (int i = 0; i < poly.size(); i += len * 2)
            for (int j = 0; j < len; j++) {
                ll u = poly[i + j];
                ll v = poly[i + j + len];
                poly[i + j] = u + v;
                poly[i + j + len] = u - v;
            }
    if (inv) {
        for (int i = 0; i < poly.size(); i++)
            poly[i] /= poly.size();
    }
    return poly;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M; ll K; cin >> N >> M >> K;
    vector<ll> cnt(1 << M);
    for (int i = 0; i < N; i++) {
        string S; cin >> S;
        int mask = 0;
        for (int j = 0; j < M; j++)
            if (S[j] == 'B') mask += 1 << j;
        cnt[mask]++;
    }
    cnt = FWHT(cnt, 0);
    for (int i = 0; i < (1 << M); i++)
        cnt[i] = cnt[i] * cnt[i];
    cnt = FWHT(cnt, 1);
    for (int i = 1; i < (1 << M); i++)
        cnt[i] /= 2;
    for (int j = 0; j < M; j++)
        for (int i = 0; i < (1 << M); i++)
            if (i >> j & 1)
                cnt[i - (1 << j)] += cnt[i];
    cnt[0] = 0;
    for (int i = 0; i < (1 << M); i++)
        if (!(__builtin_popcount(i) & 1))
            cnt[i] = -cnt[i];
    for (int j = 0; j < M; j++)
        for (int i = 0; i < (1 << M); i++)
            if (i >> j & 1)
                cnt[i] += cnt[i - (1 << j)];
    int res = 0;
    for (int i = 0; i < (1 << M); i++)
        if (cnt[i] >= K) res++;
    cout << res;
}
