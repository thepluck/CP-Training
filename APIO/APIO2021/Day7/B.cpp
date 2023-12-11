#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmax(X &a, const Y &b) {
    return a < b ? a = b, 1 : 0;
}

const int MAXN = 500005;

int H[MAXN], P[MAXN], A[MAXN], B[MAXN];

#define sqr(x) (x) * (x)

int pos(int x, int y) {
    if (H[x] >= H[y]) return MAXN;
    long long res = ceil(sqr(1.0 * (y - x) / (H[y] - H[x]) + H[y] - H[x]) / 4 + x);
    return min(res, 1ll * MAXN);  
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, first = 0, last = 0; cin >> N;
    for (int i = 0; i < N; i++) cin >> H[i];
    int idx = max_element(H, H + N) - H, lim = H[idx] - ceil(sqrt(N));
    for (int i = 0; i < N; i++) {
        if (H[i] >= lim && (first == last || H[i] > H[A[last - 1]])) {
            while (last - first > 1 && B[last - 1] >= pos(A[last - 1], i))
                last--;
            A[last++] = i;
            if (last > 1) B[last - 1] = pos(A[last - 2], A[last - 1]);
        }
        while (last - first > 1 && B[first + 1] <= i) first++;
        if (first < last)
            cmax(P[i], H[A[first]] - H[i] + ceil(sqrt(i - A[first])));
    }
    reverse(H, H + N); first = last = 0;
    for (int i = 0; i < N; i++) {
        if (H[i] >= lim && (first == last || H[i] > H[A[last - 1]])) {
            while (last - first > 1 && B[last - 1] >= pos(A[last - 1], i))
                last--;
            A[last++] = i;
            if (last > 1) B[last - 1] = pos(A[last - 2], A[last - 1]);
        }
        while (last - first > 1 && B[first + 1] <= i) first++;
        if (first < last) {
            cmax(P[N - i - 1], H[A[first]] - H[i] + ceil(sqrt(i - A[first])));
        }
    }
    for (int i = 0; i < N; i++) cout << P[i] << '\n';
}