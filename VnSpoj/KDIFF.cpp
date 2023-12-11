#include <iostream>
#include <map>
using namespace std;

struct seg{
    int mi, ma;
};

const int N = 3e5 + 5;
seg spt[N][20];
int a[N], pow2[N], log2[N];
int n, k, len[N], mlen[N];

int get_min(int l, int r){
    return min(spt[l][log2[r - l + 1]].mi, 
            spt[r + 1 - pow2[r - l + 1]][log2[r - l + 1]].mi);
}

int get_max(int l, int r){
    return max(spt[l][log2[r - l + 1]].ma,
            spt[r + 1 - pow2[r - l + 1]][log2[r - l + 1]].ma);
}

int get_diff(int l, int r){
    return get_max(l, r) - get_min(l, r);
}

void pre_calc(){
    pow2[1] = 1; log2[1] = 0;
    for (int i = 2; i <= n; i++){
        pow2[i] = pow2[i - 1]; log2[i] = log2[i - 1];
        if (!(i & (i - 1))){
            pow2[i] <<= 1; log2[i]++;
        }
    }
    for (int k = 1, p = 1; k < 20; k++, p <<= 1)
        for (int i = 0; i + (p << 1) <= n; i++){
            spt[i][k].mi = min(spt[i][k - 1].mi, spt[i + p][k - 1].mi);
            spt[i][k].ma = max(spt[i][k - 1].ma, spt[i + p][k - 1].ma);
        }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> a[i]; spt[i][0] = {a[i], a[i]};
    }
    pre_calc();
    for (int i = 0; i < n; i++){
        int l = 1, r = n - i, m;
        while (l <= r){
            m = (l + r) >> 1;
            if (get_diff(i, i + m - 1) <= k){
                len[i] = m; l = m + 1;
            }
            else r = m - 1;
        }
    }
    for (int i = n - 1; i >= 0; i--)
        mlen[i] = max(len[i], mlen[i + 1]);
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, len[i] + mlen[i + len[i]]);
    cout << ans << '\n';
}