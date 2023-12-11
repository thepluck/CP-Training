#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e3 + 5;
int a[N], l[N], r[N]; ll dp[N][N];
vector <int> st;

/// dp[i][j] is the number of rectangles x * y
/// such that x <= i, y <= j and one edge lie on the ground

ll cal(int n, int k){
    if (n < k) return 0;
    return 1ll * (n - k + 2) * (n - k + 1) / 2;
}

int main(){
    freopen("cutcloth.in", "r", stdin);
    freopen("cutcloth.out", "w", stdout);
    int n, m, k; ll res = 0;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            int x; scanf("%d", &x);
            a[j] = x ? 0 : a[j] + 1;
            dp[i][j] = dp[i - 1][j];
            int tmp = (k - 1) / i + 1;
            dp[i][j] += cal(j, tmp);
        }
        st.clear(); st.push_back(0);
        for (int j = 1; j <= m; j++){
            while (st.size() > 1 &&
            a[st.back()] >= a[j]) st.pop_back();
            l[j] = st.back() + 1;
            st.push_back(j);
        }
        st.clear(); st.push_back(m + 1);
        for (int j = m; j > 0; j--){
            while (st.size() > 1 &&
            a[st.back()] > a[j]) st.pop_back();
            r[j] = st.back() - 1;
            st.push_back(j);
        }
        for (int j = 1; j <= m; j++){
            res += dp[a[j]][r[j] - l[j] + 1];
            res -= dp[a[j]][j - l[j]];
            res -= dp[a[j]][r[j] - j];
        }
    }
    printf("%lld\n", res);
}