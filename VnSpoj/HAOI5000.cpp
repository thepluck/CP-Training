#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e6 + 5; 
ll dis[N]; int cnt[3 * N]; 
int sumc[3 * N];

int main(){
    int n, k, l, r; cin >> n >> k;
    for (int i = 1, x; i <= k; i++){
        cin >> x; cnt[x]++; 
        cnt[x + n]++; cnt[x + 2 * n]++;
    }
    for (int i = 1; i <= 3 * n; i++)
        sumc[i] = sumc[i - 1] + cnt[i];
    l = n + 1 - n / 2; r = l + n - 1;
    for (int i = l; i <= r; i++)
        dis[1] += cnt[i] * abs(n + 1 - i);
    for (int i = 2; i <= n; i++){
        dis[i] = dis[i - 1] + sumc[n + i - 1] - sumc[l];
        dis[i] -= sumc[r] - sumc[n + i - 1];
        dis[i] -= cnt[l++] * (n + i - l) - cnt[++r] * (r - n - i);
    }
    ll min_dis = *min_element(dis + 1, dis + n + 1);
    int cnt_min = 0; cout << min_dis << '\n';
    for (int i = 1; i <= n; i++)
        if (dis[i] == min_dis) cnt_min++;
    cout << cnt_min << '\n'; 
    for (int i = 1; i <= n; i++)
        if (dis[i] == min_dis) cout << i << ' ';
}