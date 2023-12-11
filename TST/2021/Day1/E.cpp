#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int val[N], num[N], id[N];
int first[N], last[N], n, tot;
vector <int> cnt[N / 2];
long long res;

void rec1(int i, int mask, int d) {
    if (i == n / 2) {
        cnt[d][mask]++; return;
    }
    if (num[val[i]]) {
        if (d + num[val[i]] >= 0)
            rec1(i + 1, mask, d + num[val[i]]);
    }
    else {
        num[val[i]] = 1;
        if (id[val[i]] >= 0)
            rec1(i + 1, mask + (1 << id[val[i]]), d + 1);
        else rec1(i + 1, mask, d + 1);
        num[val[i]] = -1;
        if (d > 0) rec1(i + 1, mask, d - 1);
        num[val[i]] = 0;
    }
}

void rec2(int i, int mask, int d) {
    if (i == n / 2) {
        res += cnt[d][mask]; return;
    }
    if (num[val[i]]) {
        if (d + num[val[i]] >= 0)
            rec2(i + 1, mask, d + num[val[i]]);
    }
    else {
        num[val[i]] = 1;
        rec2(i + 1, mask, d + 1);
        num[val[i]] = -1;
        if (d > 0) {
            if (id[val[i]] >= 0)
                rec2(i + 1, mask + (1 << id[val[i]]), d - 1);
            else rec2(i + 1, mask, d - 1);
        }
        num[val[i]] = 0;
    }
}

void rec3(int i, int d) {
    if (i == n) {
        res += d == 0; return;
    }
    if (num[val[i]]) {
        if (d + num[val[i]] >= 0)
            rec3(i + 1, d + num[val[i]]);
    }
    else {
        num[val[i]] = 1;
        rec3(i + 1, d + 1);
        num[val[i]] = -1;
        if (d > 0) rec3(i + 1, d - 1);
        num[val[i]] = 0;
    }
}

int main() {
    freopen("parentheses.inp", "r", stdin);
    freopen("parentheses.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    memset(first, -1, sizeof first);
    while (cin >> val[n]) {
        if (first[val[n]] < 0)
            first[val[n]] = n;
        last[val[n]] = n; n++;
    }
    if (n & 1) return cout << 0, 0;
    memset(id, -1, sizeof id);
    for (int i = 0; i < n; i++)
        if (first[i] < n / 2 && last[i] >= n / 2)
            id[i] = tot++;
    if (tot >= 22) {
        rec3(0, 0); cout << res; return 0;
    }
    for (int i = 0; i <= n / 2; i++)
        cnt[i].resize(1 << tot);
    rec1(0, 0, 0);
    reverse(val, val + n);
    rec2(0, 0, 0);
    cout << res;
}