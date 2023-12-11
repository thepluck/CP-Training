#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
bitset <N> x[26], ans;
char s[N], t[N], c[5];

int main(){
    int q, n, m;
    scanf("%s%d", s + 1, &q);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++)
        x[s[i] - 'a'][i] = 1;
    while (q--){
        int cmd; scanf("%d", &cmd);
        if (cmd == 1){
            int i; scanf("%d%s", &i, c);
            x[s[i] - 'a'][i] = 0;
            x[(s[i] = c[0]) - 'a'][i] = 1;
        }
        else {
            int l, r; ans.set();
            scanf("%d%d%s", &l, &r, t + 1);
            m = strlen(t + 1);
            if (r - l + 1 < m){
                puts("0"); continue;
            }
            for (int i = 1; i <= m; i++)
                ans &= x[t[i] - 'a'] >> i;
            int res = (ans >> (l - 1)).count()
                - (ans >> (r - m + 1)).count();
            printf("%d\n", res);
        }
    }
}