#include <bits/stdc++.h>
using namespace std;

using ii = pair <int, int>;
using ll = long long;
const int N = 1e6 + 5;
char s[N]; int n, k; 
ll res = 0;
unordered_map <ll, int> mp;

int main(){
    scanf("%d%d%s", &n, &k, s + 1); 
    ll cnto = 0, cntr = 0; mp[0] = 0;
    for (int i = 1; i <= n; i++){
        if (s[i] == 'O') cnto++; else cntr++;
        if (cnto - k * cntr == 0) res = i;
        if (mp[cnto - k * cntr] != 0) 
            res = max(res, ll(i - mp[cnto - k * cntr]));
        else mp[cnto - k * cntr] = i;
    }
    cout << res << '\n';
}