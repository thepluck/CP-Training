#include <bits/stdc++.h>
 
using namespace std;
int n;
int a[202][202], x[202][202];
bool OK, l = true;
void xuli()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << x[i][j] << " ";
        cout << "\n";
    }
    OK = true;
}
void thu(int k)
{
    if (k > n) { xuli(); return; }
    for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= 1; j++)
        {
            x[1][k] = i;
            x[k][1] = j;
            for (int p = 2; p <= k - 1; p++)
            {
                x[p][k] = a[p - 1][k - 1] - x[p - 1][k] - x[p - 1][k - 1] - x[p][k - 1];
                if (x[p][k] < 0 || x[p][k] > 1)
                { l = false; break; }
            }
            for (int p = 2; p <= k; p++)
            {
                x[k][p] = a[k - 1][p - 1] - x[k - 1][p] - x[k - 1][p - 1] - x[k][p - 1];
                if (x[k][p] < 0 || x[k][p] > 1)
                { l = false; break; }
            }
            if (l == true) thu(k + 1);
            if (OK) return;
            l = true;
        }
}
int main()
{
    OK = false;
    //freopen("aladdin.inp","r",stdin);
    //freopen("aladdin.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
        for (int j = 1; j <= n - 1; j++)
            cin >> a[i][j];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            x[i][j] = 0;
    x[1][1] = 0;
    thu(2);
    if (!OK)
    {
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                x[i][j] = 0;
        x[1][1] = 1;
        thu(2);
    }
    if (!OK) cout << "No solution";
}