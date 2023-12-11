#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

const int N = 6005;

int f[N], g[N], non[N];
pair <int, int> seg[N], imp[N];
deque <pair <int, int>> dq;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> seg[i].fi >> seg[i].se;
    int cntImp = 0, cntNon = 0;
    for (int i = 1; i <= n; i++) {
        bool flag = false;
        for (int j = 1; j <= n; j++)
            if ((seg[i].fi <= seg[j].fi && seg[i].se > seg[j].se)
            || (seg[i].fi < seg[j].fi && seg[i].se >= seg[j].se))
                flag = true;
        if (flag) non[++cntNon] = seg[i].se - seg[i].fi;
        else imp[++cntImp] = seg[i];
    }
    sort(imp + 1, imp + cntImp + 1);
    sort(non + 1, non + cntNon + 1, greater <int> ());
    for (int i = 1; i <= cntNon; i++)
        non[i] += non[i - 1];
    int res = 0;
    memset(f, 0xc0, sizeof f); f[0] = 0;
    for (int i = 1; i <= cntImp; i++) {
        dq.clear();
        for (int j = i; j <= cntImp; j++) {
            while (dq.size() && dq.front().fi <= imp[j].fi)
                dq.pop_front();
            int val = f[j - 1] + imp[j].se;
            while (dq.size() && dq.back().se < val)
                dq.pop_back();
            dq.emplace_back(imp[j].se, val);
            g[j] = dq.front().se - imp[j].fi;
        }
        swap(f, g);
        if (i <= m && m - i <= cntNon)
            res = max(res, f[cntImp] + non[m - i]);
    }
    cout << res;
}