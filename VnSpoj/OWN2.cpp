#include <bits/stdc++.h>
using namespace std;

template <class T = int>
class big_integer : private basic_string <T> {
private:
    static const int base = 1000; bool sign;

    void fix(){
        this->push_back(0);
        for (int i = 0; i < int(this->size()) - 1; i++){
            this->at(i + 1) += this->at(i) / base;
            this->at(i) %= base;
            if (this->at(i) < 0){
                this->at(i) += base; this->at(i + 1)--;
            }
        }
        while (!this->empty() && this->back() == 0) this->pop_back();
    }

public:
    big_integer(): sign(true){}

    big_integer(int x){
        sign = x < 0 ? x = -x, false : true;
        while (x > 0){
            this->push_back(x % base); x /= base;
        }
        this->fix();
    }

    big_integer(long long x){
        sign = x < 0 ? x = -x, false : true;
        while (x > 0){
            this->push_back(x % base); x /= base;
        }
        this->fix();
    }

    big_integer(const string &s){
        sign = s[0] == '-' ? false : true;
        this->resize(s.size() / 3 + 1);
        for (int i = sign ? 0 : 1, pos; s[i]; i++){
            pos = (s.size() - i - 1) / 3;
            this->at(pos) = this->at(pos) * 10 + s[i] - '0';
        }
        this->fix();
    }
    friend big_integer operator - (const big_integer &a){
        big_integer res = a; res.sign ^= 1; return res;
    }

    friend int comp(const big_integer &a, const big_integer &b){
        if (a.sign != b.sign) return a.sign < b.sign ? -1 : 1;
        if (a.size() != b.size())
            return (a.size() - b.size()) * (a.sign ? 1 : -1);
        for (int i = a.size() - 1; ~i; i--)
            if (a[i] != b[i]) return (a[i] - b[i]) * (a.sign ? 1 : -1);
        return 0;
    }

    friend ostream& operator << (ostream &os, const big_integer &a){
        if (a.empty()) return os << "0";
        if (!a.sign) os << '-'; os << a.back();
        for (int i = a.size() - 2; ~i; i--)
            os << setw(3) << setfill('0') << a[i];
        return os;
    }

    friend istream& operator >> (istream &is, big_integer &a){
        string s; is >> s; a = big_integer(s); return is;
    }

    friend string to_string(const big_integer &a){
        if (a.empty()) return "0"; stringstream ss;
        if (!a.sign) ss << '-'; ss << a.back();
        for (int i = a.size() - 2; ~i; i--)
            ss << setw(3) << setfill('0') << a[i];
        return ss.str();
    }

    friend bool operator < (const big_integer &a, const big_integer &b){
        return comp(a, b) < 0;
    }

    friend bool operator <= (const big_integer &a, const big_integer &b){
        return comp(a, b) <= 0;
    }

    friend bool operator > (const big_integer &a, const big_integer &b){
        return comp(a, b) > 0;
    }
    friend bool operator >= (const big_integer &a, const big_integer &b){
        return comp(a, b) >= 0;
    }

    friend big_integer operator + (const big_integer &a, const big_integer &b){
        if (a.sign && !b.sign) return a - -b;
        if (!a.sign && b.sign) return b - -a;
        big_integer res = a; res.resize(max(a.size(), b.size()));
        for (int i = 0; i < int(b.size()); i++) res[i] += b[i];
        res.fix(); return res;
    }

    friend big_integer operator - (const big_integer &a, const big_integer &b){
        if (a.sign && !b.sign) return a + -b;
        if (!a.sign && b.sign) return -(b + -a);
        if (!a.sign && !b.sign) return -(-a - -b);
        if (a > b){
            big_integer res = a;
            for (int i = 0; i < int(b.size()); i++) res[i] -= b[i];
            res.fix(); return res;
        }
        else {
            big_integer res = b;
            for (int i = 0; i < int(a.size()); i++) res[i] -= a[i];
            res.fix(); res.sign = 0; return res;
        }
    }

    friend big_integer operator * (const big_integer &a, const big_integer &b){
        big_integer res; res.resize(a.size() + b.size());
        for (int i = 0; i < int(a.size()); i++)
            for (int j = 0; j < int(b.size()); j++)
                res[i + j] += a[i] * b[j];
        res.sign = a.sign == b.sign; res.fix(); return res;
    }

    friend void operator += (big_integer &a, const big_integer &b){
        a = a + b;
    }

    friend void operator -= (big_integer &a, const big_integer &b){
        a = a - b;
    }

    friend void operator *= (big_integer &a, const big_integer &b){
        a = a * b;
    }
};

