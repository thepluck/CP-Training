#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5 + 5;
const int mod = 999996707;
const int base = 31;
int need[256], cnt[256];
char s[N], t[N]; ll has[N], pw[N];
set <ll> lmao;

ll get(int i, int j){
    return (has[j] - has[i - 1] * pw[j - i + 1] % mod + mod) % mod;
}

int main(){
    scanf("%s%s", s + 1, t + 1);
    for (int i = 1; s[i]; i++) need[s[i]]++;
    int tot = count_if(need, need + 256, [](int x){return x > 0;});
    int cur = 0, k = strlen(s + 1);
    pw[0] = 1; has[0] = 0;
    for (int i = 1; t[i]; i++){
        pw[i] = pw[i - 1] * base % mod;
        has[i] = (has[i - 1] * base + t[i] - 'a' + 1) % mod;
        if (++cnt[t[i]] == need[t[i]]) cur++;
        if (cur == tot) lmao.insert(get(i - k + 1, i));
        if (i >= k && cnt[t[i - k + 1]]-- == need[t[i - k + 1]]) cur--;
    }
    cout << lmao.size() << '\n';
}