#include <bits/stdc++.h>
using namespace std;

const int N = (1 << 16) + 5;
const int mod = 1 << 16;
int cnt[N * 4], lo[N * 4], hi[N * 4], a[250005];

void build(int i, int l, int r){
    lo[i] = l; hi[i] = r; 
    if (l == r) return;
    int m = (l + r) / 2;
    build(i * 2, l, m);
    build(i * 2 + 1, m + 1, r);
}

void update(int i, int pos, int t){
    if (lo[i] > pos || hi[i] < pos) return;
    if (lo[i] == hi[i]){
        cnt[i] += t; return;
    }
    update(i * 2, pos, t);
    update(i * 2 + 1, pos, t);
    cnt[i] = cnt[i * 2] + cnt[i * 2 + 1];
}

int order(int i, int k){
    if (lo[i] == hi[i]) return lo[i];
    if (cnt[i * 2] >= k) return order(i * 2, k);
    return order(i * 2 + 1, k - cnt[i * 2]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int seed, mul, add, n, k, nt; 
    cin >> nt; build(1, 0, 1 << 16);
    for (int t = 1; t <= nt; t++){
        memset(cnt, 0, sizeof cnt); 
        cin >> seed >> mul >> add >> n >> k;
        a[1] = seed; long long res = 0;
        for (int i = 2; i <= n; i++)
            a[i] = (1ll * mul * a[i - 1] + add) % mod;
        for (int i = 1; i < k; i++) update(1, a[i], 1);
        for (int i = k; i <= n; i++){
            update(1, a[i], 1); 
            res += order(1, (k + 1) / 2);
            update(1, a[i - k + 1], -1);
        }
        cout << "Case #" << t << ": " << res << '\n';
    }
}