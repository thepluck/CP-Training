#include <bits/stdc++.h>
using namespace std;

namespace big_integer{  
    using bigint = vector <int>;
    using cb = const bigint&;
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
            os << setw(3) << setfill('0') << a[i];
        return os;
    }

    istream& operator >> (istream& is, bigint &a){
        string s; is >> s; a = big(s); return is;
    }

    string to_string (const bigint &a){
        if (a.empty()) return "0";
        stringstream ss; ss << a.back();
        for (int i = a.size() - 2; i >= 0; i--)
            ss << setw(3) << setfill('0') << a[i];
        return ss.str();
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

using namespace big_integer;
bigint dp[205][105], pow3[105];
char s[205]; int n, k, order[256];

int main(){
    scanf("%d%d%s", &n, &k, s + 1);
    pow3[0] = dp[0][0] = big(1);
    for (int i = 1; i <= n; i++){
        pow3[i] = pow3[i - 1] * big(3);
        for (int j = 0; j <= k; j++){
            if (j > 0) dp[i][j] = dp[i - 1][j - 1];
            if (j < k) dp[i][j] += dp[i - 1][j + 1];
        }
    }
    order['('] = 1; order[')'] = 4;
    order['['] = 2; order[']'] = 5;
    order['{'] = 3; order['}'] = 6;
    stack <char> cur; bigint res = big(1);
    for (int i = 1, dep = 0; i < n; i++)
        if (order[s[i]] <= 3){
            res += big(order[s[i]] - 1) * dp[n - i][++dep] * pow3[(n - i - dep) / 2];
            if (!cur.empty() && cur.top() < s[i])
                res += dp[n - i][dep - 2] * pow3[(n - i - dep) / 2 + 1];
            cur.push(s[i]);
        }
        else {
            if (dep < k) 
                res += big(order[s[i]] - 3) * dp[n - i][dep + 1] * pow3[(n - i - dep - 1) / 2];
            cur.pop(); dep--;
        }
    cout << res << '\n';
}