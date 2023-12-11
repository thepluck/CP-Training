#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const int ninf = 0xc0c0c0c0;
int f[N], g[N], a[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    memset(f, 0xc0, sizeof f);
    memset(g, 0x3f, sizeof g);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 2; i <= n; i++){
        if (a[i] - a[i - 1] < 2000){
            f[i] = f[i - 2] + 1;
            g[i] = g[i - 2] + 1;
            if (i > 2 &&
            a[i - 1] - a[i - 2] < 2000){
                f[i] = max(f[i], f[i - 3]);
                g[i] = min(g[i], g[i - 3]);
            }
        }

    }
}