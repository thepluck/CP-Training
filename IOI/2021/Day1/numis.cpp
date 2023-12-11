#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock
::now().time_since_epoch().count());

int rand_int(int l, int r) {
    return uniform_int_distribution<int> (l, r)(rng);
}

long double rand_real(long double l, long double r) {
    return uniform_real_distribution<long double> (l, r)(rng);
}

bool bit1[64], bit2[64];
long long dp[200];

long long count(vector<int> ans) {
    long long cnt = 1;
    for (int i = 0; i < ans.size(); i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
            if (ans[j] < ans[i])
                dp[i] += dp[j];
        cnt += dp[i];
    }
    return cnt;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    long long n; cin >> n; n++;
    vector<int> on;
    for (int k = 0; k < 64; k++)
        if (n >> k & 1) on.push_back(k);
    int start = on.back() - 1;
    on.pop_back(); dp[0] = 1;
    auto calc = [&]() {
        vector<int> ans; int cnt = 0;
        long long m = 1;
        for (int i = start; i >= 0; i--) {
            ans.push_back(++cnt);
            dp[cnt] = m; m <<= 1;
            if (bit1[i]) {
                ans.insert(ans.begin(), ++cnt);
                m++; dp[cnt] = 1;
            }
        }
        while (m < n) {
            dp[++cnt] = m; int i = ans.size();
            while (m + dp[cnt] > n)
                dp[cnt] -= dp[ans[--i]];
            ans.insert(ans.begin() + i, cnt);
            m += dp[cnt];
        }
        return ans;
    };
    auto calc2 = [&]() {
        long long p = n, m = 1;
        vector<int> ans; int cnt = 0;
        for (int i = start; i >= 0; i--) {
            if (bit1[i] && (p ^ (1ll << i)) <= n)
                p ^= 1ll << i;
            ans.push_back(++cnt);
            dp[cnt] = m; m <<= 1;
            if (p >> i & 1) {
                ans.insert(ans.begin(), ++cnt);
                m++; dp[cnt] = 1;
            }
        }
        while (m < n) {
            dp[++cnt] = m; int i = ans.size();
            while (m + dp[cnt] > n)
                dp[cnt] -= dp[ans[--i]];
            ans.insert(ans.begin() + i, cnt);
            m += dp[cnt];
        }
        return ans;
    };
    vector<int> ans = calc();
    for (int step = 0; step < 5; step++) {
        memset(bit1, 0, sizeof bit1);
        if (step == 0) {
            for (int i : on) bit1[i] = 1;
        } else if (step > 1) {
             for (int i : on)
                 bit1[i] = rand_int(0, 1);
        }
        vector<int> cur = calc();
        if (cur.size() < ans.size()) ans = cur;
        long double t0 = 1e9, temp = t0;
        while (clock() < 5 * (step + 1) * CLOCKS_PER_SEC) {
            memcpy(bit2, bit1, sizeof bit1);
            // for (int i = 0; i < on.size() * temp / t0; i++)
            //     bit1[on[rand_int(0, on.size() - 1)]] ^= 1;   
            bit1[on[rand_int(0, on.size() - 1)]] ^= 1;
            vector<int> nxt = calc();
            if (nxt.size() < ans.size()) ans = nxt;
            if (nxt.size() < cur.size()) cur = nxt;
            else {
                long double prob = exp((cur.size() - nxt.size()) / temp);
                if (rand_real(0, 1) < prob) cur = nxt;
                else memcpy(bit1, bit2, sizeof bit1);
            }
            temp *= 0.99999;
        }
    }
    // for (int step = 0; step < 5; step++) {
    //     for (int i = start; i >= 0; i--)
    //         bit1[i] = rand_int(0, 1);
    //     vector<int> cur = calc2();
    //     if (cur.size() < ans.size()) ans = cur;
    //     long double t0 = 1e9, temp = t0;
    //     while (clock() < 5 * (step + 1) * CLOCKS_PER_SEC) {
    //         memcpy(bit2, bit1, sizeof bit1);
    //         // for (int i = 0; i < on.size() * temp / t0; i++)
    //         //     bit1[on[rand_int(0, on.size() - 1)]] ^= 1;   
    //         bit1[rand_int(0, start)] ^= 1;
    //         vector<int> nxt = calc2();
    //         if (nxt.size() < ans.size()) ans = nxt;
    //         if (nxt.size() < cur.size()) cur = nxt;
    //         else {
    //             long double prob = exp((cur.size() - nxt.size()) / temp);
    //             if (rand_real(0, 1) < prob) cur = nxt;
    //             else memcpy(bit1, bit2, sizeof bit1);
    //         }
    //         temp *= 0.99999;
    //     }
    // }
    // while (clock() < 20 * CLOCKS_PER_SEC) {
    //     for (int i : on) bit1[i] = rand_int(0, 1);
    //     vector<int> cur = calc();
    //     if (cur.size() < ans.size()) ans = cur;
    // }
    // while (clock() < 20 * CLOCKS_PER_SEC) {
    //     shuffle(on.begin(), on.end(), rng);
    //     for (int i : on) bit1[i] = 0;
    //     for (int i : on) {
    //         bit1[i] = 1;
    //         vector<int> cur = calc();
    //         if (cur.size() < ans.size()) ans = cur;
    //     }
    // }
    cout << ans.size() << '\n';
    for (int x : ans) cout << x << ' ';
    assert(count(ans) == n);
}
