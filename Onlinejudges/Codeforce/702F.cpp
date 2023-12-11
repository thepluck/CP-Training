#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

const int MAXN = 200005;
const int LOG = 30;
const int INF = 0x3f3f3f3f;

long long lim[LOG][MAXN];
long long sum[LOG][MAXN];
int cnt[LOG][MAXN], jump[MAXN];
pair<int, int> item[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> item[i].second >> item[i].first;
        item[i].first = -item[i].first;
    }
    sort(item, item + N); jump[N] = N;
    for (int i = N - 1; i >= 0; i--)
        if (jump[jump[i + 1]] + i + 1 == jump[i + 1] * 2)
            jump[i] = jump[jump[i + 1]];
        else jump[i] = i + 1;
    for (int k = 0; k < LOG; k++) {
        lim[k][N] = INF;
        for (int i = N - 1; i >= 0; i--) {
            if (item[i].second < (1 << k)) {
                lim[k][i] = INF; cnt[k][i] = 1;
                sum[k][i] = item[i].second;
            } else if (item[i].second < (1 << (k + 1)))
                lim[k][i] = item[i].second;
            else lim[k][i] = INF;
            if (jump[jump[i + 1]] + i + 1 == jump[i + 1] * 2) {
                cmin(lim[k][i], lim[k][i + 1] + sum[k][i]);
                sum[k][i] += sum[k][i + 1];
                cnt[k][i] += cnt[k][i + 1];
                cmin(lim[k][i], lim[k][jump[i + 1]] + sum[k][i]);
                sum[k][i] += sum[k][jump[i + 1]];
                cnt[k][i] += cnt[k][jump[i + 1]];
            }   
        }
    }
    int Q; cin >> Q;
    while (Q--) {
        int bud, ans = 0, i = 0; cin >> bud;
        for (int k = LOG - 1; k >= 0; k--) {
            if (i == N || bud < (1 << k)) continue;
            while (i < N && bud >= (1 << k)) {
                if (bud - sum[k][i] >= (1 << k) && bud < lim[k][i]) {
                    bud -= sum[k][i]; ans += cnt[k][i]; i = jump[i];
                } else if (item[i].second < (1 << k)) {
                    if (bud - item[i].second >= (1 << k)) {
                        bud -= item[i].second; ans++; i++;
                    } else break;
                } else if (bud < item[i].second) i++;
                else break; 
            }
            if (i < N) {
                bud -= item[i++].second; ans++;
            }
        }
        cout << ans << ' ';
    }
}