#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int inf = 0x3f3f3f3f;
using ii = pair <int, int>;
int pre[N], a[N], su[N];

void sieve(){
    iota(pre + 2, pre + N, 2);
    for (int i = 2; i * i < N; i++)
        if (pre[i] == i)
            for (int j = i * i; j < N; j += i)
                pre[j] = min(pre[j], i);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n; sieve();
    for (int i = 1; i <= n; cin >> a[i++]);
    set <int> prime;
    for (int i = n; i > 0; i--)
        su[i] = __gcd(su[i + 1], a[i]);
    for (int i = 1, tt = 0; i <= n; i++){
        int cc = __gcd(tt, su[i + 1]);
        while (cc > 1){
            int tmp = pre[cc]; prime.insert(tmp);
            while (cc % tmp == 0) cc /= tmp;
        }
        tt = __gcd(tt, a[i]);
    }
    long long res = 1;
    for (int p : prime){
        int fir = inf, sec = inf;
        for (int i = 1; i <= n; i++){
            int tmp = a[i], cnt = 0;
            while (tmp % p == 0){
                tmp /= p; cnt++;
            }
            if (fir > cnt){
                sec = fir; fir = cnt;
            }
            else sec = min(sec, cnt);
        }
        res *= pow(p, sec);
    }
    cout << res << '\n';
}