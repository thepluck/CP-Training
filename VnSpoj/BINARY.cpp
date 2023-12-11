#include <bits/stdc++.h>
using namespace std;
#define debug(x, t) cout << #x << " = " << x << t

using ll = long long;
int dp[35][2][35][2][2], k, n, digit[35], npos;

int go(int pos, int dgt, int nmean, bool is_less, bool is_pos){
    int &res = dp[pos][dgt][nmean][is_less][is_pos];
    if (res != -1) return res;
    if (pos == npos){
        if (nmean == k) return res = 1;
        return res = 0;
    }
    if (nmean > k) return res = 0; res = 0;
    int lim = is_less ? 1 : digit[pos + 1];
    for (int nxt_dgt = 0; nxt_dgt <= lim; nxt_dgt++){
        bool nxt_is_less = is_less ? 1 : nxt_dgt != digit[pos + 1];
        bool nxt_is_pos = is_pos || nxt_dgt;
        int nxt_nmean = nmean + (nxt_is_pos && nxt_dgt == 0);
        res += go(pos + 1, nxt_dgt, nxt_nmean, nxt_is_less, nxt_is_pos);
    }
    return res;
}

void solve(){
    if (n == 0){
        cout << (k == 1) << '\n'; return;
    }
    memset(dp, -1, sizeof(int) * 35 * 2 * 35 * 2 * 2); npos = 0;
    while (n > 0){
        digit[++npos] = n & 1; n >>= 1;
    }
    reverse(digit + 1, digit + npos + 1);
    cout << go(1, 0, 0, 1, 0) + go(1, 1, 0, 0, 1) + (k == 1) - (k == 0) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while (cin >> n >> k) solve(); 
}