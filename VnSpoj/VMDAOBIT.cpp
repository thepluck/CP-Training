#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int, int>
#define PB push_back
#define F first
#define S second
#define N 104
using namespace std;
 
int n, m, a[N][N];
vector<pii> res;
void update(int u, int v)
{
    for (int i = u; i <= u+2; i++)
        for (int j = v; j <= v+2; j++)
            a[i][j] ^= 1;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("INP.TXT", "r", stdin);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
    for (int i = 1; i <= n-2; i++)
        for (int j = 1; j <= m-2; j++)
            if (a[i][j])
            {
                res.PB(mp(i, j));
                update(i, j);
            }
    bool flag = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            flag |= a[i][j];
    if (flag) {cout <<-1; return 0;}
    else
    {
        cout <<res.size()<<endl;
        for (auto z : res)
            cout <<z.F <<" "<<z.S<<'\n';
    }
}
