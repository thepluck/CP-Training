#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()
using cd = complex<double>;
using ll = long long;
const double pi = M_PI;
 
void fft(vector <cd> &a, int inverte){
    int n = a.size(); if (n == 1) return;
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
vector <T> mul(const vector <T> &a,const vector <T> &b){
    vector <cd> fa(all(a)), fb(all(b));
    int n = 1;
    while (n < int(a.size() + b.size())) n <<= 1;
    fa.resize(n); fb.resize(n);
    fft(fa, 1); fft(fb, 1);
    for (T i = 0; i < n; i++) fa[i] *= fb[i];
    fft(fa, -1);
    vector <T> res(n);
    for (T i = 0; i < n; i++)
        res[i] = round(fa[i].real());
    return res;
}
 
namespace big_integer{
    typedef vector <ll> bigint;
    typedef const bigint& cb;
    const int base = 1000;
 
    bigint& fix(bigint& a){
        a.push_back(0);
        for (int i = 0; i < (int)a.size() - 1; i++){
            a[i + 1] += a[i] / base; a[i] %= base;
            if (a[i] < 0) a[i] += base, a[i + 1]--;
        }
        while (!a.empty() && a.back() == 0) a.pop_back();
        return a;
    }

    bigint big(int x){
        bigint res;
        while (x > 0){
            res.push_back(x % base);
            x /= base;
        }
        return fix(res), res;
    }

    bigint big(const string& s){
        bigint res(s.size() / 3 + 1);
        for (int i = 0, pos; s[i]; i++){
            pos = (s.size() - i - 1) / 3;
            res[pos] = res[pos] * 10 + s[i] - '0';
        }
        return fix(res), res;
    }
 
    int comp(cb a, cb b){
        if (a.size() != b.size())
            return (int)a.size() - (int)b.size();
        for (int i = (int)a.size() - 1; i >= 0; i--)
            if (a[i] != b[i]) return a[i] - b[i];
        return 0;
    }
 
    istream& operator >> (istream& is, bigint& a){
        string s; is >> s; a = big(s); return is;
    }
 
    ostream& operator << (ostream& os, const bigint& a){
        if (a.empty()) return os << 0;
        os << a.back();
        for (int i = (int)a.size() - 2; i >= 0; i--)
            cout << setw(3) << setfill('0') << a[i];
        return os;
    }
 
    #define def_operator(x) bool operator x (cb a, cb b){return comp(a, b) x 0;}
    def_operator(==)
    def_operator(>)
    def_operator(<)
    def_operator(<=)
    def_operator(>=)
    def_operator(!=)
 
    void operator += (bigint& a, cb b){
        a.resize(max(a.size(), b.size()));
        for (int i = 0; i < (int)b.size(); i++)
            a[i] += b[i];
        fix(a);
    }
 
    bigint operator + (bigint a, cb b){
        a += b; return a;
    }
 
    void operator -= (bigint& a, cb b){
        a.resize(max(a.size(), b.size()));
        for (int i = 0; i < (int)b.size(); i++)
            a[i] -= b[i];
        fix(a);
    }
 
    bigint operator - (bigint a, cb b){
        a -= b; return a;
    }
 
    bigint operator * (cb a, cb b){
        bigint res = mul(a, b);
        return fix(res), res;
    }
 
    void operator *= (bigint& a, cb b){
        a = a * b;
    }
}

using namespace big_integer;
bigint fibo[1000005];
bitset <1000005> used;

bigint calc(int n){
    if (used[n]) return fibo[n]; 
    int k = n / 2; used[n] = true;
    bigint x = calc(k - 1), y = calc(k);
    if (n & 1){
        return fibo[n] = x * y * big(2) + y * y;
    }
    else return fibo[n] = x * x + y * y;
} 
int main(){
    freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
    int n; cin >> n;
    fibo[0] = fibo[1] = big(1);
    used[0] = used[1] = 1;
    cout << calc(n) << '\n';
    cerr << clock() / CLOCKS_PER_SEC << '\n';
} 