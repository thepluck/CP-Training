#include <cmath>
#include <iostream>
#include <complex>
#include <vector>
#include <algorithm>
#define all(v) (v).begin(), (v).end()
using namespace std;
 
template <class T, class _T>
bool chkmax(T &a, const _T &b){
    return a < b ? a = b, true : false;
}
 
template <class T, class _T>
bool chkmin(T &a, const _T &b){
    return a > b ? a = b, true : false;
}
 
using cd = complex<double>;
using ll = long long;
const double pi = M_PI;
 
void fft(vector <cd> &a, int inverte){
    int n = a.size();
    if (n == 1) return;
    vector <cd> s(n / 2), t(n / 2);
    for (int i = 0; 2 * i < n; i++)
        s[i] = a[i * 2], t[i] = a[i * 2 + 1];
    fft(s, inverte); fft(t, inverte);
    double ang = 2 * pi / n * inverte;
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++){
        a[i] = s[i] + w * t[i];
        a[i + n / 2] = s[i] - w * t[i];
        if (inverte == -1){
            a[i] /= 2; a[i + n / 2] /= 2;
        }
        w *= wn;
    } 
}   
 
template <typename T>
vector <T> mul(const vector <T> &a, const vector <T> &b){
    vector <cd> fa(all(a)), fb(all(b));
    int n = 1;
    while (n < int(a.size() + b.size())) 
    	n <<= 1;
    fa.resize(n); fb.resize(n);
    fft(fa, 1); fft(fb, 1);
    for (T i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, -1);
    vector <T> res(n);
    for (T i = 0; i < n; i++)
        res[i] = round(fa[i].real());
    while (!res.empty() && res.back() == 0) 
    	res.pop_back();
    return res;
}
 
int main(){
    int max_abs = 0; int n;
    cin >> n; vector <int> a(n), b(n), c(n);
    for (auto &x : a){
        cin >> x; if (x < 0) chkmax(max_abs, -x);
    }
    for (auto &x : b){
        cin >> x; if (x < 0) chkmax(max_abs, -x);
    }
    for (auto &x : c) cin >> x;
    for (auto &x : a) x += max_abs;
    for (auto &x : b) x += max_abs;
    for (auto &x : c) x += 2 * max_abs;
    vector <int> ta((*max_element(all(a))) + 1);
    vector <int> tb((*max_element(all(b))) + 1);
    for (auto x : a) ta[x]++;
    for (auto x : b) tb[x]++;
    auto res = mul(ta, tb);
    ll ans = 0;
    for (auto x : c)
        if (x >= 0) ans += res[x];
    cout << ans << '\n';
} 