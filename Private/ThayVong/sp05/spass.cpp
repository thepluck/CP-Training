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
int cntupp, cntlow, cntnum;
void update(int i, int type){
    if (isdigit(s[i])) cntnum += type;
    if (isupper(s[i])) cntupp += type;
    if (islower(s[i])) cntlow += type;
}

int main(){
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    int ans = n + 1;
    for (int i = 1, k = 0; i <= n; i++){
        update(i - 1, -1);
        while (k < n && !(cntlow && cntnum && cntupp)){
            k++; update(k, 1);
        }
        while (k < n && k < i + 5){
            k++; update(k, 1);
        }
        if (k - i >= 5 && cntlow && cntupp && cntnum) chkmin(ans, k - i + 1);
    }
    cout << ans << endl;
}