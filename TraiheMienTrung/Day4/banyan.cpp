#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

using ii = pair <int, int>;

const int N = 305;
bool a[N][N]; deque <ii> dq;
int row[N][N][N], col[N][N][N];
int tmp[N];

int main(){
    freopen("banyan.inp", "r", stdin);
    freopen("banyan.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            char x; cin >> x;
            if (x == '*') a[i][j] = 1;
        }
    for (int l = 1; l <= k; l++){
        for (int i = 1; i <= n; i++){
            dq.clear();
            int _j = 1, pr = 0, cnt = 0;
            for (int j = 1; j <= m; j++){
                while (!dq.empty() &&
                dq[0].se < j) dq.pop_front();
                cnt -= a[i][j - 1];
                while (_j <= m &&
                cnt + a[i][_j] <= l)
                    cnt += a[i][_j++];
                tmp[j] = _j - pr - 1;
                while (!dq.empty() &&
                tmp[dq.back().fi] < tmp[j])
                    dq.pop_back();
                dq.emplace_back(j, _j);
                row[l][i][j] = tmp[dq[0].fi];
                if (a[i][j]) pr = j;
            }
        }
        for (int j = 1; j <= n; j++){
            dq.clear();
            int _i = 1, pr = 0, cnt = 0;
            for (int i = 1; i <= n; i++){
                while (!dq.empty() &&
                dq[0].se < i) dq.pop_front();
                cnt -= a[i - 1][j];
                while (_i <= n &&
                cnt + a[_i][j] <= l)
                    cnt += a[_i++][j];
                tmp[i] = _i - pr - 1;
                while (!dq.empty() &&
                tmp[dq.back().fi] < tmp[i])
                    dq.pop_back();
                dq.emplace_back(i, _i);
                col[l][i][j] = tmp[dq[0].fi];
                if (a[i][j]) pr = i;
            }
        }
    }
    int res = 0;
    for (int l = 1; l <= k; l++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                res = max(res, row[l][i][j] +
                col[k - l + a[i][j]][i][j] - 1);
    cout << res << '\n';
}