#include <bits/stdc++.h>
using namespace std;
#define debug(a) cerr<<#a<<" = "<<(a)<<endl

#define double long double
namespace FFT {
    const int maxf = 1 << 18;
    struct cp {
        double x, y;
        cp(double x = 0, double y = 0) : x(x), y(y) {}
        cp operator + (const cp& rhs) const {
            return cp(x + rhs.x, y + rhs.y);
        }
        cp operator - (const cp& rhs) const {
            return cp(x - rhs.x, y - rhs.y);
        }
        cp operator * (const cp& rhs) const {
            return cp(x * rhs.x - y * rhs.y, x * rhs.y + y * rhs.x);
        }
        cp operator !() const {
            return cp(x, -y);
        }
    } rts[maxf + 1];
    cp fa[maxf], fb[maxf];
    cp fc[maxf], fd[maxf];

    int bitrev[maxf];
    void fftinit() {
        int k = 0; while ((1 << k) < maxf) k++;
        bitrev[0] = 0;
        for (int i = 1; i < maxf; i++) {
            bitrev[i] = bitrev[i >> 1] >> 1 | ((i & 1) << k - 1);
        }
        double PI = acos((double) -1.0);
        rts[0] = rts[maxf] = cp(1, 0);
        for (int i = 1; i + i <= maxf; i++) {
            rts[i] = cp(cos(i * 2 * PI / maxf), sin(i * 2 * PI / maxf));
        }
        for (int i = maxf / 2 + 1; i < maxf; i++) {
            rts[i] = !rts[maxf - i];
        }
    }
    void dft(cp a[], int n, int sign) {
        static int isinit;
        if (!isinit) {
            isinit = 1;
            fftinit();
        }
        int d = 0; while ((1 << d) * n != maxf) d++;
        for (int i = 0; i < n; i++) {
            if (i < (bitrev[i] >> d)) {
                swap(a[i], a[bitrev[i] >> d]);
            }
        }
        for (int len = 2; len <= n; len <<= 1) {
            int delta = maxf / len * sign;
            for (int i = 0; i < n; i += len) {
                cp *x = a + i,*y = a + i + (len >> 1), *w = sign > 0 ? rts : rts + maxf;
                for (int k = 0; k + k < len; k++) {
                    cp z = *y * *w;
                    *y = *x - z, *x = *x + z;
                    x++, y++, w += delta;
                }
            }
        }
        if (sign < 0) {
            for (int i = 0; i < n; i++) {
                a[i].x /= n;
                a[i].y /= n;
            }
        }
    }
    void multiply(int a[], int b[], int na, int nb, int c[], int mod = 1000000007) {
        int n = na + nb - 1;
        while (n != (n & -n)) n += n & -n;
        for (int i = 0; i < n; i++) fa[i] = fb[i] = cp();
        static const int magic = 15;
        for (int i = 0; i < na; i++) fa[i] = cp(a[i] >> magic, a[i] & (1 << magic) - 1);
        for (int i = 0; i < nb; i++) fb[i] = cp(b[i] >> magic, b[i] & (1 << magic) - 1);
        dft(fa, n, 1), dft(fb, n, 1);
        for (int i = 0; i < n; i++) {
            int j = (n - i) % n;
            cp x = fa[i] + !fa[j];
            cp y = fb[i] + !fb[j];
            cp z = !fa[j] - fa[i];
            cp t = !fb[j] - fb[i];
            fc[i] = (x * t + y * z) * cp(0, 0.25);
            fd[i] = x * y * cp(0, 0.25) + z * t * cp(-0.25, 0);
        }
        dft(fc, n, -1), dft(fd, n, -1);
        for (int i = 0; i < na+nb-1; i++) {
            long long u = ((long long) floor(fc[i].x + 0.5)) % mod;
            long long v = ((long long) floor(fd[i].x + 0.5)) % mod;
            long long w = ((long long) floor(fd[i].y + 0.5)) % mod;
            c[i] = ((u << 15) + v + (w << 30)) % mod;
        }
    }
}
#undef double

int power(int a, int n, int mod = 1000000007){
    int ans = 1;
    while (n){
        if (n & 1) ans = (long long)ans * a % mod;
        a = (long long) a * a % mod;
        n >>= 1;
    }
    return ans;
}

const int mod = 1000000007;
typedef long long ll;
int a[1<<18], b[1<<18];

ll oneBound(int s, int L){//start with s, length = L
    //Cal a = (x^2+x+1)^L
    int na = 1;
    a[0] = 1;
    int nb = 3;
    b[0] = 1, b[1] = 1, b[2] = 1;
    for (int m = L; m; m >>= 1){
        if (m & 1){//a *= b
            FFT::multiply(a, b, na, nb, a);
            na += nb - 1;
        }
        if (m == 1) break;
        //b *= b
        FFT::multiply(b, b, nb, nb, b);
        nb += nb - 1;
    }
    ll ans = 0;
    for (int i = 0; i < na; ++i){
        if (i+s-L > 0) ans += a[i];
        if (i+s-L < 0) ans -= a[i];
    }
    return (ans % mod + mod) % mod;
}

int32_t main(int32_t argc,char** argv){
    if (argc>1 && freopen(argv[1],"r",stdin));
    if (argc>2 && freopen(argv[2],"w",stdout));
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n+2);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    vector<int> fac(n + 1);
    fac[0] = 1;
    for (int i = 1; i < fac.size(); ++i) fac[i] = (long long)i * fac[i-1] % mod;
    vector<int> invfac(fac.size());
    invfac.back() = power(fac.back(), mod-2);
    for (int i = invfac.size()-1; i--; ) invfac[i] = (i+1LL) * invfac[i+1] % mod;

    auto binom = [&](int n, int k){//#takes k items from n items
        if (k < 0 || k > n) return 0LL;
        return (long long)fac[n] * invfac[k] % mod * invfac[n-k] % mod;
    };

    auto s2t = [&](int s, int t, int L){//#from s to t in L steps up or down, no touch 0
        if ((L + t + s) % 2) return 0LL;
        return (binom(L, (L + t-s) / 2) - binom(L, (L - t - s) / 2) + mod) % mod;
    };

    ll ans = 1;
    for (int i = 1; i <= n; ++i) if (a[i]){
        int j = i+1;
        while (j <= n && !a[j]) ++j;
        if (j > n) break;
        int s = a[i], t = a[j], L = j-i;
        ll k = 0;
        for (int nZero = 0; nZero <= L; ++nZero){
            ll zero = binom(L, nZero);
            ll nonzero = s2t(s, t, L - nZero);
            k = (k + zero * nonzero) % mod;
        }
        ans = (ans * k) % mod;
        i = j - 1;
    }

    for (int i = 1; i <= n; ++i) if (a[i]){
        ans = (ans * oneBound(a[i], i-1)) % mod;
        break;
    }
    for (int i = n; i >= 1; --i) if (a[i]){
        ans = (ans * oneBound(a[i], n-i)) % mod;
        break;
    }
    cout << ans << endl;
#ifdef GENTEST
    cerr << ans << endl;
#endif
}
