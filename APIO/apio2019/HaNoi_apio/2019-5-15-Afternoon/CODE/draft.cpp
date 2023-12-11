#include <iostream>
#include <cstdio>
using namespace std;

const int N = 505;

int n, mod, d, k, a[N];
long long f[N], g[N], h[N];

int main()
{
    scanf("%d%d%d%d", &n, &mod, &d, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    for (int i = -d; i <= d; i++)
        f[(i + n) % n] = g[(i + n) % n] = 1;
    for (int b = 30 - __builtin_clz(k); b >= 0; b--)
    {
        for (int i = 0; i < n; i++)
        {
            h[i] = g[i];
            g[i] = 0;
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                (g[(i + j) % n] += h[i] * h[j]) %= mod;
        if (k >> b & 1)
        {
            for (int i = 0; i < n; i++)
            {
                h[i] = g[i];
                g[i] = 0;
            }
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    (g[(i + j) % n] += h[i] * f[j]) %= mod;
        }
    }
    for (int i = 0; i < n; i++)
    {
        long long ret = 0;
        for (int j = 0; j < n; j++)
            (ret += g[j] * a[(i - j + n) % n]) %= mod;
        printf("%lld ", ret);
    }
}
