#include <bits/stdc++.h>
using namespace std;

int chk(const char &x){
    if (x == 'A') return 1;
    if (x == 'C') return 2;
    if (x == 'G') return 3;
    if (x == 'T') return 4;
}

int n, m, total, cost[5], ans;
char s[10005], t[5005];

int main(){
    freopen("apple.inp", "r", stdin);
    freopen("apple.out", "w", stdout);
    scanf("%s%s", s + 1, t + 1);
    for (int i = 1; i <= 4; i++)
        scanf("%d", cost + i);
    n = strlen(s + 1); m = strlen(t + 1);
    for (int i = 1; i <= n; i++)
        s[i] = chk(s[i]);
    for (int j = 1; j <= m; j++)
        t[j] = chk(t[j]), total += cost[t[j]];
    for (int i = 1; i <= n; i++){
        int l = i, r = 1, cnt = 0;
        while (l <= n && r <= m){
            if (s[l] != t[r]) r++;
            else {
                cnt += cost[s[l]];
                l++; r++;
            }
            ans = max(ans, cnt);
        }
    }
    cout << total - ans << '\n';
}