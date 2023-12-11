
// Problem : F. Classical?
// Contest : Codeforces - Codeforces Round #613 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1285/F
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

template <class X, class Y>
bool cmax(X &a, const Y &b) {
    return a < b ? a = b, 1 : 0;
}

const int N = 1e5 + 5;

int mu[N], cnt[N];
bool oc[N];
vector <int> dvi[N];

int query(int x) {
    int res = 0;
    for (int d : dvi[x])
        res += cnt[d] * mu[d];
    return res;
}

void update(int x, int t) {
    for (int d : dvi[x])
        cnt[d] += t;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    stack <int, vector <int>> s;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x; oc[x] = 1;
    }
    mu[1] = 1;
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i)
            cnt[j]++;
        dvi[i].reserve(cnt[i]);
    }
    for (int i = 1; i < N; i++) {
        dvi[i].emplace_back(i);
        for (int j = i * 2; j < N; j += i) {
            dvi[j].emplace_back(i);
            oc[i] |= oc[j]; mu[j] -= mu[i];
        }
    }
    long long res = 1;
    memset(cnt, 0, sizeof cnt);
    for (int i = N - 1; i > 0; i--) {
        if (!oc[i]) continue;
        int c = query(i);
        while (c) {
            if (__gcd(s.top(), i) == 1) {
                cmax(res, 1ll * i * s.top());
                c--;
            }
            update(s.top(), -1); s.pop();
        }
        update(i, 1); s.push(i);
    }
    cout << res << '\n';
}