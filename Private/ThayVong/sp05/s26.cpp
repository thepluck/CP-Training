#include <bits/stdc++.h>
using namespace std;

template <class T, class _T>
bool chkmax(T &a, const _T &b){
    return a < b ? a = b, true : false;
}

template <class T, class _T>
bool chkmin(T &a, const _T &b){
    return a > b ? a = b, true : false;
}

char s[100005];
int cnt[256], cond = 1;

void update(int i, int type){
    cnt[s[i]] += type;
    if (cnt[s[i]] == 0) cond--;
    if (type == 1 && cnt[s[i]] == 1) cond++;
}

int main(){
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    int ans = n + 1; cnt[0] = 1;
    for (int i = 1, k = 0; i <= n; i++){
        update(i - 1, -1);
        while (cond < 26 && k < n){
            k++; update(k, 1);
        }
        if (cond == 26) chkmin(ans, k - i + 1);
        //cout << ans << ' ' << k << ' ' << cond << '\n';
    }
    cout << (ans ==  n + 1 ? 0 : ans) << endl;
}