#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e6;
int t, mod, n, m, k;
bool pr[N + 5];
ll gt[N + 5], igt[N + 5], d[N + 5];

ll Pow(ll a, ll b) {
    if (b == 0) return 1;
    ll cur = Pow(a, b / 2);
    cur = (cur * cur) % mod;
    if (b % 2) return (cur * a) % mod;
    return cur;
}

ll cal1(int k, int n) {
    if (k > n) return 0;
    return (((gt[n] * igt[k]) % mod) * igt[n - k]) % mod;
}

ll cal2(int k, int n) {
    ll res1 = 1; ll res2 = 1;

    for(int i = n - k + 1;i <= n; i++)
        res1 = (res1 * i) % mod;
    for(int i = 1; i <= k; i++)
        res2 = (res2 * i) % mod;

    return (res1 * Pow(res2,mod-2)) % mod;
}

ll cal3(int k, int n) {
    for (int i = 1; i <= k; i++)
        d[i] = n + i - k;
    for (int i = 2; i <= k; i++)
    if (!pr[i]) {
        ll sz = i, sum = 0;
        while(sz <= k) {
            sum += k / sz; sz *= i;
        }

        ll L = ((n - k) / i + 1) * i;

        for (int j = L; j <= n; j+=i)
        while (d[j - (n - k)]%i == 0 && sum > 0) {
            d[j - (n - k)] /= i; sum--;
        }
    }
    ll res = 1;
    for (int i = 1;i <= k; i++)
        res = (res * d[i]) % mod;
    return res;
}

void prepare() {
    gt[0] = 1;
    for(int i = 1; i <= N; i++)
        gt[i] = (gt[i - 1] * i) % mod;

    igt[N] = Pow(gt[N], mod - 2);
    for(int i = N - 1; i >= 0; --i)
        igt[i] = (igt[i + 1] * (i + 1)) % mod;

    for(int i = 2; i * i < N; i++)
    if (!pr[i]) for (int j = i * i; j < N; j += i) pr[j] = true;
}

void solve1() {
    ll res1 = (m * Pow(m - 1,k)) % mod;
    ll res2 = cal1(k, n - 1);
    cout << (res1 * res2) % mod <<'\n';
}
void solve2()
{
    ll res1 = (m * Pow(m - 1, k)) % mod;
    ll res2 = cal2(k, n - 1);
    cout << (res1 * res2) % mod << '\n';
}

void solve3() {
    ll res1 = (m * Pow(m - 1, k)) % mod;
    ll res2 = cal3(k, n - 1);
    cout << (res1 * res2) % mod <<'\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> t >> mod; prepare();
    for(int i = 1; i <= t; i++) {
        cin >> n >> m >> k;
        if(mod != 998244353) solve3();
        else {
            if (n <= 1000000) solve1();
            else solve2();
        }
    }
}

