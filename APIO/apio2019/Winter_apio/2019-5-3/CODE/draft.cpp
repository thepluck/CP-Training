#include<bits/stdc++.h>
#define REP(i, a, b)            for (int i = a; i < (int) b; ++i)
#define int                     long long
using namespace std;

typedef vector<int> BIG;
const int BASE = 10;

void fix(BIG &a) {
    for (int i = 0; i < (int) a.size(); ++i) {
        if (a[i] / BASE != 0 && i == (int) a.size()-1) a.push_back(0);
        a[i+1] += a[i]/BASE; a[i] %= BASE;
        if (a[i] < 0) { a[i+1]--; a[i] += BASE; }
    }
    while (a.size() >= 2 && a.back() == 0) a.pop_back();
}
BIG To_BIG(int val) {
    BIG ans;
    while (val > 0) ans.push_back(val%BASE), val /= BASE;
    fix(ans); return ans;
}

void operator += (BIG &a, BIG b) {
    a.resize(max(a.size(), b.size()));
    for (int i = 0; i < (int) b.size(); ++i) a[i] += b[i];
    fix(a);
}
BIG operator + (BIG a, BIG b) { a += b; return a; }

//BIG operator * (BIG a, BIG b) {
//    BIG c; c.resize(a.size()+b.size(), 0);
//    REP(i, 0, a.size()) REP(j, 0, b.size()) c[i+j] += a[i] * b[j];
//    fix(c);
//    return c;
//   }

BIG operator * (BIG a, int x) {
    REP(i, 0, a.size()) a[i] *= x;
    fix(a); return a;
}

void Print(BIG a) {
    cout << a.back();
    for (int i = a.size()-2; i >= 0; --i) cout << setfill('0') << setw(1) << a[i];
    cout << '\n';
}

const int N = 504;
int n, m;

BIG dp[N][3], res;

void sol() {
    BIG big_n = To_BIG(n-2);
    BIG big_1 = To_BIG(1);

    dp[1][0] = big_n; dp[1][1] = dp[1][2] = big_1;
    for (int i = 2; i <= m; ++i) {
        dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) * (n - 2);
        dp[i][1] = dp[i-1][0] + dp[i-1][1];
        dp[i][2] = dp[i-1][0] + dp[i-1][2];
    }
    res = dp[m][0] + dp[m][1] + dp[m][2];
    Print(res);
}

#undef int
int main() {
#define int                 long long
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    else if (fopen("labo.inp", "r")) {
        freopen("labo.inp", "r", stdin);
        freopen("labo.out", "w", stdout);
    }

    cin >> n >> m;

    sol();

    return 0;
}
