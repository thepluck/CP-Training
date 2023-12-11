#include <bits/stdc++.h>

using namespace std;

struct segment {
    int l, r, idx;
    
    bool operator < (const segment &o) const {
        return r < o.r;
    }
};

const int MAXN = 200005;
const int INF = 0x3f3f3f3f;
const int LG = 18;

segment S[MAXN];
int jump[MAXN][LG], ord[MAXN];
int nxt[MAXN];

int calc(int i, int j) {
    if (S[i].r >= S[j].l) return -INF;
    int ans = 0;
    for (int k = LG - 1; k >= 0; k--)
        if (S[jump[i][k]].r < S[j].l) {
            ans += 1 << k; i = nxt[jump[i][k]];
        }
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> S[i].l >> S[i].r;
        S[i].idx = i;
    }
    S[N + 1] = {INF, INF, N + 1};
    sort(S + 1, S + N + 1);
    for (int i = 1; i <= N; i++)
        ord[S[i].idx] = i;
    for (int i = 0, j = 0; i <= N; i++) {
        while (S[j].l <= S[i].r) j++;
        nxt[i] = j;
    }
    nxt[N + 1] = N + 1;
    for (int i = 0; i <= N + 1; i++)
        jump[i][0] = i;
    for (int k = 1; k < LG; k++)
        for (int i = 0; i <= N + 1; i++)
            jump[i][k] = jump[nxt[jump[i][k - 1]]][k - 1];
    cout << calc(0, N + 1) - 1 << '\n';
    set <int> cur({0, N + 1});
    for (int i = 1; i <= N; i++) {
        auto it = cur.upper_bound(ord[i]);
        if (calc(*prev(it), ord[i]) + calc(ord[i], *it)
        == calc(*prev(it), *it)) {
            cout << i << ' '; cur.insert(ord[i]);
            
        }
    }
}