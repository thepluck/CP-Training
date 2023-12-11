#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 1005;

bool a[N][N]; ll res = 0; int h[N];
int le[N], ri[N], n, q, l[N][N], r[N][N];

void recalc(int i) {
    for (int j = 1; j <= n; j++) {
        l[i][j] = l[i][j - 1] + 1;
        if (a[i][j]) l[i][j] = 0;
    }
    for (int j = n; j > 0; j--) {
        r[i][j] = r[i][j + 1] + 1;
        if (a[i][j]) r[i][j] = 0;
    }
}

void update(int i, int j) {
    bool t = a[i][j]; int up = 0;
    a[i][j] = 0; recalc(i);
    ll sumlr = 0, suml = 0, sumr = 0;
    for (int x = i; x > 0; x--) {
        if (a[x][j]) {up = x; break;}
        le[x]= l[x][j]; ri[x] = r[x][j];
        if (x < i) {
            le[x] = min(le[x], le[x + 1]);
            ri[x] = min(ri[x], ri[x + 1]);
        }
        sumlr += le[x] * ri[x];
    }
    int p1 = i, p2 = i, p3 = i; ll sum = 0;
    for (int x = i; x <= n; x++) {
        if (a[x][j]) break;
        le[x] = l[x][j]; ri[x] = r[x][j];
        if (x > i) {
            le[x] = min(le[x], le[x - 1]);
            ri[x] = min(ri[x], ri[x - 1]);
        }
        while (p1 > up && (le[p1] >
        le[x] || ri[p1] > ri[x])) {
            sumlr -= le[p1] * ri[p1];
            suml += le[p1];
            sumr += ri[p1]; p1--;
        }
        while (p2 > p1 && (le[p2] <=
        le[x] || ri[p2] > ri[x])) {
            sumr -= ri[p2]; p2--;
        }
        while (p3 > p1 && (le[p3] >
        le[x] || ri[p3] <= ri[x])) {
            suml -= le[p3]; p3--;
        }
        sum += sumlr;
        sum += sumr * le[x];
        sum += suml * ri[x];
        sum += 1ll * le[x] * ri[x]
        * (i - max(p2, p3));

    }
    if (t) res += sum; else res -= sum;
    a[i][j] = t ^ 1; recalc(i);
}

ll calc(int w, int h) {
    return 1ll * w * (w + 1) / 2 * h;
}

void preCalc() {
    for (int i = 1; i <= n; i++) {
        vector <int> st; st.push_back(0);
        for (int j = 1; j <= n; j++) {
            if (a[i][j]) h[j] = 0;
            else h[j]++;
            while (st.size() > 1 &&
            h[j] <= h[st.back()])
                st.pop_back();
            le[j] = st.back() + 1;
            st.push_back(j);
        }
        st.clear(); st.push_back(n + 1);
        for (int j = n; j > 0; j--) {
            while (st.size() > 1 &&
            h[j] < h[st.back()])
                st.pop_back();
            ri[j] = st.back() - 1;
            res += calc(ri[j] - le[j] + 1, h[j]);
            res -= calc(j - le[j], h[j]);
            res -= calc(ri[j] - j, h[j]);
            st.push_back(j);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        string s; cin >> s; int j = 0;
        for (char c : s) {
            j++; a[i][j] = c - '0';
        }
    }
    preCalc();
    for (int i = 1; i <= n; i++) recalc(i);
    cout << res << '\n';
    while (q--) {
        int i, j; cin >> i >> j;
        update(i + 1, j + 1);
        cout << res << '\n';
    }
}