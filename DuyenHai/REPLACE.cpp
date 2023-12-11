#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e6 + 10;
int a[N]; bitset <N> av;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();
    s = ' ' + s; t = ' ' + t;
    for (int i = 1; i <= n; i++)
        a[i] = a[i - 1] + s[i] - '0';
    for (int x = n, y = m; x > 0 && y > 0; x--, y--)
        if (s[x] == t[y]) av[x] = true; else break;
    int res = 0, start = 0; av[n + 1] = true;
    for (int i = 1; i <= m; i++){
        ll cur = 0;
        for (int j = 0; j <= min(10, m - i + 1); j++){
            cur = cur * 10 + int(t[i + j] - '0');
            int last = n - m + i + j;
            if (last >= i && av[last + 1] && a[last] - a[i - 1] == cur)
                if (res < last - i + 1) 
                    res = last - i + 1, start = i;
            if (t[i] == '0') break;
        }
        if (s[i] != t[i]) break; 
    }
    cout << start << ' ' << start + res - 1;
}