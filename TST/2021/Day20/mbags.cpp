#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock
::now().time_since_epoch().count());

int randInt(int l, int r) {
    return uniform_int_distribution <int> (l, r)(rng);
}

const int N = 505;

int val[N], n, m, cur[N], nxt[N], mx = 0;
vector <int> idx;

int calc() {
    int lo = mx, hi = 2e9;
    while (lo < hi) {
        int mi = lo + (hi - lo) / 2, cnt = 0;
        for (int i = 0; i < n; ) {
            int j = i, sum = 0;
            while (j < n && sum + val[idx[j]] <= mi)
                sum += val[idx[j++]];
            i = j; cnt++;
        }
        if (cnt <= m) hi = mi;
        else lo = mi + 1;
    }
    return hi;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> val[i]; mx = max(mx, val[i]);
    }
    vector <int> ans(n);
    iota(ans.begin(), ans.end(), 0);
    idx = ans;
    int res = calc(), pre = res;
    double temp = 1e9, t0 = 1e9;
    while (clock() < CLOCKS_PER_SEC * 10) {
        for (int i = 0; i < n; i++)
            cur[i] = nxt[i];
        for (int i = 0; i < n * temp / t0; i++)
            nxt[randInt(0, n - 1)] ^= 1;
        vector <int> pos;
        for (int i = 0; i < n; i++)
            if (nxt[i]) pos.push_back(i);
        int tmp = 1e9;
        vector <int> sff = pos;
        shuffle(sff.begin(), sff.end(), rng);
        for (int i = 0; i < sff.size(); i++)
            idx[pos[i]] = sff[i];
        tmp = calc();
        if (tmp < res) {
            res = tmp; ans = idx;
        }
        for (int i = 0; i < sff.size(); i++)
            idx[pos[i]] = pos[i];
        if (tmp < pre) pre = tmp;
        else {
            double prob = exp((tmp - pre) / temp);
            int x = randInt(1, 100000000);
            int y = randInt(1, 100000000);
            x %= y;
            if (double(x) / y <= prob) pre = tmp;
            else {
                for (int i = 0; i < n; i++)
                    nxt[i] = cur[i];
            }
        }
        temp *= 0.9999;
    }
    idx = ans;
    while (clock() < 5 * CLOCKS_PER_SEC) {
        pre = calc();
        while (true) {
            bool found = false;
            for (int i = 0; i < n; i++)
                for (int j = i + 1; j < n; j++) {
                    swap(idx[i], idx[j]);
                    int tmp = calc();
                    if (tmp < res) {
                        res = tmp; ans = idx;
                    }
                    if (tmp < pre) {
                        pre = tmp; found = true;
                    }
                    else swap(idx[i], idx[j]);
                }
            if (!found) break;
        }
        shuffle(idx.begin(), idx.end(), rng);
    }
    int cnt = m;
    for (int i = 0; i < n; ) {
        int j = i, sum = 0;
        while (j < n && sum + val[ans[j]] <= res)
            sum += val[ans[j++]];
        cout << j - i << ' ';
        for (int x = i; x < j; x++)
            cout << ans[x] << ' ';
        cout << '\n'; cnt--; i = j;
    }
    while (cnt--) cout << "0\n";
}