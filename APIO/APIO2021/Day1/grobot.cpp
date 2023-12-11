#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000005;

int pdiv[MAXN], cnt[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    iota(pdiv, pdiv + MAXN, 0);
    for (int i = 2; i * i < MAXN; i++)
        if (pdiv[i] == i)
            for (int j = i * i; j < MAXN; j += i)
                pdiv[j] = i;
    int T; cin >> T;
    while (T--) {
        int N, zero = 0; cin >> N;
        vector <int> prime;
        while (N--) {
            int x; cin >> x;
            if (x == 0) {
                zero++; continue;
            }
            if (x < 0) x = -x;
            while (x > 1) {
                int p = pdiv[x]; cnt[p]++;
                while (x % p == 0) x /= p;
                prime.push_back(p);
            }
        }
        int res = 0;
        for (int p : prime)
            res = max(res, cnt[p]);
        for (int p : prime) cnt[p] = 0;
        cout << res + zero << '\n';
    }
}
