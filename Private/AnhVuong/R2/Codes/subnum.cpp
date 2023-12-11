#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

const int N = 100005;

char str[N], ans[N];
int last[10], rig[N][10], pos[N];
vector <pair <int, int>> que[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    cin >> (str + 1) >> q;
    n = strlen(str + 1);
    for (int i = 1; i <= q; i++) {
        int k, l; cin >> k >> l;
        que[k].emplace_back(l, i);
    }
    for (int d = 0; d < 10; d++)
        last[d] = n + 1;
    for (int i = n; i > 0; i--) {
        for (int d = 0; d < 10; d++)
            rig[i][d] = last[d];
        last[str[i] - '0'] = i;
    }
    for (int d = 0; d < 10; d++)
        rig[0][d] = last[d];
    int far = n + 1, cur = 0, top = 0;
    for (int i = 1; i <= n; i++) {
        while (cur == far - 1) {
            far = pos[top--];
            cur = pos[top];
        }
        for (int d = 9; d >= 0; d--)
            if (rig[cur][d] < far) {
                cur = rig[cur][d]; break;
            }
        pos[++top] = cur;
        for (auto qq : que[i])
            if (qq.fi <= top)
                ans[qq.se] = str[pos[qq.fi]];
            else ans[qq.se] = str[n - i + qq.fi];
    }
    cout << (ans + 1);
}