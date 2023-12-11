#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

const int MAXN = 200005;

int cnt[MAXN * 4][2][2], cur, B[MAXN];
vector <pair <int, int>> seg;
int pmin[MAXN], pmax[MAXN], val[MAXN];
vector <pair <int, int>> chn;

void build(int i, int l, int r) {
    if (l == r) cnt[i][1][1] = -1;
    else {
        int m = (l + r) / 2;
        build(i * 2, l, m);
        build(i * 2 + 1, m + 1, r);
    }
}

void merge(int A[][2], int B[][2], int C[][2], int v) {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            C[i][j] = max({A[i][0] + B[0][j],
            A[i][1] + B[1][j] + 1});
}

void update(int i, int l, int r, int p) {
    if (l == r) {
        if (seg[l].fi <= cur && seg[l].se >= cur)
            cnt[i][0][0] = 1;
        else cnt[i][0][0] = 0;
    } else {
        int m = (l + r) / 2;
        if (m >= p) update(i * 2, l, m, p);
        else update(i * 2 + 1, m + 1, r, p);
        merge(cnt[i * 2], cnt[i * 2 + 1], cnt[i],
        (seg[m].fi <= cur && seg[m + 1].se >= cur) ||
        (seg[m].se >= cur && seg[m + 1].fi <= cur));
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, K; cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> B[i];
        if (!pmin[B[i]]) pmin[B[i]] = i;
        pmax[B[i]] = i;
    }
    for (int x = 1; x < MAXN; x++)
        if (pmin[x]) {
            chn.emplace_back(pmin[x], seg.size());
            chn.emplace_back(pmax[x] + 1, seg.size());
            seg.emplace_back(pmin[x], pmax[x]);        
        }
    sort(chn.begin(), chn.end());
    int M = seg.size(), ptr = 0;
    build(1, 0, M - 1);
    for (cur = 1; cur <= N; cur++) {
        while (ptr < 2 * M && chn[ptr].fi <= cur)
            update(1, 0, M - 1, chn[ptr++].se);
        if (cnt[1][0][0] >= K) break;
    }
    if (cur > N) return cout << -1, 0;
    int lef = N + 1, rig = 0, num = 1;
    for (int i = 0; i < M; i++) {
        val[B[seg[i].fi]] = num;
        if (num == K) continue;
        lef = min(lef, seg[i].fi);
        rig = max(rig, seg[i].se);
        if (lef <= cur && rig >= cur) {
            lef = N + 1; rig = 0; num++;    
        }
    }
    for (int i = 1; i <= N; i++)
        cout << val[B[i]] << ' ';
}
