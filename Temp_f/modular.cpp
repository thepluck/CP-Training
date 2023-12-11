#include <bits/stdc++.h>
using namespace std;

class modular{
public:
    using ll = long long; ll val;
    static const int mod = 1e9 + 7;

    modular(): val(0){}

    template <typename T>
    modular(T _val): val(_val % mod){
        if (val < 0) val += mod;
    }

    bool operator != (const modular &o){
        return val != o.val;
    }

    bool operator == (const modular &o){
        return val == o.val;
    }

    friend modular operator + (const modular &a, const modular &b){
        return modular(a.val + b.val);
    }

    friend void operator += (modular &a, const modular &b){
        a = a + b;
    }

    friend modular operator - (const modular &a, const modular &b){
        return modular(a.val - b.val);
    }

    friend void operator -= (modular &a, const modular &b){
        a = a - b;
    }

    friend modular operator * (const modular &a, const modular &b){
        return modular(a.val * b.val);
    }

    friend void operator *= (modular &a, const modular &b){
        a = a * b;
    }

    friend modular pow(const modular &a, const int &k){
        modular res(1), x(a);
        for (int i = k; i > 0; i >>= 1){
            if (i & 1) res *= x; x *= x;
        }
        return res;
    }

    friend modular inverse(const modular &a){
        return pow(a, modular::mod - 2);
    }

    friend modular operator / (const modular &a, const modular &b){
        return a * inverse(b);
    }

    friend void operator /= (modular &a, const modular &b){
        a = a / b;
    }

    friend istream& operator >> (istream &is, modular &a){
        modular::ll x; is >> x; a = modular(x); return is;
    }

    friend ostream& operator << (ostream &os, const modular &a){
        return os << a.val;
    }
};

int main(){

}