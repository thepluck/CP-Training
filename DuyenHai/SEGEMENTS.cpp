#include <bits/stdc++.h>
using namespace std;

#define lb lower_bound
using ll = long long;
ll a[1000005]; int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i]; a[i] += a[i - 1];
    }
    for (int i = 1; i <= n; i++)
        if (a[n] % a[i] == 0){
            ll sum = a[i], pos = i;
            bool flag = true;
            while (pos < n){\
                sum += a[i];
                pos = lb(a + 1, a + n + 1, sum) - a;
                if (a[pos] != sum){
                    flag = false; break;
                }
            }
            if (flag) return cout << a[n] / a[i], 0;
        }
}