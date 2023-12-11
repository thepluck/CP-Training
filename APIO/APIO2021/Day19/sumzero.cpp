#include <bits/stdc++.h>

using namespace std;

const int MAXN = 400005;
const int LG = 19;

map <long long, int> idx;
int jump[MAXN][LG];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    int last = -1; long long sum;
    idx[sum = 0] = 0;
    memset(jump, -1, sizeof jump);
    for (int i = 1, x; i <= N; i++) {
        cin >> x; sum += x;
        if (idx.count(sum))
            last = max(last, idx[sum]);
        idx[sum] = i; jump[i][0] = last;
    }
    for (int k = 1; k < LG; k++)
        for (int i = 1; i <= N; i++)
            if (jump[i][k - 1] >= 0)
                jump[i][k] = jump[jump[i][k - 1]][k - 1];
    int Q; cin >> Q;
    while (Q--) {
        int l, r, res = 0; cin >> l >> r; l--;
        for (int k = LG - 1; k >= 0; k--)
            if (jump[r][k] >= l) {
                res += 1 << k; r = jump[r][k];
            }
        cout << res << '\n';
    }    
}