/// longest interval [i, j] such that
/// a[i] = min(a[i], a[i + 1], ..., a[j])
/// a[j] = max(a[i], a[i + 1], ..., a[j])
#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int a[N], id[N], st[N], top, res, n;

int main(){
    freopen("boundseq.inp", "r", stdin);
    freopen("boundseq.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n; top = 0; res = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i]; int cur = i;
        while (top && a[st[top]] <= a[i])
            if (a[id[top--]] <= a[cur])
                cur = id[top + 1];
        res = max(res, i - cur + 1);
        st[++top] = i; id[top] = cur;
    }
    cout << (res < 1 ? -1 : res) << '\n';
}