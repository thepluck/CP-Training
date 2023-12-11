#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;

int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
int cnt[20];

namespace big_integer{
    typedef vector <int> bigint;
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

    ostream& operator << (ostream& os, const bigint& a){
        if (a.empty()) return os << 0;
        os << a.back();
        for (int i = a.size() - 2; i >= 0; i--)
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
        bigint res(a.size() + b.size());
        for (int i = 0; i < (int)a.size(); i++)
            for (int j = 0; j < (int)b.size(); j++)
                res[i + j] += a[i] * b[j];
        return fix(res), res;
    }

    void operator *= (bigint& a, cb b){
        a = a * b;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k; vector <int> a(n);
    for (int &x : a) cin >> x; sort(all(a));
    a.resize(unique(all(a)) - a.begin());
    for (int &x : a){
        for (int i = 0; i < 13; i++){
            int cur = 0;
            while (x % prime[i] == 0){
                cur++; x /= prime[i];
            }
            cnt[i] = max(cur, cnt[i]);
        }
    }
    using namespace big_integer;
    bigint ans = big(1);
    for (int i = 0; i < 13; i++){
    	if (cnt[i] == 0) continue;
        cnt[i] = (cnt[i] - 1) / k * k + k;
        for (int j = 0; j < cnt[i] / k; j++)
            ans *= big(prime[i]);
    }
    cout << ans;
}