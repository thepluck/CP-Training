#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
char s[N]; int cnt[N];

int main(){
    scanf("%s", s + 1); int n = strlen(s + 1);
    s[0] = s[n + 1] = '0'; int res = 0;
    for (int i = 1, st; i <= n; i++){
        if (s[i] == '7' && s[i - 1] != '7') st = i;
        if (s[i] == '7' && s[i + 1] != '7'){
            for (int j = st; j <= i; j++)
                cnt[j - st + 1] += i - j + 1;
            res = max(res, i - st + 1);
        }
    }
    for (int i = 1; i <= res; i++)
        printf("%d %d\n", i, cnt[i]);

}