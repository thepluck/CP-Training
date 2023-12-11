#include <bits/stdc++.h>
using namespace std;

int fac[13], a[20], ans[20];
bitset <20> mark; int x;

int main(){
    fac[0] = 1; int n = 0;
    for (int i = 1; i <= 12; i++)
        fac[i] = fac[i - 1] * i;
    while (cin >> x) a[++n] = x; n--; x--;
    int res = 0; mark.set();
    for (int i = 1; i <= n; i++){
        int cnt = 0;
        for (int j = i + 1; j <= n; j++)
            cnt += a[j] < a[i];
        res += cnt * fac[n - i];
    }
    cout << res + 1 << '\n';
    for (int i = 1; i <= n; i++){
        int cnt = x / fac[n - i];
        x %= fac[n - i];
        for (int j = 1; j <= n; j++){
            if (mark[j] && cnt == 0){
                a[i] = j;  mark[j] = 0; break;
            }
            if (mark[j]) cnt--;
        }
    }
    for (int i = 1; i <= n; i++) 
        cout << a[i] << ' ';
    cout << endl;
}