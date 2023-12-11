#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;
const int MAXN = 1000010;

int add(int x, int y) {
    return (x += y) >= MOD ? x - MOD : x;
}

int sub(int x, int y) {
    return (x -= y) < 0 ? x + MOD : x;
}

int cnt[MAXN], sum[MAXN]; char S[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    scanf("%s", S + 3);
    int N = strlen(S + 3);
    S[1] = S[N + 4] = '*'; S[2] = S[N + 3] = '?'; 
    sum[1] = sum[2] = cnt[1] = 1;
    for (int i = 3, j = 0; i <= N + 4; i++) {
        sum[i] = sum[i - 1];
        if (S[i - 2] != '0' && S[i - 2] != '?') j = i - 2;
        if (i == N + 3 || (S[i] != '*' && S[i] != '?')) continue;
        cnt[i] = cnt[i - 1];
        if (S[i - 1] == '?' || S[i - 1] == '2')
            cnt[i] = add(cnt[i], cnt[i - 2]);
        if (i < 4 || (S[i - 1] != '?' && S[i - 1] != '1')) goto gg;
        if (j <= i - 3) {
            cnt[i] = add(cnt[i], sub(sum[i - 3], sum[j]));
            if (S[j] == '*' && S[j + 1] == '?')
                cnt[i] = add(cnt[i], cnt[j]);
        }
        if (S[j] == '1' && (S[j - 1] == '*' || S[j - 1] == '?'))
            cnt[i] = add(cnt[i], cnt[j - 1]);
        gg:if (S[i + 1] == '?') sum[i] = add(sum[i], cnt[i]);
     }
     printf("%d", cnt[N + 4]);
}