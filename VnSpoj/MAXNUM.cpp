#include <bits/stdc++.h>
using namespace std;

const int N = 30005;
int min_div[N], cnt[N];
vector <int> prime;

void prime_sieve(){
    for (int i = 1; i < N; i++) min_div[i] = i;
    for (int i = 2; i * i < N; i++)
        if (min_div[i] == i)
            for (int j = i * i; j < N; j += i)
                if (min_div[j] == j) min_div[j] = i;
}

int cnt_exp(int p, int n){
    int res = 0;
    while (n >= p){
        res += n / p; n /= p;
    }
    return res;
}

int main(){
    int n, p; cin >> n >> p;
    prime_sieve(); int res = INT_MAX;
    for (int i = 2; i <= n; i++)
        if (min_div[i] == i) prime.push_back(i);
    for (int i = 0; i < prime.size(); i++)
        cnt[prime[i]] = cnt_exp(prime[i], n);
    while (p > 1){
        int t = min_div[p], cur = 0;
        while (p % t == 0){
            cur++; p /= t;
        }
        res = min(res, cnt[t] / cur);
    }
    cout << res << '\n';
}