int prime[] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 
                23, 29, 31, 37, 41, 43, 47, 
                53, 59, 61, 67, 71, 73, 79, 
                83, 89, 97, 101, 103, 107, 
                109, 113, 127, 131, 137, 139, 
                149, 151, 157, 163, 167, 173, 
                179, 181, 191, 193, 197, 199, 
                211, 223, 227, 229, 233, 239, 
                241, 251, 257, 263, 269, 271, 
                277, 281, 283, 293, 307, 311, 
                313, 317, 331, 337, 347, 349, 
                353, 359, 367, 373, 379, 383, 
                389, 397, 401, 409, 419, 421, 
                431, 433, 439, 443, 449, 457, 
                461, 463, 467, 479, 487, 491, 
                499, 503, 509, 521, 523, 541, 
                547, 557, 563, 569, 571, 577, 
                587, 593, 599, 601, 607, 613, 
                617, 619, 631, 641, 643, 647, 
                653, 659, 661, 673, 677, 683, 
                691, 701, 709, 719, 727, 733, 
                739, 743, 751, 757, 761, 769, 
                773, 787, 797, 809, 811, 821, 
                823, 827, 829, 839, 853, 857, 
                859, 863, 877, 881, 883, 887, 
                907, 911, 919, 929, 937, 941, 
                947, 953, 967, 971, 977, 983, 
                991, 997, 1009, 1013, 1019, 
                1021, 1031, 1033, 1039, 1049, 
                1051, 1061, 1063, 1069, 1087, 
                1091, 1093, 1097, 1103, 1109, 
                1117, 1123, 1129, 1151, 1153, 
                1163, 1171, 1181, 1187, 1193, 
                1201, 1213, 1217, 1223, 1229, 
                1231, 1237, 1249, 1259, 1277, 
                1279, 1283, 1289, 1291, 1297, 
                1301, 1303, 1307, 1319, 1321, 
                1327, 1361, 1367, 1373, 1381, 
                1399, 1409, 1423, 1427, 1429, 
                1433, 1439, 1447, 1451, 1453, 
                1459, 1471, 1481, 1483, 1487, 
                1489, 1493, 1499, 1511, 1523, 
                1531, 1543, 1549, 1553, 1559, 
                1567, 1571, 1579, 1583, 1597, 
                1601, 1607, 1609, 1613, 1619, 
                1621, 1627, 1637, 1657, 1663, 
                1667, 1669, 1693, 1697, 1699, 
                1709, 1721, 1723, 1733, 1741, 
                1747, 1753, 1759, 1777, 1783, 
                1787, 1789, 1801, 1811, 1823, 
                1831, 1847, 1861, 1867, 1871, 
                1873, 1877, 1879, 1889, 1901, 
                1907, 1913, 1931, 1933, 1949, 
                1951, 1973, 1979, 1987, 1993, 
                1997, 1999, 2003, 2011, 2017, 
                2027, 2029, 2039, 2053, 2063, 
                2069, 2081, 2083, 2087, 2089, 
                2099, 2111, 2113, 2129, 2131, 
                2137, 2141, 2143, 2153, 2161, 
                2179, 2203, 2207, 2213, 2221, 
                2237, 2239, 2243, 2251, 2267, 
                2269, 2273, 2281, 2287, 2293, 
                2297, 2309, 2311, 2333, 2339, 
                2341, 2347, 2351, 2357, 2371, 
                2377, 2381, 2383, 2389, 2393, 
                2399, 2411, 2417, 2423, 2437, 
                2441, 2447, 2459, 2467, 2473, 
                2477, 2503, 2521, 2531, 2539, 
                2543, 2549, 2551, 2557, 2579, 
                2591, 2593, 2609, 2617, 2621, 
                2633, 2647, 2657, 2659, 2663, 
                2671, 2677, 2683, 2687, 2689, 
                2693, 2699, 2707, 2711, 2713, 
                2719, 2729, 2731, 2741, 2749, 
                2753, 2767, 2777, 2789, 2791, 
                2797, 2801, 2803, 2819, 2833, 
                2837, 2843, 2851, 2857, 2861, 
                2879, 2887, 2897, 2903, 2909, 
                2917, 2927, 2939, 2953, 2957, 
                2963, 2969, 2971, 2999, 3001, 
                3011, 3019, 3023, 3037, 3041, 
                3049, 3061, 3067, 3079, 3083, 
                3089, 3109, 3119, 3121, 3137, 
                3163, 3167, 3169, 3181, 3187, 
                3191, 3203, 3209, 3217, 3221, 
                3229, 3251, 3253, 3257, 3259, 
                3271, 3299, 3301, 3307, 3313, 
                3319, 3323, 3329, 3331, 3343, 
                3347, 3359, 3361, 3371, 3373, 
                3389, 3391, 3407, 3413, 3433, 
                3449, 3457, 3461, 3463, 3467, 
                3469, 3491, 3499};

big_integer <int> dp[3505][500];

void pre_calc(){
    for (int j = 0; j <= 489; j++) dp[0][j] = 1;
    for (int i = 1; i <= 3500; i++){
        dp[i][0] = 1;
        for (int j = 1; j <= 489; j++){
            dp[i][j] = dp[i][j - 1];
            for (int power = 1; power <= i; power *= prime[j])
                dp[i][j] = max(dp[i][j], dp[i - power][j - 1] * power);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    pre_calc(); int t, n; cin >> t;
    while (t--){
        cin >> n; cout << dp[n][489] << '\n';
    }
}