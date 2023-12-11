#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll sum[12][10][2];
int cnt[12][10][2];
int digit[12], ndgt;

void go(int i, int dgt, bool less){
    ll &cur_sum = sum[i][dgt][less];
    int &cur_cnt = cnt[i][dgt][less];
    if (cur_cnt != -1) return;
    cur_sum = cur_cnt = 0;
    if (i == ndgt){
        cur_cnt = 1; cur_sum = dgt;
        return;
    }
    int lim = less ? 9 : digit[i + 1];
    for (int nxt = 0; nxt <= lim; nxt++){
        bool __less = less || !(nxt == digit[i + 1]);
        go(i + 1, nxt, __less);
        cur_sum += sum[i + 1][nxt][__less] + 1ll * cnt[i + 1][nxt][__less] * dgt;
        cur_cnt += cnt[i + 1][nxt][__less];
    }
}

ll total(int x){
    if (x == 0) return 0;
    memset(cnt, -1, sizeof(int) * 12 * 10 * 2);
    ndgt = 0; ll res = 0;
    while (x > 0){
        digit[++ndgt] = x % 10; x /= 10;
    }
    reverse(digit + 1, digit + ndgt + 1);
    for (int dgt = 0; dgt < digit[1]; dgt++){
        go(1, dgt, true); res += sum[1][dgt][1];
    }
    go(1, digit[1], false); res += sum[1][digit[1]][0];
    return res;
}

int main(){
    int a, b; 
    while (cin >> a >> b){
        if (a == -1 && b == -1) return 0;
        cout << total(b) - total(a - 1) << '\n';
    }
}