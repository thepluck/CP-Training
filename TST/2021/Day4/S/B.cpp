#include <bits/stdc++.h>

using namespace std;

long long dp1[30000], dp2[30000];

int main() {
    freopen("divisors.inp", "r", stdin);
    freopen("divisors.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    long long a; cin >> a;
    vector <long long> divi;
    for (long long d = 1; d * d <= a; d++)
        if (a % d == 0) {
            divi.push_back(d);
            if (d * d != a)
                divi.push_back(a / d);
        }
    vector <pair <long long, long long>> can;
    sort(divi.begin(), divi.end());
    for (long long d : divi) {
        if (d <= 2) continue;
        long long pr = d - 1;
        for (long long x = 2; x * x < d; x++)
            if ((d - 1) % x == 0) {
                pr = x; break;
            }
        long long tmp = d - 1;
        while (tmp % pr == 0) tmp /= pr;
        if (tmp == 1) can.emplace_back(pr, d);
    }
    sort(can.begin(), can.end());
    dp1[0] = 1;
    for (int i = 0; i < can.size(); ) {
        int j = i;
        while (j < can.size() &&
        can[i].first == can[j].first) j++;
        fill_n(dp2, divi.size(), 0);
        for (int k = i; k < j; k++) {
            long long x = can[k].second;
            int pt = 0;
            for (int p = 0; p < divi.size(); p++)
                if (divi[p] % x == 0) {
                    while (divi[pt] < divi[p] / x) pt++;
                    dp2[p] += dp1[pt];
                }
        }
        for (int k = 0; k < divi.size(); k++)
            dp1[k] += dp2[k];
        i = j;
    }
    cout << dp1[divi.size() - 1] << '\n';
}